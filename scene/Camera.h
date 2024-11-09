#pragma once

#include <iostream>
#include <random>
#include "../Vector3.h"

class Camera {
public:
    Camera(const Vector3 &center, const Vector3 &direction, const Vector3 &up, float beta, int width, int height);

    // Méthode pour obtenir la position 3D d_'un pixel
    [[nodiscard]] Vector3 getPixelPosition(int x, int y) const;

    Vector3 center;
    Vector3 direction;
    Vector3 up;
    float beta;  // Champ de vision
    int width;   // Largeur de l'image en pixels
    int height;  // Hauteur de l'image en pixels

private:
    Vector3 horizontal;   // Vecteur horizontal calculé à partir de direction et up
    Vector3 vertical;     // Vecteur vertical calculé à partir de up
    Vector3 upper_left_corner; // Coin supérieur gauche de l'image projetée
    float pixel_size;     // Taille d_'un pixel en termes de coordonnées 3D
};
