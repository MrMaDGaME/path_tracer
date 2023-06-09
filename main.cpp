#include <iostream>
#include <cmath>
#include <random>
#include "camera.hh"
#include "scene.hh"
#include "objects/plane.hh"
#include "objects/sphere.hh"
#include "image.hh"
#include "lights/sphere_light.hh"
#include "lights/plane_light.hh"
#include "textures/mirror_texture.hh"

#define FOV (30 * M_PI / 180)
#define WIDTH 1920
#define HEIGHT 1080
#define ZMIN 1
#define MIN_TIME 10
#define REFRACTION_INDEX_AIR 1.0f

int main() {
    // Variables
    Vector3 camera_center(0, 1, 0);
    Vector3 camera_direction(1, 0, 0);
    Vector3 camera_up(0, 1, 0);
    // Camera
    auto camera = new Camera(camera_center, camera_direction, camera_up, FOV, ZMIN, WIDTH, HEIGHT);
    auto height = static_cast<float>(camera->height);
    auto width = static_cast<float>(camera->width);
    float pixel_size = (2 * tan(camera->beta / 2) * camera->z) / height;
    Vector3 left(camera->up._y * camera->direction._z - camera->up._z * camera->direction._y,
                 camera->up._x * camera->direction._z - camera->up._z * camera->direction._x,
                 camera->up._x * camera->direction._y - camera->up._y * camera->direction._x);
    Vector3 right = -left;
    Vector3 down = -camera->up;
    Vector3 upper_left_corner =
            camera->center + camera->up * (pixel_size * (height - 1) / 2) + camera->direction * camera->z +
            left * (pixel_size * (width - 1) / 2);
    // Random
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-pixel_size / 2, pixel_size / 2);
    // Scene
    std::cout << "Creating scene..." << std::endl;
    Scene scene(camera);
    // Objects
    scene.addObject(
            new Plane(0, 1, 0, 0, new UniformTexture(0.1, 0.9, 10, true, Color(100, 255, 100))));
//    scene.addObject(
//            new Plane({-1, 0, 0}, {1, 0, 0}, new UniformTexture(0.1, 0.9, 10, true, Color(255, 255, 255))));
    scene.addObject(
            new Plane({10, 0, 2}, {-1, 0, -1}, new UniformTexture(new MirrorTexture())));
    scene.addObject(new Sphere(Vector3(10, 0.5, -2), 0.5,
                               new UniformTexture(0.9, 0.1, 50, true, Color(0, 0, 255))));
    scene.addObject(new Sphere(Vector3(10, 2.5, -2), 0.5,
                               new UniformTexture(0.9, 0.1, 50, true, Color(255, 0, 0))));
    scene.addObject(new Sphere(Vector3(0, 0, 0), 15,
                               new UniformTexture(0.1, 0.9, 10, true, Color(150, 150, 150))));
    // lights
    scene.addLight(new SphereLight(Vector3(10, 1.5, -2), Color(255, 255, 255), 0.5));
//    scene.addLight(new PlaneLight(Vector3(-1, 0, 0), Vector3(1, 0, 0), Color(255, 255, 255)));
//     Image
    std::cout << "Rendering..." << std::endl;
    Image image(WIDTH, HEIGHT);
    int nb_frames = 0;
    std::time_t start = std::time(nullptr);
    while (true) {
        /*if (std::time(nullptr) - start > MIN_TIME) {
            break;
        }*/
        for (int j = 0; j < camera->height; j++) {
            for (int i = 0; i < camera->width; i++) {
                auto x = static_cast<float>(dis(gen));
                auto y = static_cast<float>(dis(gen));
                Vector3 pixel = upper_left_corner + right * ((static_cast<float>(i) * pixel_size) + x) +
                                down * ((static_cast<float>(j) * pixel_size) + y);
                Color pixel_color = scene.get_pixel_color(pixel, (pixel - camera->center).normalize(),
                                                          {MAX_COLOR, MAX_COLOR, MAX_COLOR}, REFRACTION_INDEX_AIR);
                image.average_color(i, j, pixel_color, nb_frames);
            }
        }
        nb_frames++;
//        image.to_ppm("../results/all_frames/frame" + std::to_string(nb_frames) + ".ppm");
        image.to_ppm("../results/tmp.ppm");
        std::cout << "Render time : " << std::time(nullptr) - start << "s" << std::endl;
    }
//    std::cout << nb_frames << " frames rendered." << std::endl;
//    std::cout << "Saving image..." << std::endl;
    return 0;
}
