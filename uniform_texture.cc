#include "uniform_texture.hh"

Uniform_Texture::Uniform_Texture(float ks, float kd, float ns, float shine, bool is_opaque, const
Color &color)
        : _ks(ks), _kd(kd), _ns(ns), _shine(shine), is_opaque(is_opaque), _color(color) {}

Texture_Material::Texture Uniform_Texture::get_texture(float x, float y, float z) {
    return {_ks, _kd, _ns, _shine, is_opaque, _color};
}
