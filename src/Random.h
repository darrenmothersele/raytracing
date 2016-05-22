//
// Created by Darren Mothersele on 22/05/2016.
//

#ifndef RAY0_RANDOM_H
#define RAY0_RANDOM_H

#include <random>

double dRan()
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_real_distribution<double> dist(0.0f, 1.0f);
    return dist(mt);
}

#endif //RAY0_RANDOM_H
