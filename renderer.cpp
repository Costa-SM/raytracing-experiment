#include "renderer.h"

Renderer::Renderer(int width, int height){
    this->w = width;
    this->h = height;
    framebuffer = std::vector<pixelColor>(width * height);
    std::cout << "Framebuffer Size: " << framebuffer.size() << std::endl;

    outputFile.open("./outputImage.ppm");
    std::cout << "Starting render." << std::endl;
    startTime = std::chrono::high_resolution_clock::now();
}

Renderer::~Renderer(){
    // Stop counting time
    endTime = std::chrono::high_resolution_clock::now();
    
    // Write to output file and close it
    outputFile << "P6\n" << w << " " << h << "\n255\n";
    for(std::vector<pixelColor>::iterator it = framebuffer.begin(); it != framebuffer.end(); it++){
        outputFile << (char)(255 * std::max(0., std::min(1., (*it).x)));
        outputFile << (char)(255 * std::max(0., std::min(1., (*it).y)));
        outputFile << (char)(255 * std::max(0., std::min(1., (*it).z)));
    }
    
    outputFile.close();

    std::cout << "Finished render." << std::endl;
    std::cout << "Elapsed time: " 
        << (std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime)).count() 
        << " milliseconds." << std::endl;
}

void Renderer::gradientRender(){
    // Generate sample output
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            framebuffer[i + j * w](j / double(h), i / double(w), 0);
        }
    }
}

void Renderer::singleSphere(const Sphere sphere){
    // Preallocate variables
    double x = 0;
    double y = 0;
    
    // Generate raycasting output
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            x =  (2 * (i + 0.5) / (float)w - 1) * tan(fov/2.) * w / (float)h;
            y = -(2 * (j + 0.5) / (float)h - 1) * tan(fov/2.);

            Vector3 direction = Vector3(x, y, -1).normalize();

            framebuffer[i + j * w] = castRay(cameraLocation, direction, sphere);
        }
    }
}

pixelColor Renderer::castRay(const Vector3 origin, const Vector3 direction, Sphere sphere){
    // Sphere color
    if(sphere.rayIntersect(origin, direction))
        return Colors::Cyan();
    
    // Background color
    else
        return Colors::Gray();
}