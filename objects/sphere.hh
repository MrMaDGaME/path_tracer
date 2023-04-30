#pragma once

#include <iostream>
#include "object.hh"

class Sphere : public Object {
public:
    Sphere(const Vector3 &center, float radius, Texture_Material *texture);

    float raycast_hit(Vector3 point, Vector3 direction) override;

    Vector3 get_normal(Vector3 point) override;

    Texture_Material::Texture get_texture(Vector3 point) override;

protected:
    Vector3 center;
    float radius;
};

float sphere_raycast_hit(Vector3 point, Vector3 direction, Vector3 center, float radius);
