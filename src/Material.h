//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_MATERIAL_H
#define RAY0_MATERIAL_H

#include "Ray.h"


Vec3 reflect(const Vec3& v, const Vec3& n)
{
    return v - 2 * dot(v,n) * n;
}

bool refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted)
{
    Vec3 uv = unitVector(v);
    float dt = dot(uv, n);
    float discriminant = 1.0 - ni_over_nt * ni_over_nt * (1 - dt * dt);
    if (discriminant > 0)
    {
        refracted = ni_over_nt * (uv - n * dt) - (n * float(sqrt(discriminant)));
        return true;
    }
    return false;
}

class Material
{
public:
    virtual bool scatter(const Ray& rIn, const HitRecord& reec, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif //RAY0_MATERIAL_H
