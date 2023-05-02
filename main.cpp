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

#define FOV (120 * M_PI / 180)
#define WIDTH 1920
#define HEIGHT 1080
#define ZMIN 1
#define MIN_TIME 10

int main() {
    // Variables
    Vector3 camera_center(0, 1, 0);
    Vector3 camera_direction(1, 0, 0);
    Vector3 camera_up(0, 1, 0);
    // Camera
    auto camera = new Camera(camera_center, camera_direction, camera_up, atan(tan(FOV) * HEIGHT / WIDTH) + M_PI / 2,
                             FOV,
                             ZMIN);
    float pixel_size = (2 * tan(camera->alpha / 2) * ZMIN) / WIDTH;
    Vector3 left(camera->up._y * camera->direction._z - camera->up._z * camera->direction._y,
                 camera->up._x * camera->direction._z - camera->up._z * camera->direction._x,
                 camera->up._x * camera->direction._y - camera->up._y * camera->direction._x);
    Vector3 right = -left;
    Vector3 down = -camera->up;
    Vector3 upper_left_corner =
            camera->center + camera->up * (pixel_size * (HEIGHT - 1) / 2) + camera->direction * camera->z +
            left * (pixel_size * (WIDTH - 1) / 2);
    // Random
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-pixel_size / 2, pixel_size / 2);
    // Scene
    std::cout << "Creating scene..." << std::endl;
    Scene scene(camera);
    // Objects
    scene.addObject(
            new Plane(0, 1, 0, 0, new Uniform_Texture(0.1, 0.9, 10, true, Color(100, 255, 100))));
//    scene.addObject(
//            new Plane(0, 1, 0, -2, new Uniform_Texture(0.1, 0.9, 10, true, Color(100, 100, 100))));
    scene.addObject(new Sphere(Vector3(10, 1, -2), 1,
                               new Uniform_Texture(0.9, 0.1, 15, true, Color(0, 0, 255))));
    scene.addObject(new Sphere(Vector3(10, 1, 2), 1,
                               new Uniform_Texture(0.9, 0.1, 15, true, Color(255, 0, 0))));
    scene.addObject(new Sphere(Vector3(5, 0, 0), 8,
                               new Uniform_Texture(0.1, 0.9, 15, true, Color(150, 150, 150))));
    // lights
    scene.addLight(new SphereLight(Vector3(10, 1, 0), Color(255, 255, 255), 1));
    scene.addLight(new PlaneLight(Vector3(-1, 0, 0), Vector3(1, 0, 0), Color(255, 255, 255)));
    // Image
    std::cout << "Rendering..." << std::endl;
    Image image(WIDTH, HEIGHT);
    int nb_frames = 0;
    std::time_t start = std::time(nullptr);
    while (true) {
        /*if (std::time(nullptr) - start > MIN_TIME) {
            break;
        }*/
        for (int j = 0; j < HEIGHT; j++) {
            for (int i = 0; i < WIDTH; i++) {
                auto x = static_cast<float>(dis(gen));
                auto y = static_cast<float>(dis(gen));
                Vector3 pixel = upper_left_corner + right * ((static_cast<float>(i) * pixel_size) + x) +
                                down * ((static_cast<float>(j) * pixel_size) + y);
                Color pixel_color = scene.get_pixel_color(pixel, (pixel - camera->center).normalize(),
                                                          {MAX_COLOR, MAX_COLOR, MAX_COLOR});
                image.avegrage_color(i, j, pixel_color, nb_frames);
            }
        }
        nb_frames++;
//        image.to_ppm("../results/all_frames_d*d/frame" + std::to_string(nb_frames) + ".ppm");
        image.to_ppm("../result.ppm");
        std::cout << "Render time : " << std::time(nullptr) - start << "s" << std::endl;
    }
//    std::cout << nb_frames << " frames rendered." << std::endl;
//    std::cout << "Saving image..." << std::endl;
    return 0;
}
