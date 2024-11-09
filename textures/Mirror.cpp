#include "Mirror.h"

void MirrorTexture::reflect(Vector3 point, Vector3 direction, Vector3 normal, Vector3 &lightDirection, Color &filter) {
    filter = Color(1, 1, 1);
    lightDirection = direction.get_reflection(normal);
}

Color MirrorTexture::getColor(Vector3 point) {
    return {0, 0, 0};
}
