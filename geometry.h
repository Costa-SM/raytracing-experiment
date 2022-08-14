#include "vector3.h"

#ifndef GEOMETRY_H
#define GEOMETRY_H

// Sphere Declarations
class Sphere {
public:
    // Epsilon for differences between doubles
    double epsilon = 0.00001;

    // Constructors and Destructor
    Sphere();
    Sphere(double X, double Y, double Z, double R);
    ~Sphere();

    // Auxiliary functions
    double getRadius();

    int rayIntersect(Vector3 origin, Vector3 direction);
private:
    Vector3 sphereCenter;
    double r;
};

#endif