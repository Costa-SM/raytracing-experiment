#include "Vector3.h"

#ifndef LIGHT_H
#define LIGHT_H

class LightSource {
public:
    LightSource(double x, double y, double z, double intensity);
    LightSource(Vector3 lightPosition, double intensity);
    ~LightSource();
    Vector3 getPosition();
    double getIntensity();
private:
    Vector3 position;
    double intensity;
};

#endif