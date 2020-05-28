#ifndef NSP_OP_H
#define NSP_OP_H

#include "../primitives/Point/Point.hpp"
#include "../primitives/Vector/Vector.hpp"

#include <math.h>
#include <type_traits>
#include <vector>
#include <algorithm> 

class Point;
class Vector;

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

    bool leftOf(const Vector& v1, const Vector& v2);
    Vector left(const Vector& v1, const Vector& v2);

    std::vector<Point *> sortPoints(std::vector<Point *> points, bool desc=true);
}

#endif