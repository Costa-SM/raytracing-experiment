#include <cmath>
#include <iostream>

#ifndef VECTOR3_H
#define VECTOR3_H

// Vector3 Declarations
class Vector3 {
public:
    // Constructor and Destructor
    Vector3();
    Vector3(double X, double Y, double Z);
    ~Vector3();

    // Operation overloads
    Vector3 operator+(const Vector3 otherVector);
    Vector3 operator-(const Vector3 otherVector);
    Vector3 operator*(const double scalar);
    Vector3 operator/(const double scalar);
    bool operator==(const Vector3 otherVector);
    bool operator!=(const Vector3 otherVector);
    void operator()(double X, double Y, double Z);
    friend std::ostream& operator<<(std::ostream& out, Vector3& vector);
    
    // Auxiliary functions
    double abs();
    Vector3 normalize();
    static double dotProduct(Vector3 v1, Vector3 v2);
    static double angleBetweenVectors(Vector3 v1, Vector3 v2);
    static Vector3 crossProduct(Vector3 v1, Vector3 v2);

    // Vector variables
    double x, y, z;
};

// Operator overload so that it works both ways
Vector3 operator*(const double scalar, Vector3& vector);

#endif
