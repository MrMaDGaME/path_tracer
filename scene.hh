#pragma once

#include <iostream>
#include <vector>
#include "objects/object.hh"
#include "lights/sphere_light.hh"
#include "camera.hh"

class Scene {
public:
    explicit Scene(Camera *camera);

    virtual ~Scene();

    void addObject(Object *object);

    void addLight(SphereLight *light);

    float get_hit(Vector3 point, Vector3 direction, Object *&current_obj);

    Color getLight(Vector3 point, SphereLight *light);

    Vector3 get_direct_hit(Vector3 point, Vector3 direction, Object *&current_obj);

    Color get_pixel_color(Vector3 point, Vector3 direction, int max_depth);

    std::vector<Object *> objects;
    std::vector<SphereLight *> lights;
    Camera *camera = nullptr;
};
