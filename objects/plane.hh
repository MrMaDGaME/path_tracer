#pragma once

#include <iostream>
#include "object.hh"

class Plane : public Object {
public:
    Plane(float a, float b, float c, float d, Texture_Material *texture);

    float raycast_hit(Vector3 point, Vector3 direction) override;

    Vector3 get_normal(Vector3 point) override;

    Texture_Material::Texture get_texture(Vector3 point) override;

protected:
    float a, b, c, d;
};

float plane_raycast_hit(Vector3 point, Vector3 direction, float a, float b, float c, float d);
