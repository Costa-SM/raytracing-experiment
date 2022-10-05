#include "Renderer.h"

Renderer::Renderer(int width, int height, std::string filename){
    this->w = width;
    this->h = height;
    framebuffer = std::vector<pixelColor>(width * height);
    std::cout << "Framebuffer Size: " << framebuffer.size() << std::endl;

    outputFile.open("./" + filename + ".ppm");
    std::cout << "Starting render." << std::endl;
    startTime = std::chrono::high_resolution_clock::now();
}

Renderer::~Renderer(){
    // Stop counting time
    endTime = std::chrono::high_resolution_clock::now();
    
    // Write to output file and close it
    outputFile << "P6\n" << w << " " << h << "\n255\n";
    for(std::vector<pixelColor>::iterator it = framebuffer.begin(); it != framebuffer.end(); it++){
        outputFile << (char)((int) (std::min(255., std::max(0., (*it).x))));
        outputFile << (char)((int) (std::min(255., std::max(0., (*it).y))));
        outputFile << (char)((int) (std::min(255., std::max(0., (*it).z))));
    }
    
    outputFile.close();

    std::cout << "Finished render." << std::endl;
    std::cout << "Elapsed time: " 
        << (std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime)).count() 
        << " milliseconds." << std::endl;
}

void Renderer::gradientRender(){
    // Generate sample output
    #pragma omp parallel for
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            framebuffer[i + j * w](255 * j / double(h), 255 * i / double(w), 0);
        }
    }
}

void Renderer::singleSphere(Sphere sphere){
    // Reset variables
    x = 0;
    y = 0;
    
    // Generate raycasting output
    #pragma omp parallel for
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            x =  (2 * (i + 0.5) / (float)w - 1) * tan(fov/2.) * w / (float)h;
            y = -(2 * (j + 0.5) / (float)h - 1) * tan(fov/2.);

            Vector3 direction = Vector3(x, y, -1).normalize();

            framebuffer[i + j * w] = sphere.rayIntersect(cameraLocation, direction, backgroundColor);
        }
    }
}

void Renderer::multipleSpheres(std::vector<Sphere> spheres){
    // Reset variables
    x = 0;
    y = 0;
    
    // Generate raycasting output
    #pragma omp parallel for
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            x =  (2 * (i + 0.5) / (float)w - 1) * tan(fov/2.) * w / (float)h;
            y = -(2 * (j + 0.5) / (float)h - 1) * tan(fov/2.);

            Vector3 direction = Vector3(x, y, -1).normalize();

            // @TODO: Optimize the raycasting operation.
            // Iterating over all spheres every single operation is not good practice. (?)
            double smallestDistance = std::numeric_limits<double>::max();

            bool hitSphere = false;
            color currentPixel;
            double currentDistance;
            for(std::vector<Sphere>::iterator it = spheres.begin(); it != spheres.end(); it++){
                currentPixel = (*it).rayIntersect(cameraLocation, direction, backgroundColor);
                currentDistance = (*it).getCenter().abs();
                
                if(smallestDistance > currentDistance && currentPixel != backgroundColor){
                    hitSphere = true;
                    smallestDistance = currentDistance;
                    framebuffer[i + j * w] = currentPixel;
                }
            }

            if(!hitSphere)
                framebuffer[i + j * w] = backgroundColor;
        }
    }
}

void Renderer::renderWithLighting(std::vector<Sphere> spheres, std::vector<LightSource> lights){
    // Generate raycasting output
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            x =  (2 * (i + 0.5) / (float)w - 1) * tan(fov/2.) * w / (float)h;
            y = -(2 * (j + 0.5) / (float)h - 1) * tan(fov/2.);

            Vector3 direction = Vector3(x, y, -1).normalize();

            framebuffer[i + j * w] = determinePixelColor(cameraLocation, direction, spheres, lights);
        }
    }
}

color Renderer::determinePixelColor(Vector3 origin, Vector3 direction, std::vector<Sphere> spheres, std::vector<LightSource> lights){
    color pixelColor = backgroundColor;
    double shortestDistance = std::numeric_limits<double>::max();

    color temporaryColor;
    double temporaryDistance = 0;
    bool temporaryIntersection = false;
    
    for(std::vector<Sphere>::iterator it = spheres.begin(); it != spheres.end(); it++){
        temporaryColor = (*it).pixelColor(origin, direction, backgroundColor, lights, &temporaryDistance, &temporaryIntersection);
        
        if(!temporaryIntersection)
            continue;

        else if(shortestDistance > temporaryDistance){
            shortestDistance = temporaryDistance;
            pixelColor = temporaryColor;
        }
    }

    return pixelColor;
}