//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_RAY_H
#define RAY0_RAY_H

#include "Vec3.h"

class Ray
{
    Vec3 origin;
    Vec3 direction;

public:
    Ray(const Vec3& a, const Vec3& b)
    {
        origin = a;
        direction = b;
    }
    Vec3 getOrigin() const { return origin; }
    Vec3 getDirection() const { return direction; }

    // "point at parameter"
    Vec3 p(float t) const
    {
        return origin + t * direction;
    }
};

#endif //RAY0_RAY_H
