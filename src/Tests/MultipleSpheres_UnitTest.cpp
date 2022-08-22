#include "Renderer.h"

int main(){
    Renderer newRenderer(1024, 768);

    std::vector<Sphere> spheres;

    spheres.push_back(Sphere(-3, 0, -16, 1, Colors::Cyan()));
    spheres.push_back(Sphere(4, 1, -16, 2, Colors::Green()));
    spheres.push_back(Sphere(-3, -2, -20, 1, Colors::Blue()));
    
    newRenderer.multipleSpheres(spheres);

    return 0;
}