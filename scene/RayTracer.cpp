#include "RayTracer.h"
#include <stdexcept>

#define EPSILON 0.0001f

RayTracer::RayTracer(ObjectManager &objectManager, LightManager &lightManager)
        : objectManager(objectManager), lightManager(lightManager) {}

Vector3 RayTracer::getDirectHit(const Vector3 &point,
                                const Vector3 &direction,
                                std::shared_ptr<Object> &currentObj,
                                std::shared_ptr<Light> &currentLight) {
    std::shared_ptr<Object> tmpObj = nullptr;
    std::shared_ptr<Light> tmpLight = nullptr;
    float objectMinT = -1.0f;
    float lightMinT = -1.0f;

    // Iterate through objects to find nearest intersection
    for (const auto &object: objectManager.getObjects()) {
        float t = object->getObjectRayCastHit(point, direction);
        if (t > 0 && (t < objectMinT || objectMinT < 0)) {
            objectMinT = t;
            tmpObj = object;
        }
    }

    // Iterate through lights to find nearest intersection
    for (const auto &light: lightManager.getLights()) {
        float t = light->getLightRayCastHit(point, direction);
        if (t > 0 && (t < lightMinT || lightMinT < 0)) {
            lightMinT = t;
            tmpLight = light;
        }
    }

    // Determine the closest hit point (object or light)
    if (objectMinT > 0 && (objectMinT < lightMinT || lightMinT <= 0)) {
        currentObj = tmpObj;
        return point + direction * (objectMinT - EPSILON);
    }
    if (lightMinT > 0 && (lightMinT < objectMinT || objectMinT <= 0)) {
        currentLight = tmpLight;
        return point + direction * (lightMinT - EPSILON);
    }

    throw std::logic_error("No object or light found");
}

Color RayTracer::getPixelColor(const Vector3 &pixel, const Vector3 &direction, const Color &totalFilter) {
    if (totalFilter < Color(0.5, 0.5, 0.5))  // Limit recursion depth by color_ filter
        return {0, 0, 0};

    std::shared_ptr<Object> currentObj = nullptr;
    std::shared_ptr<Light> currentLight = nullptr;

    try {
        Vector3 hitPoint = getDirectHit(pixel, direction, currentObj, currentLight);

        if (currentLight) {
            return currentLight->getColor();
        } else if (currentObj) {
            Vector3 normal = currentObj->getNormal(hitPoint);
            if (normal * direction > 0)  // Ensure normal points towards camera
                normal = -normal;

            Vector3 lightDirection;
            Color filter;

            // Compute lightDirection and filter
            currentObj->getMaterial()->reflect(hitPoint, direction, normal, lightDirection, filter);
            // Recursive call for light tracing
            Color incomingLight = getPixelColor(hitPoint, lightDirection, totalFilter * filter);
            return (incomingLight * filter);
        }
    } catch (std::logic_error &e) {
        return {0, 0, 0};
    }
    return {0, 0, 0};  // Default case for no intersections
}
