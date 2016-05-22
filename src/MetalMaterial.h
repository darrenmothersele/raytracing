//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_METALMATERIAL_H
#define RAY0_METALMATERIAL_H

#include "Material.h"
#include "Ray.h"


class MetalMaterial : public Material
{
    Vec3 albedo;
    float fuzz;

public:
    MetalMaterial(const Vec3& a, float f) : albedo(a)
    {
        if (f < 1) fuzz = f;
        else fuzz = 1;
    }
    virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override
    {
        Vec3 reflected = reflect(unitVector(rIn.getDirection()), rec.normal);
        scattered = Ray(rec.p, reflected + fuzz * randomInUnitSphere());
        attenuation = albedo;
        return (dot(scattered.getDirection(), rec.normal) > 0);
    }
};

#endif //RAY0_METALMATERIAL_H
