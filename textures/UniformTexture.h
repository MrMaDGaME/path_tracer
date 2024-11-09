#pragma once

#include <random>
#include "IMaterial.h"
#include "Texture.h"

class UniformTexture : public IMaterial {
public:
    explicit UniformTexture(std::shared_ptr<Texture> texture);

    UniformTexture(float ks, float kd, float ns, const Color &color);

    void reflect(Vector3 point, Vector3 direction, Vector3 normal, Vector3 &lightDirection, Color &filter) override;

    Color getColor(Vector3 point) override;

protected:
    std::shared_ptr<Texture> texture_;
};
