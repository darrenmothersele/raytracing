//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_CAMERA_H
#define RAY0_CAMERA_H

#include "Ray.h"
#include "Random.h"

class Camera
{
    Vec3 origin;
    Vec3 lowerLeftCorner;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 u, v, w;
    float lensRadius;

public:
    Camera(Vec3 cameraPos, Vec3 lookAt, Vec3 vUp, float vFov, float aspect, float aperture, float focusDist)
            : origin(cameraPos)
    {
        lensRadius = aperture / 2.0f;
        float theta = vFov * M_PI / 180.0;
        float halfHeight = tan(theta / 2.0);
        float halfWidth = aspect * halfHeight;
        w = unitVector(cameraPos - lookAt);
        u = unitVector(cross(vUp, w));
        v = cross(w, u);

        lowerLeftCorner = origin - (halfWidth * focusDist * u) - (halfHeight * focusDist * v) - (focusDist * w);
        horizontal = 2.0f * halfWidth * focusDist * u;
        vertical = 2.0f * halfHeight * focusDist * v;
    }

    Ray getRay(float s, float t)
    {
        Vec3 rd = lensRadius * randomInUnitDisc();
        Vec3 offset = (u * rd.x) + (v * rd.y);
        return Ray(origin + offset, lowerLeftCorner + (s * horizontal) + (t * vertical) - origin - offset);
    }
};

#endif //RAY0_CAMERA_H
