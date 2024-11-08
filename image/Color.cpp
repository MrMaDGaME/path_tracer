#include "Color.h"

Color::Color() : r_(0), g_(0), b_(0) {
}

Color::Color(float r, float g, float b) {
    r_ = std::min(r, MAX_COLOR);
    g_ = std::min(g, MAX_COLOR);
    b_ = std::min(b, MAX_COLOR);
}

std::ostream &operator<<(std::ostream &os, const Color &color) {
    os << "r: " << color.r_ << " g: " << color.g_ << " b_: " << color.b_;
    return os;
}

Color Color::operator*(const float f) const {
    return {r_ * f, g_ * f, b_ * f};
}

Color Color::operator+(const Color &color) const {
    return {r_ + color.r_, g_ + color.g_, b_ + color.b_};
}

Color Color::operator/(float f) const {
    return {r_ / f, g_ / f, b_ / f};
}

Color Color::operator+=(const Color &color) {
    r_ += color.r_;
    g_ += color.g_;
    b_ += color.b_;
    r_ = std::min(r_, MAX_COLOR);
    g_ = std::min(g_, MAX_COLOR);
    b_ = std::min(b_, MAX_COLOR);
    return *this;
}

bool Color::operator==(const Color &color) const {
    return color.r_ == r_ && color.g_ == g_ && color.b_ == b_;
}

Color Color::operator*(const Color &color) const {
    return {r_ * color.r_, g_ * color.g_, b_ * color.b_};
}

bool Color::operator<(const Color &color) const {
    return r_ < color.r_ && g_ < color.g_ && b_ < color.b_;
}

[[maybe_unused]] Color Color::proportionalProduct(const float f) const {
    float max = std::max(r_, std::max(g_, b_));
    if (max * f > MAX_COLOR) {
        return {MAX_COLOR * r_ / max, MAX_COLOR * g_ / max, MAX_COLOR * b_ / max};
    }
    return {r_ * f, g_ * f, b_ * f};
}

[[maybe_unused]] float Color::getR() const {
    return r_;
}

float Color::getG() const {
    return g_;
}

float Color::getB() const {
    return b_;
}

Color Color::operator*=(const Color &color) {
    r_ *= color.r_;
    g_ *= color.g_;
    b_ *= color.b_;
    return *this;
}

Color Color::operator*=(float f) {
    r_ *= f;
    g_ *= f;
    b_ *= f;
    return *this;
}
