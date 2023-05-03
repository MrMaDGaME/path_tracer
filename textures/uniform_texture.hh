#pragma once

#include <iostream>
#include "texture_material.hh"

class UniformTexture : public TextureMaterial {
public:
    explicit UniformTexture(TextureMaterial::Texture *texture);

    UniformTexture(float ks, float kd, float ns, bool is_opaque, const Color &color);

    Texture *get_texture(float x, float y, float z) override;

protected:
    TextureMaterial::Texture *_texture;
};
