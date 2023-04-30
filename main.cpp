#include <iostream>
#include <cmath>
#include <random>
#include "camera.hh"
#include "scene.hh"
#include "objects/plane.hh"
#include "objects/sphere.hh"
#include "image.hh"
#include "lights/sphere_light.hh"

#define FOV (120 * M_PI / 180)
#define WIDTH 1920
#define HEIGHT 1080
#define ZMIN 1
#define MAX_REFLECTION 5
#define ANTIALIASING 1

int main() {
    // Variables
    Vector3 camera_center(0, 1, 0);
    Vector3 camera_direction(1, 0, 0);
    Vector3 camera_up(0, 1, 0);
    // Camera
    auto camera = new Camera(camera_center, camera_direction, camera_up, atan(tan(FOV) * HEIGHT / WIDTH) + M_PI / 2,
                             FOV,
                             ZMIN);
    float pixel_size = (2 * tan(camera->getAlpha() / 2) * ZMIN) / WIDTH;
    Vector3 left(camera->up._y * camera->direction._z - camera->up._z * camera->direction._y,
                 camera->up._x * camera->direction._z - camera->up._z * camera->direction._x,
                 camera->up._x * camera->direction._y - camera->up._y * camera->direction._x);
    Vector3 right = -left;
    Vector3 down = -camera->up;
    Vector3 upper_left_corner =
            camera->center + camera->up * (pixel_size * (HEIGHT - 1) / 2) + camera->direction * ZMIN +
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
            new Plane(0, 1, 0, 0, new Uniform_Texture(1, 1, 30, 0, true, Color(100, 255, 100))));
    scene.addObject(new Sphere(Vector3(10, 1.5, -1.5), 1,
                               new Uniform_Texture(0.4, 0.9, 15, 0.9, true, Color(255, 255, 255))));
    scene.addObject(new Sphere(Vector3(10, 1.5, 1.5), 1,
                               new Uniform_Texture(0.4, 0.9, 15, 0.1, true, Color(255, 0, 0))));
    scene.addObject(new Sphere(Vector3(0, 0, 0), 100,
                               new Uniform_Texture(0.4, 0.9, 15, 0.1, true, Color(150, 150, 255))));
    // lights
    scene.addLight(new SphereLight(Vector3(5, 5, 0), Color(255, 255, 255), 0.5));
    // Image
    std::cout << "Rendering..." << std::endl;
    Image image(WIDTH, HEIGHT);
    for (float j = 0; j < HEIGHT; j++) {
        for (float i = 0; i < WIDTH; i++) {
            float r = 0, g = 0, b = 0;
            for (float k = 0; k < ANTIALIASING; k++) {
                float x = ANTIALIASING == 1 ? 0 : dis(gen);
                float y = ANTIALIASING == 1 ? 0 : dis(gen);
                Vector3 pixel = upper_left_corner + right * ((i * pixel_size) + x) +
                                down * ((j * pixel_size) + y);
                Color tmp_color = scene.get_pixel_color(pixel, pixel - camera->center, MAX_REFLECTION);
                r = (r / (k + 1) * k + tmp_color._r / (k + 1));
                g = (g / (k + 1) * k + tmp_color._g / (k + 1));
                b = (b / (k + 1) * k + tmp_color._b / (k + 1));
            }
            image.set_pixel(i, j, Color(r, g, b));
        }
    }
    image.to_ppm("../result.ppm");
    return 0;
}
