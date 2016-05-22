//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_DIFFUSEMATERIAL_H
#define RAY0_DIFFUSEMATERIAL_H

#include "Material.h"
#include "Random.h"

class DiffuseMaterial : public Material
{
    Vec3 albedo;

public:
    DiffuseMaterial(const Vec3& a) : albedo(a) {}
    virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override
    {
        Vec3 target = rec.p + rec.normal + randomInUnitSphere();
        scattered = Ray(rec.p, target - rec.p);
        attenuation = albedo;
        return true;
    }
};

#endif //RAY0_DIFFUSEMATERIAL_H
