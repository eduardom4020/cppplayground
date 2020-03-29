#ifndef NSP_OP_H
#define NSP_OP_H

#include "../primitives/Point/Point.hpp"
#include "../primitives/Vector/Vector.hpp"

#include <math.h>

namespace op
{
    Vector sub(const Point& p1, const Point& p2);

    Vector sum(const Vector& v1, const Vector& v2);
    Vector sub(const Vector& v1, const Vector& v2);
    Vector mult(double lambda, const Vector& v);
    
    double dot(const Vector& v1, const Vector& v2);
    double sqrLen(const Vector& v);
    double len(const Vector& v);
}

#endif