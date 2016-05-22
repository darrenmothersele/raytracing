//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_SPHERE_H
#define RAY0_SPHERE_H

#include "Hitable.h"
#include "Material.h"

class Sphere : public Hitable
{
    Vec3 center;
    float radius;
    std::shared_ptr<Material> matPtr;

public:
    Sphere(Vec3 c, float r, std::shared_ptr<Material> m) : center(c), radius(r), matPtr(m) {};
    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;
};

bool Sphere::hit(const Ray &r, float tMin, float tMax, HitRecord &rec) const
{
    Vec3 oc = r.getOrigin() - center;
    float a = dot(r.getDirection(), r.getDirection());
    float b = dot(oc, r.getDirection());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;
    if (discriminant > 0)
    {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < tMax && temp > tMin)
        {
            rec.t = temp;
            rec.p = r.p(temp);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = matPtr;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < tMax && temp > tMin)
        {
            rec.t = temp;
            rec.p = r.p(temp);
            rec.normal = (rec.p - center) / radius;
            rec.mat_ptr = matPtr;
            return true;
        }
    }
    return false;
}

#endif //RAY0_SPHERE_H
