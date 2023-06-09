#include "sphere_light.hh"

SphereLight::SphereLight(const Vector3 &position, const Color &color, float radius) : Light(color), position(position),
                                                                                      radius(radius) {}

float SphereLight::raycast_hit(Vector3 point, Vector3 direction) {
    return sphere_raycast_hit(point, direction, position, radius);
}
