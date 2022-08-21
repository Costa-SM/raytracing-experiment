#include "Renderer.h"

int main(){
    Renderer newRenderer(1024, 768);
    Sphere newSphere(-3, 0, -16, 1);

    newRenderer.singleSphere(newSphere);

    return 0;
}