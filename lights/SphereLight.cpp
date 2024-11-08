#include "SphereLight.h"

SphereLight::SphereLight(const Vector3 &position, float radius, const Color &color)
        : Light(color), Sphere(position, radius) {}

float SphereLight::getLightRayCastHit(Vector3 point, Vector3 direction) {
    return getRayCastHit(point, direction);
}
