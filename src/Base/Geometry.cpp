#include "Geometry.h"

// Sphere Definitions
Sphere::Sphere(){
    sphereCenter.x = 0;
    sphereCenter.y = 0;
    sphereCenter.z = 0;
    r = 0;
    materialColor = Colors::White();
}

Sphere::Sphere(double X, double Y, double Z, double R, color material){
    sphereCenter.x = X;
    sphereCenter.y = Y;
    sphereCenter.z = Z;
    r = R;
    materialColor = material;
}

Sphere::~Sphere(){

}

Vector3 Sphere::getCenter(){
    return sphereCenter;
}

double Sphere::getRadius(){
    return r;
}

color Sphere::getMaterial(){
    return materialColor;
}

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