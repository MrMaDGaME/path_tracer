#include "uniform_texture.hh"

UniformTexture::UniformTexture(TextureMaterial::Texture *texture) : _texture(texture) {}

UniformTexture::UniformTexture(float ks, float kd, float ns, bool is_opaque, const Color &color) {
    _texture = new TextureMaterial::Texture(ks, kd, ns, is_opaque, color);
}

TextureMaterial::Texture *UniformTexture::get_texture(float x, float y, float z) {
    return _texture;
}
