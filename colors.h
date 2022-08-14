#include "vector3.h"

#ifndef RENDERER_COLORS_H
#define RENDERER_COLORS_H
using color = Vector3;

class Colors{
public:
    static color Red();
    static color Green();
    static color Blue();

    static color Black();
    static color White();

    static color Gray();
    static color LightGray();

    static color Cyan();
};

#endif