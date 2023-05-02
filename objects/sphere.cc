#include "sphere.hh"
#include <cmath>

Sphere::Sphere(const Vector3 &center, float radius, Texture_Material *texture) : Object(texture),
                                                                                 center(center),
                                                                                 radius(radius) {}

float square(float x) {
    return x * x;
}

float Sphere::raycast_hit(Vector3 point, Vector3 direction) {
    return sphere_raycast_hit(point, direction, center, radius);
}

Vector3 Sphere::get_normal(Vector3 point) {
    return (point - center).normalize();
}

Texture_Material::Texture Sphere::get_texture(Vector3 point) {
    return texture->get_texture(point._x, point._y, point._z);
}

float sphere_raycast_hit(Vector3 point, Vector3 direction, Vector3 center, float radius) {
    float a = square(direction._x) + square(direction._y) + square(direction._z);
    float b = 2 * (direction._x * (point._x - center._x) + direction._y * (point._y - center._y) +
                   direction._z * (point._z - center._z));
    float c = square(point._x - center._x) + square(point._y - center._y) +
              square(point._z - center._z) - square(radius);
    float delta = square(b) - 4 * a * c;
    if (delta < 0.0f)
        return -1;
    if (delta == 0)
        return -b / (2 * a);
    float t1 = (-b - sqrt(delta)) / (2 * a);
    float t2 = (-b + sqrt(delta)) / (2 * a);
    return (t1 <= t2 && t1 > 0) ? t1 : t2;
}
