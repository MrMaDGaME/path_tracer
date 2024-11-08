#include "Sphere.h"
#include <cmath>
#include <utility>

float square(float x) {
    return x * x;
}

float Sphere::getRayCastHit(Vector3 point, Vector3 direction) {
    float a = square(direction.x_) + square(direction.y_) + square(direction.z_);
    float b = 2 *
              (direction.x_ * (point.x_ - center.x_) +
               direction.y_ * (point.y_ - center.y_) +
               direction.z_ * (point.z_ - center.z_));
    float c = square(point.x_ - center.x_) +
              square(point.y_ - center.y_) +
              square(point.z_ - center.z_) -
              square(radius);
    float delta = square(b) - 4 * a * c;
    if (delta < 0.0f)
        return -1;
    if (delta == 0)
        return -b / (2 * a);
    float t1 = (-b - sqrt(delta)) / (2 * a);
    float t2 = (-b + sqrt(delta)) / (2 * a);
    return (t1 <= t2 && t1 > 0) ? t1 : t2;
}

Vector3 Sphere::getNormal(Vector3 point) {
    return (point - center).normalize();
}

Sphere::Sphere(const Vector3 &center, float radius) : center(center), radius(radius) {
}
