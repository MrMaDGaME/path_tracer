#include "Light.h"

Light::Light(Color color) {
    color_ = color;
}

Color Light::getColor() {
    return color_;
}
