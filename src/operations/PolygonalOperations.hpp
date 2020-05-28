#ifndef NSP_POP_H
#define NSP_POP_H

#include "./Operations.hpp"
#include "../shapes/Line/Line.hpp"
#include "../shapes/Polygon/Polygon.hpp"
#include "../shapes/Triangle/Triangle.hpp"

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

    Polygon giftWrap3D(std::vector<Point *> points);
}

#endif