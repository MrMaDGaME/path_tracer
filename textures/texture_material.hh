#pragma once

#include <iostream>
#include "../colors.hh"

class Texture_Material {
public:
    struct Texture {
        Texture(float ks, float kd, float ns, bool is_opaque, const Color &color) : ks(
                ks), kd(kd), ns(ns), is_opaque(is_opaque), color(color) {}

        float ks, kd, ns;
        bool is_opaque;
        Color color;
    };

    virtual Texture get_texture(float x, float y, float z) = 0;

    virtual ~Texture_Material() = default;
};
