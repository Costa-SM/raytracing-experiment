#include <vector>
#include <limits>

#include "Vector3.h"
#include "Colors.h"
#include "Light.h"

#ifndef GEOMETRY_H
#define GEOMETRY_H

// Sphere Declarations
class Sphere {
public:
    // Epsilon for differences between doubles
    double epsilon = 0.00001;

    // Constructors and Destructor
    Sphere();
    Sphere(double X, double Y, double Z, double R, color material);
    Sphere(Vector3 center, double R, color material);
    ~Sphere();

    // Auxiliary functions
    Vector3 getCenter();
    double getRadius();
    color getMaterial();

    /**
     * @brief Function to calculate how many intersections a given ray has
     * with the current sphere.
     * 
     * @param origin Origin point for the given ray.
     * @param direction Direction that the ray follows.
     * @param backgroundColor Color of the image background.
     * @return color 
     */
    color rayIntersect(Vector3 origin, Vector3 direction, color backgroundColor);

    /**
     * @brief Function to determine what is the color of the current point in
     * space.
     * 
     * @param origin Origin point for the given ray.
     * @param direction Direction that the ray follows.
     * @param lights Vector containing the existing light sources.
     * @return color 
     */
    color pixelColor(Vector3 origin, Vector3 direction, color backgroundColor, std::vector<LightSource> lights, double* rayLength, bool* intersects);
private:
    Vector3 sphereCenter;
    color materialColor;
    double r;
    double lightIntensity;
};

#endif