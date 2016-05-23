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
    Camera(float vFov, float aspect)
    {
        float theta = vFov * M_PI / 180;
        float halfHeight = tan(theta / 2.0);
        float halfWidth = aspect * halfHeight;
        lowerLeftCorner = Vec3(-halfWidth, -halfHeight, -1.0);
        horizontal = Vec3(2 * halfWidth, 0.0, 0.0);
        vertical = Vec3(0.0, 2 * halfHeight, 0.0);
        origin = Vec3(0.0, 0.0, 0.0);
    }

    Ray getRay(float u, float v)
    {
        return Ray(origin, lowerLeftCorner + (u * horizontal) + (v * vertical) - origin);
    }
};

#endif //RAY0_CAMERA_H
