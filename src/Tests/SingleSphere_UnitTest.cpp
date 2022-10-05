#include "Renderer.h"

int main(){
    Renderer newRenderer(1024, 768, "singleSphereTest");
    Sphere newSphere(-3, 0, -16, 1, Colors::Black());

    newRenderer.singleSphere(newSphere);

    return 0;
}