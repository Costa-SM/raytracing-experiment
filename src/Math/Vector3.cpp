#include "Vector3.h"

// Vector3 Definitions
Vector3::Vector3(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3::Vector3(double X, double Y, double Z){
    this->x = X;
    this->y = Y;
    this->z = Z;
}

Vector3::~Vector3(){

}

Vector3 Vector3::operator+(const Vector3 otherVector){
    return Vector3(x + otherVector.x, y + otherVector.y, z + otherVector.z);
}

Vector3 Vector3::operator-(const Vector3 otherVector){
    return Vector3(x - otherVector.x, y - otherVector.y, z - otherVector.z);
}

Vector3 Vector3::operator*(const double scalar){
    return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector3 operator*(const double scalar, Vector3& vector){
    return vector * scalar;
}

Vector3 Vector3::operator/(const double scalar){
    double m = this->abs();
    return Vector3(this->x / m, this->y / m, this->z / m);
}

void Vector3::operator()(double X, double Y, double Z){
    this->x = X;
    this->y = Y;
    this->z = Z;
}

std::ostream& operator<<(std::ostream& out, Vector3& vector){
    out << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")" << std::endl; 
    return out; 
}

double Vector3::abs(){
    return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalize(){
    return Vector3(x, y, z) / this->abs();
}

double Vector3::dotProduct(Vector3 v1, Vector3 v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3 Vector3::crossProduct(Vector3 v1, Vector3 v2){
    
    return Vector3();
}

