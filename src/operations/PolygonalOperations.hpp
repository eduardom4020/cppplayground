#ifndef NSP_POP_H
#define NSP_POP_H

#include <iostream>

#include "./Operations.hpp"
#include "../shapes/Line/Line.hpp"
#include "../shapes/Polygon/Polygon.hpp"
#include "../shapes/Triangle/Triangle.hpp"
#include "../object_components/Face/Face.hpp"
#include "../object_components/Wedge/Wedge.hpp"
#include "../primitives/Angle/Angle.hpp"

#include <cmath>
#include <math.h>
#include <type_traits>
#include <vector>
#include <algorithm>

namespace op
{
    bool intersect(Line& l1, Line& l2, std::string plane);
    bool intersect(Line line, Face face);
    bool intersect(Face f1, Face f2);
    std::vector<double> baricentricCoordnates(Point& point, Triangle& triangle);
    bool isInside(Point& point, Triangle& triangle);

    std::vector<Face> giftWrap3D(std::vector<Point *> points);
    bool equal(Wedge& e1, Wedge& e2);

    std::vector<Face> frontierAdvance3D(std::vector<Point *> points);
    double dist(Point point, Face face);
    bool isVertexOfFace(Point* point, Face face);
}

#endif