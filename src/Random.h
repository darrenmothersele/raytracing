//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_RANDOM_H
#define RAY0_RANDOM_H

#include <random>
#include "Vec3.h"

double dRan()
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_real_distribution<double> dist(0.0f, 1.0f);
    return dist(mt);
}

Vec3 randomInUnitSphere()
{
    Vec3 p;
    do
    {
        p = 2.0f * Vec3(dRan(), dRan(), dRan()) - Vec3(1,1,1);
    }
    while (dot(p,p) >= 1.0);
    return p;
}

Vec3 randomInUnitDisc()
{
    Vec3 p;
    do
    {
        p = 2.0f * Vec3(dRan(), dRan(), 0) - Vec3(1,1,0);
    }
    while (dot(p,p) >= 1.0);
    return p;
}

#endif //RAY0_RANDOM_H
