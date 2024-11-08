#include "Vector3.h"

Vector3::Vector3(float x, float y, float z) : x_(x), y_(y), z_(z) {}

Vector3::Vector3() : x_(0), y_(0), z_(0) {}

Vector3 Vector3::operator*(const float &l) const {
    return {x_ * l, y_ * l, z_ * l};
}

Vector3 Vector3::operator-(const Vector3 &v) const {
    return {x_ - v.x_, y_ - v.y_, z_ - v.z_};
}

Vector3 Vector3::operator-() const {
    return {-x_, -y_, -z_};
}

Vector3 Vector3::operator+(const Vector3 &v) const {
    return {x_ + v.x_, y_ + v.y_, z_ + v.z_};
}

std::ostream &operator<<(std::ostream &os, const Vector3 &vector3) {
    os << "x_: " << vector3.x_ << " y_: " << vector3.y_ << " z_: " << vector3.z_;
    return os;
}

float Vector3::operator*(const Vector3 &v) const {
    return x_ * v.x_ + y_ * v.y_ + z_ * v.z_;
}

Vector3 Vector3::normalize() const {
    return *this * (float) (1.0 / sqrt(x_ * x_ + y_ * y_ + z_ * z_));
}

Vector3 Vector3::get_reflection(const Vector3 &normal) const {
    return *this - normal * (2 * (*this * normal));
}

float Vector3::norm() const {
    return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

Vector3 Vector3::cross(const Vector3 &v) const {
    return {y_ * v.z_ - z_ * v.y_, z_ * v.x_ - x_ * v.z_, x_ * v.y_ - y_ * v.x_};
}
