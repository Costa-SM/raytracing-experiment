#include "Light.h"

LightSource::LightSource(double x, double y, double z, double intensity){
    position.x = x;
    position.y = y;
    position.z = z;
    this->intensity = intensity;
}

LightSource::LightSource(Vector3 lightPosition, double intensity){
    position.x = lightPosition.x;
    position.y = lightPosition.y;
    position.z = lightPosition.z;
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