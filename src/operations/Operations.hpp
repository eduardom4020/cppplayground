#ifndef NSP_OP_H
#define NSP_OP_H

#include "Point.hpp"
#include "Vector.hpp"

#include <math.h>
#include <type_traits>

namespace op
{
    // Point only operations
    Vector sub(const Point& p1, const Point& p2);
    double dist(const Point& p1, const Point& p2);

    // Vector only operations
    Vector sum(const Vector& v1, const Vector& v2);
    Vector sub(const Vector& v1, const Vector& v2);
    Vector mult(double lambda, const Vector& v);
    
    double dot(const Vector& v1, const Vector& v2);
    double sqrLen(const Vector& v);
    double len(const Vector& v);

    Vector cross(const Vector& v1, const Vector& v2);
    double crossR2(const Vector& v1, const Vector& v2);
    // double crossXY(const Vector& v1, const Vector& v2);
    // double crossXZ(const Vector& v1, const Vector& v2);
    // double crossYZ(const Vector& v1, const Vector& v2);

    // const Vector& leftXY(const Vector& v1, const Vector& v2);
    // const Vector& leftXZ(const Vector& v1, const Vector& v2);
    // const Vector& leftYZ(const Vector& v1, const Vector& v2);

    template <typename T>
    T left(const Vector& v1, const Vector& v2);
}

#endif