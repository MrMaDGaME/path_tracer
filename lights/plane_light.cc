#include "plane_light.hh"

PlaneLight::PlaneLight(const Vector3 &position, const Vector3 &normal, const Color &color) : Light(color),
                                                                                             position(position),
                                                                                             normal(normal.normalize()) {}

float PlaneLight::raycast_hit(Vector3 point, Vector3 direction) {
    if (direction * normal >= -1 - EPSILON && direction * normal <= -1 + EPSILON) {
        float d = -normal._x * position._x - normal._y * position._y - normal._z * position._z;
        return plane_raycast_hit(point, direction, normal._x, normal._y, normal._z, d);
    }
    return -1;
}
