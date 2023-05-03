#pragma once

#include <iostream>
#include "texture_material.hh"

class Uniform_Texture : public Texture_Material {
public:
    Uniform_Texture(float ks, float kd, float ns, bool is_opaque, const Color &color);

    Texture get_texture(float x, float y, float z) override;

protected:
    float _ks, _kd, _ns;
    bool is_opaque;
    Color _color;
};
