#include "PlaneLight.h"

[[maybe_unused]] PlaneLight::PlaneLight(const Vector3 &position, const Vector3 &normal, const Color &color) : Light(
        color), Plane(position, normal) {}

float PlaneLight::getLightRayCastHit(Vector3 point, Vector3 direction) {
    return Plane::GetRayCastHit(point, direction);
}
