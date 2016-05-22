//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_DIELECTRICMATERIAL_H
#define RAY0_DIELECTRICMATERIAL_H

#include "Material.h"

class DielectricMaterial : public Material
{
    float refIdx;

public:
    DielectricMaterial(float ri) : refIdx(ri) {}

    virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override
    {
        Vec3 outwardNormal;
        Vec3 reflected = reflect(rIn.getDirection(), rec.normal);
        float ni_over_nt;
        attenuation = Vec3(1.0, 1.0, 1.0);
        Vec3 refracted;
        float reflectProb;
        float cosine;
        if (dot(rIn.getDirection(), rec.normal) > 0)
        {
            outwardNormal = -rec.normal;
            ni_over_nt = refIdx;
            cosine = refIdx * dot(rIn.getDirection(), rec.normal) / rIn.getDirection().length();
        }
        else
        {
            outwardNormal = rec.normal;
            ni_over_nt = 1.0 / refIdx;
            cosine = -dot(rIn.getDirection(), rec.normal) / rIn.getDirection().length();
        }
        if (refract(rIn.getDirection(), outwardNormal, ni_over_nt, refracted))
        {
            reflectProb = schlick(cosine);
        }
        else
        {
            reflectProb = 1.0;
        }

        if (dRan() < reflectProb)
        {
            scattered = Ray(rec.p, refracted);
        }
        else
        {
            scattered = Ray(rec.p, reflected);
        }
        return true;
    }

    float schlick(float cosine) const
    {
        float r0 = (1 - refIdx) / (1 + refIdx);
        r0 = r0 * r0;
        return r0 + (1 - r0) * pow((1 - cosine), 5);
    }
};

#endif //RAY0_DIELECTRICMATERIAL_H
