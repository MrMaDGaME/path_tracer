#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "objects/object.hh"
#include "lights/light.hh"
#include "camera.hh"

class Scene {
public:
    explicit Scene(Camera *camera);

    virtual ~Scene();

    void addObject(Object *object);

    void addLight(Light *light);

    Vector3 get_direct_hit(Vector3 point, Vector3 direction, Object *&current_obj, Light *&current_light);

    float get_object_hit(Vector3 point, Vector3 direction, Object *&current_obj);

    float get_light_hit(Vector3 point, Vector3 direction, Light *&current_light);

    Color get_pixel_color(Vector3 point, Vector3 direction, Color total_filter);

    std::vector<Object *> objects;
    std::vector<Light *> lights;
    Camera *camera = nullptr;
};
