#include "PlaneLight.h"

[[maybe_unused]] PlaneLight::PlaneLight(const Vector3 &position, const Vector3 &normal, const Color &color) : Light(
        color), Plane(position, normal) {}

[[maybe_unused]] PlaneLight::PlaneLight(float a, float b, float c, float d, const Color &color) : Light(color),
                                                                                                  Plane(a, b, c, d) {
}

float PlaneLight::getLightRayCastHit(Vector3 point, Vector3 direction) {
    return Plane::GetRayCastHit(point, direction);
}
