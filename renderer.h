#include <limits>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <chrono>

#include "vector3.h"
#include "geometry.h"

#ifndef RENDERER_H
#define RENDERER_H

using pixelColor = Vector3;

class Renderer {
public:
    Renderer(int width, int height);
    ~Renderer();
    void gradientRender();
    void singleSphere(const Sphere sphere);

    pixelColor castRay(const Vector3 origin, const Vector3 direction, const Sphere sphere);

private:
    int w, h;
    int fov = 120;
    Vector3 cameraLocation = Vector3(0, 0, 0);

    std::vector<pixelColor> framebuffer;
    std::ofstream outputFile;
    std::chrono::_V2::high_resolution_clock::time_point startTime, endTime;
};

#endif