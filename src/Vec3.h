//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_VEC3_H
#define RAY0_VEC3_H

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

typedef glm::vec3 Vec3;

Vec3 unitVector(Vec3 v)
{
    return glm::normalize(v);
}

#endif //RAY0_VEC3_H
