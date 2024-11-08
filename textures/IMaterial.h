#pragma once

#include "../image/Color.h"
#include "../Vector3.h"

class IMaterial {
public:
    virtual void reflect(Vector3 point, Vector3 direction, Vector3 normal, Vector3 &lightDirection, Color &filter) = 0;
};
