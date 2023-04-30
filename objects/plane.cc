#include "plane.hh"

Plane::Plane(float a, float b, float c, float d, Texture_Material *texture) : Object(texture), a(a),
                                                                              b(b), c(c), d(d) {}

float Plane::raycast_hit(Vector3 point, Vector3 direction) {
    return (-d - a * point._x - b * point._y - c * point._z) / (a * direction._x + b * direction._y
                                                                + c * direction._z);
}

Vector3 Plane::get_normal(Vector3 point) {
    return {a, b, c};
}

Texture_Material::Texture Plane::get_texture(Vector3 point) {
    return texture->get_texture(point._x, point._y, point._z);
}
