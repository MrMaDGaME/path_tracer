#include "Plane.h"

#include <utility>

float Plane::GetRayCastHit(Vector3 point, Vector3 direction) const {
    return (-d_ - a_ * point.x_ - b_ * point.y_ - c_ * point.z_) /
           (a_ * direction.x_ + b_ * direction.y_ + c_ * direction.z_);
}

Vector3 Plane::getNormal() const {
    return {a_, b_, c_};
}

Plane::Plane(float a, float b, float c, float d) : a_(a), b_(b), c_(c), d_(d) {
}

Plane::Plane(Vector3 point, Vector3 normal) {
    normal = normal.normalize();
    a_ = normal.x_;
    b_ = normal.y_;
    c_ = normal.z_;
    d_ = -normal.x_ * point.x_ - normal.y_ * point.y_ - normal.z_ * point.z_;
}

Plane::~Plane() = default;
