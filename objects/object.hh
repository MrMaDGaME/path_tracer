#pragma once

#include <iostream>
#include "../textures/texture_material.hh"
#include "../textures/uniform_texture.hh"
#include "../vector_3.hh"

class Object {
public:
    virtual float raycast_hit(Vector3 point, Vector3 direction) = 0;

    virtual Vector3 get_normal(Vector3 point) = 0;

    virtual TextureMaterial::Texture *get_texture(Vector3 point) = 0;

    virtual ~Object() {
        delete texture;
    }

protected:
    explicit Object(TextureMaterial *texture) : texture(texture) {}

    TextureMaterial *texture;
};
