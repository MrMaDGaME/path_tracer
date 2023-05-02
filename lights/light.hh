#pragma once

#include <iostream>
#include "../vector_3.hh"
#include "../colors.hh"

class Light {
public :
    virtual float raycast_hit(Vector3 point, Vector3 direction) = 0;

    virtual ~Light() = default;

    Color getColor() const {
        return color;
    }

protected:
    explicit Light(const Color &color) : color(color) {}

    Color color;
};
