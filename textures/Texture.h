#pragma once

#include "../image/Color.h"

struct Texture {
    Texture(float ks, float kd, float ns, const Color &color) : ks(ks), kd(kd), ns(ns), color(color) {}

    float ks, kd, ns;
    Color color;
};
