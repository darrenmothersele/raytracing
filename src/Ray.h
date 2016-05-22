//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_RAY_H
#define RAY0_RAY_H

#include "Vec3.h"
#include <glm/gtx/intersect.hpp>

class Ray
{
    Vec3 origin;
    Vec3 direction;

public:
    Ray() {}
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

    float hitSphere(const Vec3& center, float radius) const
    {
        Vec3 oc = origin - center;
        float a = dot(direction, direction);
        float b = 2.0 * dot(oc, direction);
        float c = dot(oc, oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
        {
            return -1.0;
        }
        return (-b - sqrt(discriminant)) / (2.0 * a);
    }
};

#endif //RAY0_RAY_H
