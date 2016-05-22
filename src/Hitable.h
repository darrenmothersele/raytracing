//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_HITABLE_H
#define RAY0_HITABLE_H

#include "Ray.h"

struct HitRecord
{
    float t;
    Vec3 p;
    Vec3 normal;
};

class Hitable
{
public:
    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const = 0;
};

#endif //RAY0_HITABLE_H
