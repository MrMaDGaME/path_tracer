#include "plane.hh"

[[maybe_unused]] Plane::Plane(float a, float b, float c, float d, TextureMaterial *texture) : Object(texture), a(a),
                                                                                              b(b), c(c), d(d) {}

[[maybe_unused]] Plane::Plane(Vector3 point, Vector3 normal, TextureMaterial *texture) : Object(texture) {
    normal = normal.normalize();
    a = normal._x;
    b = normal._y;
    c = normal._z;
    d = -normal._x * point._x - normal._y * point._y - normal._z * point._z;
}

float Plane::raycast_hit(Vector3 point, Vector3 direction) {
    return plane_raycast_hit(point, direction, a, b, c, d);
}

Vector3 Plane::get_normal(Vector3 point) {
    return {a, b, c};
}

TextureMaterial::Texture *Plane::get_texture(Vector3 point) {
    return texture->get_texture(point._x, point._y, point._z);
}

float plane_raycast_hit(Vector3 point, Vector3 direction, float a, float b, float c, float d) {
    return (-d - a * point._x - b * point._y - c * point._z) / (a * direction._x + b * direction._y
                                                                + c * direction._z);
}
