#pragma once

#include "IMaterial.h"

class MirrorTexture : public IMaterial {
public:
    void reflect(Vector3 point, Vector3 direction, Vector3 normal, Vector3 &lightDirection, Color &filter) override;
};
