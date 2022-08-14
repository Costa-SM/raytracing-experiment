#include <limits>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "vectors.h"

#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
public:
    using pixelColor = Vector3;

    Renderer(int width, int height);
    ~Renderer();
    void render();

private:
    int w, h;
    std::vector<pixelColor> framebuffer;
    std::ofstream outputFile;
    time_t startTime, endTime;
};

#endif