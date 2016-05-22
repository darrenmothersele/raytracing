//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_HITABLELIST_H
#define RAY0_HITABLELIST_H

#include <vector>
#include "Hitable.h"

class HitableList : public Hitable
{
    std::vector<std::shared_ptr<Hitable>> items;

public:
    void addItem(std::shared_ptr<Hitable> item) { items.push_back(item); }
    int getListSize() { return items.size(); }

    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;
};


bool HitableList::hit(const Ray &r, float tMin, float tMax, HitRecord &rec) const
{
    HitRecord tempRec;
    bool hitAnything = false;
    double closestSoFar = tMax;
    for (auto i : items)
    {
        if (i->hit(r, tMin, closestSoFar, tempRec))
        {
            hitAnything = true;
            closestSoFar = tempRec.t;
            rec = tempRec;
        }
    }
    return hitAnything;
}

#endif //RAY0_HITABLELIST_H
