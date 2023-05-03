#pragma once

#include <iostream>
#include "../colors.hh"
#include "material.hh"

class TextureMaterial {
public:
    struct Texture {
        Texture(float ks, float kd, float ns, bool is_opaque, const Color &color) : ks(
                ks), kd(kd), ns(ns), is_opaque(is_opaque), color(color) {}

        Texture(float ks, float kd, float ns, bool isOpaque, const Color &color, Material material) : ks(ks), kd(kd),
                                                                                                      ns(ns), is_opaque(
                        isOpaque), color(color), material(material) {}

        float ks, kd, ns;
        bool is_opaque;
        Color color;
        Material material = DEFAULT;
    };

    virtual Texture *get_texture(float x, float y, float z) = 0;

    virtual ~TextureMaterial() = default;
};
