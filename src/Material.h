//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_MATERIAL_H
#define RAY0_MATERIAL_H

#include "Ray.h"

class Material
{
public:
    virtual bool scatter(const Ray& rIn, const HitRecord& reec, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif //RAY0_MATERIAL_H
