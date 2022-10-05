#include "Renderer.h"

int main(){
    Renderer newRenderer(1024, 768, "lightingTest");

    Vector3 sunPosition(-1, 3, -10);

    std::vector<Sphere> spheres;

    spheres.push_back(Sphere(-3, 0, -16, 1, Colors::Cyan()));
    spheres.push_back(Sphere(4, 1, -16, 2, Colors::Green()));
    spheres.push_back(Sphere(-3, -2, -20, 1, Colors::Blue()));
    
    std::vector<LightSource> lights;
    lights.push_back(LightSource(sunPosition, 1.0));

    newRenderer.renderWithLighting(spheres, lights);

    return 0;
}