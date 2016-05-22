//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_VEC3_H
#define RAY0_VEC3_H

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <string>

typedef glm::vec3 Vec3;

Vec3 unitVector(Vec3 v)
{
    return glm::normalize(v);
}

std::string toString(Vec3 v)
{
    return "[" + std::to_string(v.x) + "," + std::to_string(v.y) + "," + std::to_string(v.z) + "]";
}

#endif //RAY0_VEC3_H
