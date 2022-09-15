#include "Light.h"

LightSource::LightSource(double x, double y, double z, double intensity){
    this->position.x = x;
    this->position.y = y;
    this->position.z = z;
    this->intensity = intensity;
}

LightSource::~LightSource(){

}

Vector3 LightSource::getPosition(){
    return position;
}

double LightSource::getIntensity(){
    return intensity;
}