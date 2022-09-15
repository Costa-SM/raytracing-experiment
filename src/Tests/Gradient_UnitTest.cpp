#include "Renderer.h"

int main(){
    Renderer newRenderer(1024, 768, "gradientTest");
    newRenderer.gradientRender();

    return 0;
}