#ifndef NSP_POP_H
#define NSP_POP_H

#include "Operations.hpp"
#include "Line.hpp"
#include "Polygon.hpp"
#include "Triangle.hpp"

#include <math.h>
#include <type_traits>
#include <vector>

class Line;
class Polygon;
class Triangle;

namespace op
{
    bool intersect(Line& l1, Line& l2);
    std::vector<double> baricentricCoordnates(Point& point, Triangle& triangle);
    bool isInside(Point& point, Triangle& triangle);
}

#endif