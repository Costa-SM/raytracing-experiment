#include <cmath>
#include <iostream>

#ifndef VECTORS_H
#define VECTORS_H

// Vector3 Declarations
class Vector3 {
public:
    // Constructor and Destructor
    Vector3();
    Vector3(double X, double Y, double Z);
    ~Vector3();

    // Operation overloads
    Vector3 operator+(Vector3 otherVector);
    Vector3 operator-(Vector3 otherVector);
    Vector3 operator=(Vector3 otherVector);
    Vector3 operator*(double scalar);
    void operator()(double X, double Y, double Z);
    friend std::ostream& operator<<(std::ostream& out, Vector3& vector);
    
    // Auxiliary functions
    double abs();
    double dotProduct(Vector3 v1, Vector3 v2);
    Vector3 crossProduct(Vector3 v1, Vector3 v2);

    double x, y, z;

private:
    
};

/*
// Vector2 Declarations
class Vector2 {
public:
    // Constructor and Destructor
    Vector2(double X, double Y);
    Vector2(double module, double angle);
    ~Vector2();

    // Operation overloads

    // Auxiliary functions

private:
    double x, y;
};
*/



#endif