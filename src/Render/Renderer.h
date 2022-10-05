#include <limits>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <chrono>
#include <string>
#include <limits>

#include "Geometry.h"
#include "Colors.h"
#include "Light.h"

#ifndef RENDERER_H
#define RENDERER_H

using pixelColor = Vector3;

class Renderer {
public:
    Renderer(int width, int height, std::string filename);
    ~Renderer();
    void gradientRender();
    void singleSphere(Sphere sphere);
    void multipleSpheres(std::vector<Sphere> spheres);
    void renderWithLighting(std::vector<Sphere> spheres, std::vector<LightSource> lights);

private:
    // Preallocated variables
    double x, y;

    int w, h;
    int fov = 120;
    Vector3 cameraLocation = Vector3(0, 0, 0);
    color backgroundColor = Colors::SkyBlue();

    std::vector<pixelColor> framebuffer;
    std::ofstream outputFile;
    std::chrono::_V2::high_resolution_clock::time_point startTime, endTime;
    color determinePixelColor(Vector3 origin, Vector3 direction, std::vector<Sphere> spheres, std::vector<LightSource> lights);
};

#endif