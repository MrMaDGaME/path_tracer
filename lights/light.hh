#pragma once

#include <iostream>
#include "../Vector3.h"
#include "../image/Color.h"

class Light {
public :
    virtual float raycast_hit(Vector3 point, Vector3 direction) = 0;

    virtual ~Light() = default;

    [[nodiscard]] Color getColor() const {
        return color;
    }

protected:
    explicit Light(const Color &color) : color(color) {}

    Color color;
};
