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
    Camera(Vec3 cameraPos, Vec3 lookAt, Vec3 vUp, float vFov, float aspect) : origin(cameraPos)
    {
        float theta = vFov * M_PI / 180;
        float halfHeight = tan(theta / 2.0);
        float halfWidth = aspect * halfHeight;
        Vec3 w = unitVector(cameraPos - lookAt);
        Vec3 u = unitVector(cross(vUp, w));
        Vec3 v = cross(w, u);

        lowerLeftCorner = origin - (halfWidth * u) - (halfHeight * v) - w;
        horizontal = 2 * halfWidth * u;
        vertical = 2 * halfHeight * v;
    }

    Ray getRay(float u, float v)
    {
        return Ray(origin, lowerLeftCorner + (u * horizontal) + (v * vertical) - origin);
    }
};

#endif //RAY0_CAMERA_H
