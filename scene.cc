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

Vector3 Scene::get_direct_hit(Vector3 point, Vector3 direction, Object *&current_obj, Light *&current_light) {
    Object *tmp_obj = nullptr;
    Light *tmp_light = nullptr;
    float object_min_t = get_object_hit(point, direction, tmp_obj);
    float light_min_t = get_light_hit(point, direction, tmp_light);
    if (object_min_t < light_min_t || (object_min_t > 0 && light_min_t <= 0)) {
        current_obj = tmp_obj;
        return point + direction * (object_min_t - EPSILON);
    }
    if (light_min_t < object_min_t || (light_min_t > 0 && object_min_t <= 0)) {
        current_light = tmp_light;
        return point + direction * (light_min_t - EPSILON);
    }
    throw std::runtime_error("No object or light found");
}

float Scene::get_object_hit(Vector3 point, Vector3 direction, Object *&current_obj) {
    float min_t = -1;
    Object *min_obj = nullptr;
    for (Object *object: objects) {
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

float Scene::get_light_hit(Vector3 point, Vector3 direction, Light *&current_light) {
    float min_t = -1;
    Light *min_light = nullptr;
    for (auto light: lights) {
        float t = light->raycast_hit(point, direction);
        if (t > 0 && (t < min_t || min_t == -1)) {
            min_t = t;
            min_light = light;
        }
    }
    if (min_t > 0) {
        current_light = min_light;
        return min_t;
    }
    return -1;
}

Color Scene::get_pixel_color(Vector3 pixel, Vector3 direction, Color total_filter) {
    // If the ray has bounced too many times, no more light is gathered.
    if (total_filter < Color(0.5, 0.5, 0.5))
        return {0, 0, 0};
    Object *current_obj = nullptr;
    Light *current_light = nullptr;
    try {
        Vector3 hit_point = get_direct_hit(pixel, direction, current_obj, current_light);
        if (current_light == nullptr && current_obj == nullptr) {
        }
        if (current_light != nullptr) {
            return current_light->getColor();
        } else {
            // Random light_direction
            Vector3 normal = current_obj->get_normal(hit_point);
            if (normal * direction > 0)
                normal = -normal;
            Vector3 light_direction = direction.get_reflection(normal).normalize();
            // Compute the filter of the incoming light
            Texture_Material::Texture texture = current_obj->get_texture(hit_point);
            Color filter = (texture.color / 255.0f) * (texture.kd * std::max((normal * light_direction), 0.0f) +
                                                       texture.ks *
                                                       (pow(std::max(direction.get_reflection(normal).normalize() *
                                                                     light_direction, 0.0f),
                                                            texture.ns)));
            // Get the incoming light
            Color incoming_light = get_pixel_color(hit_point, light_direction, total_filter * filter);
            // Render the object color
            Color pixel_color = incoming_light * filter;
            return pixel_color;
        }
    } catch (std::runtime_error &e) {
        return {0, 0, 0};
    }
}
