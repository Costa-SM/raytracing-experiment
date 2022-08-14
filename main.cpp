#include "renderer.h"

int main(){
    Renderer newRenderer(1024, 768);
    Sphere firstSphere = Sphere(-3, 0, -16, 2);

    newRenderer.singleSphere(firstSphere);

    return 0;
}