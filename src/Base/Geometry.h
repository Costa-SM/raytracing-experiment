#include "Vector3.h"
#include "Colors.h"

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
     * @return int 
     */
    int rayIntersect(Vector3 origin, Vector3 direction);
private:
    Vector3 sphereCenter;
    color materialColor;
    double r;
};

#endif