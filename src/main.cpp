#include "renderer.h"

int main(){
    Renderer newRenderer(1024, 768);

    std::vector<Sphere> spheres;

    spheres.push_back(Sphere(-3, 0, -16, 2));
    spheres.push_back(Sphere(-5, 3, -17, 4));

    newRenderer.multipleSpheres(spheres);

    return 0;
}