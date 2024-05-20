#pragma once
#include <cmath>

inline bool NearEquals(double a, double b, double e = 0.000001)
{
    return std::abs(a - b) <= e;
}
