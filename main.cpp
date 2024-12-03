#include <iostream>
#include <cmath>
#include <random>
#include "scene/Camera.h"
#include "scene/Scene.h"
#include "image/Image.h"
#include "lights/SphereLight.h"
#include "lights/PlaneLight.h"
#include "textures/Mirror.h"
#include "image/ImageExporter.h"
#include "objects/PlaneObject.h"
#include "objects/SphereObject.h"

#define FOV (30 * M_PI / 180)
#define WIDTH 1920
#define HEIGHT 1080
#define MAX_COLOR 255.f

int main() {
    // Initialisation de la caméra
    Vector3 camera_center(0, 1, 0);
    Vector3 camera_direction(1, 0, 0);
    Vector3 camera_up(0, 1, 0);
    Camera camera(camera_center, camera_direction, camera_up, FOV, WIDTH, HEIGHT);

    // Initialisation de la scène
    Scene scene;

    // Ajout des textures
    auto mirror_texture = std::make_shared<MirrorTexture>();
    auto ground_texture = std::make_shared<UniformTexture>(0.9, 0.9, 100, Color(100, 100, 100));
    auto trunk_texture = std::make_shared<UniformTexture>(0.1, 0.9, 10, Color(139, 69, 19));
    auto leaf_texture = std::make_shared<UniformTexture>(0.1, 0.9, 10, Color(0, 255, 0));
    auto sky_texture = std::make_shared<UniformTexture>(0.1, 0.9, 10, Color(135, 206, 235));

    // Ajout des objets
    scene.addObject(std::make_shared<PlaneObject>(0, 1, 0, 0, ground_texture));
    scene.addObject(std::make_shared<PlaneObject>(Vector3(10, 0, 2), Vector3(-1, 0, -1), mirror_texture));
    scene.addObject(std::make_shared<SphereObject>(Vector3(10, 0.5, -2), 0.5, trunk_texture));
    scene.addObject(std::make_shared<SphereObject>(Vector3(10, 1.5, -2), 0.5, leaf_texture));
    scene.addObject(std::make_shared<SphereObject>(Vector3(0, 0, 0), 15, sky_texture));

    // Ajout des lumières
    scene.addLight(std::make_shared<SphereLight>(Vector3(10, 2.5, -2), 0.5, Color(255, 255, 200)));
    scene.addLight(std::make_shared<PlaneLight>(Vector3(-1, 1, 0), Vector3(1, 0, 0), Color(255, 255, 255)));

    // Création de l'image
    Image image(WIDTH, HEIGHT);

    int nb_frames = 0;
    std::time_t start = std::time(nullptr);
    while (true) {
        /*if (std::time(nullptr) - start > MIN_TIME) {
            break;
        }*/
        // Rendu de la scène
        std::cout << "Rendering..." << std::endl;
        for (int j = 0; j < camera.height; ++j) {
            for (int i = 0; i < camera.width; ++i) {
                Vector3 pixel = camera.getPixelPosition(i, j);  // Calculer la position du pixel dans l'espace
                Color pixel_color = scene.renderPixel(camera.center, (pixel - camera.center).normalize(), MAX_COLOR);
                image.averageColor(i, j, pixel_color, nb_frames);
            }
        }
        nb_frames++;
        ImageExporter::exportToPng(image, "../results/rendered_scene.png");
        std::cout << "Render time : " << std::time(nullptr) - start << "s" << std::endl;
    }

    // Sauvegarde de l'image
    //    ImageExporter::exportToPng(image, "../results/rendered_scene.png");
    std::cout << "Rendering complete. Image saved to ../results/rendered_scene.ppm" << std::endl;

    return 0;
}
