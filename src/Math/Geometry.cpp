#include "Geometry.h"

// Sphere Definitions
Sphere::Sphere(){
    sphereCenter.x = 0;
    sphereCenter.y = 0;
    sphereCenter.z = 0;
    r = 0;
}

Sphere::Sphere(double X, double Y, double Z, double R){
    sphereCenter.x = X;
    sphereCenter.y = Y;
    sphereCenter.z = Z;
    r = R;
}

Sphere::~Sphere(){

}

double Sphere::getRadius(){
    return r;
}


/**
 * @brief Function to calculate how many intersections a given ray has
 * with the current sphere.
 * 
 * @param origin Origin point for the given ray.
 * @param direction Direction that the ray follows.
 * @return int 
 */
int Sphere::rayIntersect(Vector3 origin, Vector3 direction){
    // Calculate which point is the projection of the center
    // of the sphere onto the ray.
    Vector3 distanceVector = sphereCenter - origin - 
        ((Vector3::dotProduct(sphereCenter - origin, direction) /
         Vector3::dotProduct(direction, direction)) * direction);

    double distance = distanceVector.abs();

    if(std::abs(distance - r) < epsilon)
        return 1;
    else if(distance < r)
        return 2;
    else 
        return 0;
}