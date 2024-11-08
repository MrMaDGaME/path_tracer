#pragma once

#include <iostream>
#include "../textures/IMaterial.h"
#include "../textures/UniformTexture.h"
#include "../Vector3.h"

class Object {
public:
    virtual float getObjectRayCastHit(Vector3 point, Vector3 direction) = 0;

    virtual Vector3 getNormal(Vector3 point) = 0;

    [[nodiscard]] std::shared_ptr<IMaterial> getMaterial() const;

protected:
    explicit Object(std::shared_ptr<IMaterial> material);
    std::shared_ptr<IMaterial> material_;
};
