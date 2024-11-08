// RayTracer.cc
#include "RayTracer.h"
#include <algorithm>
#include <stdexcept>

RayTracer::RayTracer(ObjectManager &objectManager, LightManager &lightManager) : objectManager(objectManager),
                                                                                 lightManager(lightManager) {}

Vector3
RayTracer::getDirectHit(const Vector3 &point, const Vector3 &direction, Object *&currentObj, Light *&currentLight) {
    Object *tmpObj = nullptr;
    Light *tmpLight = nullptr;
    float objectMinT = -1.0f;
    float lightMinT = -1.0f;

    // Iterate through objects to find nearest intersection
    for (Object *object: objectManager.getObjects()) {
        float t = object->raycast_hit(point, direction);
        if (t > 0 && (t < objectMinT || objectMinT < 0)) {
            objectMinT = t;
            tmpObj = object;
        }
    }

    // Iterate through lights to find nearest intersection
    for (Light *light: lightManager.getLights()) {
        float t = light->raycast_hit(point, direction);
        if (t > 0 && (t < lightMinT || lightMinT < 0)) {
            lightMinT = t;
            tmpLight = light;
        }
    }

    // Determine the closest hit point (object or light)
    if (objectMinT > 0 && (objectMinT < lightMinT || lightMinT <= 0)) {
        currentObj = tmpObj;
        return point + direction * objectMinT;
    }
    if (lightMinT > 0 && (lightMinT < objectMinT || objectMinT <= 0)) {
        currentLight = tmpLight;
        return point + direction * lightMinT;
    }

    throw std::logic_error("No object or light found");
}

Color RayTracer::getPixelColor(const Vector3 &pixel, const Vector3 &direction, const Color &totalFilter,
                               float currentRefractiveIndex) {
    if (totalFilter < Color(0.5, 0.5, 0.5))  // Limit recursion depth by color filter
        return {0, 0, 0};

    Object *currentObj = nullptr;
    Light *currentLight = nullptr;

    try {
        Vector3 hitPoint = getDirectHit(pixel, direction, currentObj, currentLight);

        if (currentLight) {
            return currentLight->getColor();
        } else if (currentObj) {
            Vector3 normal = currentObj->get_normal(hitPoint);
            if (normal * direction > 0)  // Ensure normal points towards camera
                normal = -normal;

            // Compute color based on object material properties
            TextureMaterial::Texture *texture = currentObj->get_texture(hitPoint);
            Vector3 lightDirection = getLightDirection(direction, normal, texture);
            float attenuation = 1.0f;  // Placeholder for attenuation logic
            Color filter = (texture->color / 255.0f) * attenuation *
                           (texture->kd * std::max(0.0f, normal * lightDirection) + texture->ks * std::pow(
                                   std::max(0.0f, direction.get_reflection(normal) * lightDirection), texture->ns));

            // Recursive call for light tracing
            Color incomingLight = getPixelColor(hitPoint, lightDirection, totalFilter * filter, currentRefractiveIndex);
            return (incomingLight * filter);
        }
    } catch (std::logic_error &e) {
        return {0, 0, 0};
    }
    return {0, 0, 0};  // Default case for no intersections
}

Vector3 RayTracer::getLightDirection(const Vector3 &previousDirection, const Vector3 &normal,
                                     TextureMaterial::Texture *texture) {
    if (texture->material == Material::MIRROR) {
        return previousDirection.get_reflection(normal).normalize();
    }

    // Generate a random light direction for diffuse materials
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1, 1);
    Vector3 lightDirection(static_cast<float>(dis(gen)), static_cast<float>(dis(gen)), static_cast<float>(dis(gen)));
    return (lightDirection * normal < 0) ? -lightDirection : lightDirection;
}
