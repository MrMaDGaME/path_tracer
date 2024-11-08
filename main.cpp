#include <iostream>
#include <cmath>
#include <random>
#include "scene/Camera.h"
#include "scene/Scene.h"
#include "objects/plane.hh"
#include "objects/sphere.hh"
#include "image/Image.h"
#include "lights/sphere_light.hh"
#include "lights/plane_light.hh"
#include "textures/mirror_texture.hh"
#include "image/ImageExporter.h"

#define FOV (30 * M_PI / 180)
#define WIDTH 1920
#define HEIGHT 1080
#define ZMIN 1
#define REFRACTION_INDEX_AIR 1.0f

int main() {
    // Initialisation de la caméra
    Vector3 camera_center(0, 1, 0);
    Vector3 camera_direction(1, 0, 0);
    Vector3 camera_up(0, 1, 0);
    Camera camera(camera_center, camera_direction, camera_up, FOV, ZMIN, WIDTH, HEIGHT);

    // Initialisation de la scène
    Scene scene;

    // Ajout des objets
    scene.addObject(new Plane(0, 1, 0, 0, new UniformTexture(0.1, 0.9, 10, true, Color(100, 255, 100))));
    scene.addObject(new Plane({10, 0, 2}, {-1, 0, -1}, new UniformTexture(new MirrorTexture())));
    scene.addObject(new Sphere(Vector3(10, 0.5, -2), 0.5, new UniformTexture(0.9, 0.1, 50, true, Color(0, 0, 255))));
    scene.addObject(new Sphere(Vector3(10, 2.5, -2), 0.5, new UniformTexture(0.9, 0.1, 50, true, Color(255, 0, 0))));
    scene.addObject(new Sphere(Vector3(0, 0, 0), 15, new UniformTexture(0.1, 0.9, 10, true, Color(150, 150, 150))));

    // Ajout des lumières
    scene.addLight(new SphereLight(Vector3(10, 1.5, -2), Color(255, 255, 255), 0.5));

    // Création de l'image
    Image image(WIDTH, HEIGHT);

    // Rendu de la scène
    std::cout << "Rendering..." << std::endl;
    for (int j = 0; j < camera.height; ++j) {
        for (int i = 0; i < camera.width; ++i) {
            Vector3 pixel = camera.getPixelPosition(i, j);  // Calculer la position du pixel dans l'espace
            Color pixel_color = scene.renderPixel(pixel, (pixel - camera.center).normalize());
            image.setPixel(i, j, pixel_color);
        }
    }

    // Sauvegarde de l'image
    ImageExporter::exportToPpm(image, "../results/rendered_scene.ppm");
    std::cout << "Rendering complete. Image saved to ../results/rendered_scene.ppm" << std::endl;

    return 0;
}
