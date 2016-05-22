//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_CAMERA_H
#define RAY0_CAMERA_H

#include "Ray.h"

class Camera
{
    Vec3 origin;
    Vec3 lowerLeftCorner;
    Vec3 horizontal;
    Vec3 vertical;

public:
    Camera() :
            origin{0.0, 0.0, 0.0},
            lowerLeftCorner{-2.0, -1.0, -1.0},
            horizontal{4.0, 0.0, 0.0},
            vertical{0.0, 2.0, 0.0}
    {}

    Ray getRay(float u, float v)
    {
        return Ray(origin, lowerLeftCorner + (u * horizontal) + (v * vertical) - origin);
    }
};

#endif //RAY0_CAMERA_H
