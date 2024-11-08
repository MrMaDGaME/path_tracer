#include "UniformTexture.h"

#include <utility>

UniformTexture::UniformTexture(std::shared_ptr<Texture> texture) : texture_(std::move(texture)) {}

UniformTexture::UniformTexture(float ks, float kd, float ns, const Color &color) : texture_(new Texture(ks,
                                                                                                        kd,
                                                                                                        ns,
                                                                                                        color)) {
}

void UniformTexture::reflect(Vector3 point, Vector3 direction, Vector3 normal, Vector3 &lightDirection, Color &filter) {
    // Generate a_ random light direction for diffuse materials
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1, 1);
    lightDirection = {static_cast<float>(dis(gen)), static_cast<float>(dis(gen)), static_cast<float>(dis(gen))};
    lightDirection = (lightDirection * normal < 0) ? -lightDirection : lightDirection;

    filter = (texture_->color / 255.0f) *
             (texture_->kd * std::max(0.0f, normal * lightDirection) +
              texture_->ks * std::pow(std::max(0.0f, direction.get_reflection(normal) * lightDirection), texture_->ns));
}
