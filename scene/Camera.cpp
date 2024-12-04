#include "Camera.h"
#include <cmath>

Camera::Camera(const Vector3 &center, const Vector3 &direction, const Vector3 &up, float beta, int width, int height)
        : center(center), direction(direction.normalize()), up(up.normalize()), beta(beta), width(width),
          height(height) {

    // Calcul des vecteurs horizontal et vertical
    horizontal = (this->up.cross(this->direction)).normalize();
    vertical = up.normalize();

    // Calcul de la taille d'un pixel
    float viewport_height = 2 * tan(beta / 2);
    pixel_size = viewport_height / static_cast<float>(height);

    // Calcul de la position du coin supérieur gauche
    upper_left_corner = center + direction + vertical * (viewport_height / 2) -
                        horizontal * (pixel_size * (static_cast<float>(width) - 1) / 2);
}

Vector3 Camera::getPixelPosition(int x, int y) const {
    // Random
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-pixel_size / 2, pixel_size / 2);
    // Calcul de la position du pixel (x, y) en coordonnées 3D
    return upper_left_corner + horizontal * ((static_cast<float>(x) * pixel_size) + static_cast<float>(dis(gen))) -
           vertical * ((static_cast<float>(y) * pixel_size) + static_cast<float>(dis(gen)));
}
