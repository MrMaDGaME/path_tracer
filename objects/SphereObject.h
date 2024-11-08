#pragma once

#include "Object.h"
#include "../geometry/Sphere.h"

class SphereObject : public Object, Sphere {
public:
    SphereObject(const Vector3 &center, float radius, std::shared_ptr<IMaterial> material);

    float getObjectRayCastHit(Vector3 point, Vector3 direction) override;

    Vector3 getNormal(Vector3 point) override;
};
