cmake_minimum_required(VERSION 3.25)
project(path_tracer)

set(CMAKE_CXX_STANDARD 23)

add_executable(path_tracer main.cpp camera.cc colors.cc image.cc lights/sphere_light.cc scene.cc textures/uniform_texture.cc vector_3.cc objects/plane.cc objects/sphere.cc lights/light.hh lights/plane_light.cc lights/plane_light.hh textures/mirror_texture.cc textures/mirror_texture.hh textures/material.hh textures/glass_texture.cc textures/glass_texture.hh)
