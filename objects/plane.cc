#include "plane.hh"

Plane::Plane(float a, float b, float c, float d, Texture_Material *texture) : Object(texture), a(a),
                                                                              b(b), c(c), d(d) {}

float Plane::raycast_hit(Vector3 point, Vector3 direction) {
    return plane_raycast_hit(point, direction, a, b, c, d);
}

Vector3 Plane::get_normal(Vector3 point) {
    return Vector3(a, b, c).normalize();
}

Texture_Material::Texture Plane::get_texture(Vector3 point) {
    return texture->get_texture(point._x, point._y, point._z);
}

float plane_raycast_hit(Vector3 point, Vector3 direction, float a, float b, float c, float d) {
    return (-d - a * point._x - b * point._y - c * point._z) / (a * direction._x + b * direction._y
                                                                + c * direction._z);
}
