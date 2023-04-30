#include "scene.hh"

#define EPSILON 0.0001f

Scene::Scene(Camera *camera) : camera(camera) {}

void Scene::addObject(Object *object) {
    objects.push_back(object);
}

Scene::~Scene() {
    for (auto object: objects) {
        delete object;
    }
    for (auto light: lights) {
        delete light;
    }
    delete camera;
}

void Scene::addLight(SphereLight *light) {
    lights.push_back(light);
}

float Scene::get_hit(Vector3 point, Vector3 direction, Object *&current_obj) {
    float min_t = -1;
    Object *min_obj = nullptr;
    for (auto object: objects) {
        float t = object->raycast_hit(point, direction);
        if (t > 0 && (t < min_t || min_t == -1)) {
            min_t = t;
            min_obj = object;
        }
    }
    if (min_t > 0) {
        current_obj = min_obj;
        return min_t;
    }
    return -1;
}

Color Scene::getLight(Vector3 point, SphereLight *light) {
    Color result = light->getColor();
    for (auto object: objects) {
        float t = object->raycast_hit(point, light->getPosition() - point);
        if (t > 0 && t < 1) {
            if (object->get_texture(point + (light->getPosition() - point) * t).is_opaque) {
                return {0, 0, 0};
            }
            result._r *= object->get_texture(point).color._r / 255;
            result._g *= object->get_texture(point).color._g / 255;
            result._b *= object->get_texture(point).color._b / 255;
        }
    }
    return result;
}

Vector3 Scene::get_direct_hit(Vector3 point, Vector3 direction, Object *&current_obj) {
    float min_t = get_hit(point, direction, current_obj);
    if (min_t > 0) {
        return point + direction * (min_t - EPSILON);
    }
    throw std::runtime_error("No object found");
}

Color Scene::get_pixel_color(Vector3 pixel, Vector3 direction, int max_depth) {
    if (max_depth <= -1)
        return {0, 0, 0};
    Object *current_obj = nullptr;
    Color pixel_color;
    try {
        Vector3 hit_point = get_direct_hit(pixel, direction, current_obj);
        Texture_Material::Texture texture = current_obj->get_texture(hit_point);
        Color total_light;
        for (auto light: lights) {
            Vector3 normal = current_obj->get_normal(hit_point).normalize();
            if (normal * direction > 0)
                normal = -normal;
            Vector3 light_direction = (light->getPosition() - hit_point).normalize();
            Vector3 reflection = direction.get_reflection(normal).normalize();
            total_light += get_pixel_color(hit_point, reflection, max_depth - 1) * texture.shine +
                           getLight(hit_point, light) * (texture.kd * (normal * light_direction) +
                                                         texture.ks *
                                                         (pow(reflection * light_direction,
                                                              texture.ns)));
        }
        pixel_color._r = texture.color._r / 255.0f * total_light._r;
        pixel_color._g = texture.color._g / 255.0f * total_light._g;
        pixel_color._b = texture.color._b / 255.0f * total_light._b;
    } catch (std::runtime_error &e) {
        return {0, 0, 0};
    }
    return pixel_color;
}
