#include "vector_3.hh"

Vector3::Vector3(float x, float y, float z) : _x(x), _y(y), _z(z) {}

Vector3::Vector3() : _x(0), _y(0), _z(0) {}

Vector3 Vector3::operator*(const float &l) const {
    return {_x * l, _y * l, _z * l};
}

Vector3 Vector3::operator-(const Vector3 &v) const {
    return {_x - v._x, _y - v._y, _z - v._z};
}

Vector3 Vector3::operator-() const {
    return {-_x, -_y, -_z};
}

Vector3 Vector3::operator+(const Vector3 &v) const {
    return {_x + v._x, _y + v._y, _z + v._z};
}

std::ostream &operator<<(std::ostream &os, const Vector3 &vector3) {
    os << "_x: " << vector3._x << " _y: " << vector3._y << " _z: " << vector3._z;
    return os;
}

float Vector3::operator*(const Vector3 &v) const {
    return _x * v._x + _y * v._y + _z * v._z;
}

Vector3 Vector3::normalize() const {
    return *this * (float) (1.0 / sqrt(_x * _x + _y * _y + _z * _z));
}

Vector3 Vector3::get_reflection(const Vector3 &normal) const {
    return *this - normal * (2 * (*this * normal));
}

float Vector3::norm() const {
    return sqrt(_x * _x + _y * _y + _z * _z);
}
