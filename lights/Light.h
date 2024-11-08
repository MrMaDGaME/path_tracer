#pragma once

#include <iostream>
#include "../Vector3.h"
#include "../image/Color.h"

class Light {
public :
    virtual float getLightRayCastHit(Vector3 point, Vector3 direction) = 0;

    [[nodiscard]] Color getColor();

protected:
    explicit Light(Color color);
    Color color_;
};
