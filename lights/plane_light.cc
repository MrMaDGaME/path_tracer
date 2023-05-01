#include "plane_light.hh"

PlaneLight::PlaneLight(const Color &color, const Vector3 &position, const Vector3 &normal) : Light(color),
                                                                                             position(position),
                                                                                             normal(normal) {}

const Vector3 &PlaneLight::getPosition() const {
    return position;
}

const Vector3 &PlaneLight::getNormal() const {
    return normal;
}

float PlaneLight::raycast_hit(Vector3 point, Vector3 direction) {
    float d = -normal._x * position._x - normal._y * position._y - normal._z * position._z;
    return plane_raycast_hit(point, direction, normal._x, normal._y, normal._z, d);
}
