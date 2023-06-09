#include "scene.hh"

#define EPSILON 0.0001f

Scene::Scene(Camera *camera) : camera(camera) {}

Scene::Scene(Camera *camera, const Color &ambientColor) : camera(camera), ambient_color(ambientColor) {}

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

void Scene::addLight(Light *light) {
    lights.push_back(light);
}

Vector3 Scene::get_direct_hit(Vector3 point, Vector3 direction, Object *&current_obj, Light *&current_light) {
    Object *tmp_obj = nullptr;
    Light *tmp_light = nullptr;
    float object_min_t = get_object_hit(point, direction, tmp_obj);
    float light_min_t = get_light_hit(point, direction, tmp_light);
    if (object_min_t > 0 && (object_min_t < light_min_t || light_min_t <= 0)) {
        current_obj = tmp_obj;
        return point + direction * (object_min_t - EPSILON);
    }
    if (light_min_t > 0 && (light_min_t < object_min_t || object_min_t <= 0)) {
        current_light = tmp_light;
        return point + direction * (light_min_t - EPSILON);
    }
    throw std::logic_error("No object or light found");
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

Color Scene::get_pixel_color(Vector3 pixel, Vector3 direction, Color total_filter, float curret_refractive_index) {
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
            Vector3 normal = current_obj->get_normal(hit_point);
            // If the normal is not pointing towards the camera, flip it
            if (normal * direction > 0)
                normal = -normal;
            // Get the texture of the object
            TextureMaterial::Texture *texture = current_obj->get_texture(hit_point);
            if (texture == nullptr) {
                throw std::logic_error("Texture is null");
            }
            // Get the light direction
            Vector3 light_direction = get_light_direction(direction, normal, texture);
            float distance = (pixel - hit_point).norm();
            // constant factors for attenuation
            Vector3 k = {0.25, 0.01, 0.001};
            // compute attenuation factor based on distance
//            float attenuation = 1.0f / (k._x + k._y * distance + k._z * distance * distance);
            float attenuation = 1.0f;
            // Compute the filter of the incoming light
            Color filter = (texture->color / 255.0f) * attenuation *
                           (texture->kd * std::max((normal * light_direction), 0.0f) +
                            texture->ks *
                            (pow(std::max(direction.get_reflection(normal).normalize() *
                                          light_direction, 0.0f),
                                 texture->ns)));
            // Get the incoming light
            Color incoming_light = get_pixel_color(hit_point, light_direction, total_filter * filter,
                                                   curret_refractive_index);
            // Render the object color
            Color pixel_color = (incoming_light + ambient_color) * filter;
            return pixel_color;
        }
    } catch (std::logic_error &e) {
        return {0, 0, 0};
    }
}

Vector3 Scene::get_light_direction(Vector3 previous_direction, Vector3 normal, TextureMaterial::Texture *texture) {
    if (texture->material == Material::MIRROR) {
        // Mirror reflection
        return previous_direction.get_reflection(normal).normalize();
    }
    // Random
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1, 1);
    Vector3 light_direction = Vector3(static_cast<float>(dis(gen)), static_cast<float>(dis(gen)),
                                      static_cast<float>(dis(gen))).normalize();
    // If the light is not pointing towards the normal, flip it
    return light_direction * normal < 0 ? -light_direction : light_direction;
}
