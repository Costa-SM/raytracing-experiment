#include "renderer.h"

Renderer::Renderer(int width, int height){
    this->w = width;
    this->h = height;
    framebuffer = std::vector<pixelColor>(width * height);
    std::cout << "Framebuffer Size: " << framebuffer.size() << std::endl;

    outputFile.open("./outputImage.ppm");
}

Renderer::~Renderer(){
    outputFile.close();
}

void Renderer::render(){
    std::cout << "Starting render." << std::endl;
    time(&startTime);

    // Generate sample input
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            framebuffer[i + j * w](j / double(h), i / double(w), 0);
        }
    }

    // Write to output file
    outputFile << "P6\n" << w << " " << h << "\n255\n";
    for(std::vector<pixelColor>::iterator it = framebuffer.begin(); it != framebuffer.end(); it++){
        outputFile << (char)(255 * std::max(0.d, std::min(1.d, (*it).x)));
        outputFile << (char)(255 * std::max(0.d, std::min(1.d, (*it).y)));
        outputFile << (char)(255 * std::max(0.d, std::min(1.d, (*it).z)));
    }

    time(&endTime);
    std::cout << "Finished render.";
    std::cout << "Elapsed time: " << double(endTime - startTime) << " seconds." << std::endl; 
}