#include "Renderer.h"

int main(){
    Renderer newRenderer(1024, 768, "lightingTest");

    std::vector<Sphere> spheres;

    spheres.push_back(Sphere(-3, 0, -16, 1, Colors::Cyan()));
    spheres.push_back(Sphere(4, 1, -16, 2, Colors::Green()));
    spheres.push_back(Sphere(-3, -2, -20, 1, Colors::Blue()));
    spheres.push_back(Sphere(4, 5, -10, 1, Colors::White()));
    
    std::vector<LightSource> lights;
    lights.push_back(LightSource(4, 5, -10, 1));

    newRenderer.renderWithLighting(spheres, lights);

    return 0;
}