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

Sphere::Sphere(Vector3 center, double R, color material){
    sphereCenter.x = center.x;
    sphereCenter.y = center.y;
    sphereCenter.z = center.z;
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

color Sphere::rayIntersect(Vector3 origin, Vector3 direction, color backgroundColor){
    // Calculate which point is the projection of the center
    // of the sphere onto the ray.
    Vector3 distanceVector = sphereCenter - origin - 
        ((Vector3::dotProduct(sphereCenter - origin, direction) /
         Vector3::dotProduct(direction, direction)) * direction);

    double distance = distanceVector.abs();

    if(std::abs(distance - r) < epsilon || distance < r)
        return materialColor;
    else 
        return backgroundColor;
}

color Sphere::pixelColor(Vector3 origin, Vector3 direction, color backgroundColor, std::vector<LightSource> lights, double* rayLength, bool* intersects){
    *intersects = false;
    
    // Calculate which point is the projection of the center of the sphere onto the ray.
    double dotCamera = Vector3::dotProduct(sphereCenter - origin, direction);

    // If the dot product is negative, the sphere is behind the camera.
    if(dotCamera < 0){
        *rayLength = -1;
        return backgroundColor;
    }

    Vector3 centerToProjected = (origin + (dotCamera / Vector3::dotProduct(direction, direction) * direction)) - sphereCenter;
    double distanceToProjection = centerToProjected.abs();

    if(distanceToProjection > r){
        *rayLength = -1;
        return backgroundColor;
    }

    double moduleToIntersection = sqrt(r * r - distanceToProjection * distanceToProjection);
    Vector3 intersectionPoint = sphereCenter + centerToProjected - moduleToIntersection * direction;

    *rayLength = (intersectionPoint - origin).abs();

    lightIntensity = 0;
    for(std::vector<LightSource>::iterator it = lights.begin(); it != lights.end(); ++it){
        Vector3 lightDirection = (*it).getPosition() - intersectionPoint;
        Vector3 normalVector = intersectionPoint - sphereCenter;

        lightIntensity += (*it).getIntensity() * std::max(0.0, cos(Vector3::angleBetweenVectors(lightDirection, normalVector)));
    }

    Vector3 returnedColor = materialColor * lightIntensity;
    *intersects = true;
    return returnedColor;
}