#pragma once

#include <iostream>
#include "object.hh"

class Plane : public Object {
public:
    [[maybe_unused]] Plane(float a, float b, float c, float d, TextureMaterial *texture);

    [[maybe_unused]] Plane(Vector3 point, Vector3 normal, TextureMaterial *texture);

    float raycast_hit(Vector3 point, Vector3 direction) override;

    Vector3 get_normal(Vector3 point) override;

    TextureMaterial::Texture *get_texture(Vector3 point) override;

protected:
    float a, b, c, d;
};

float plane_raycast_hit(Vector3 point, Vector3 direction, float a, float b, float c, float d);
