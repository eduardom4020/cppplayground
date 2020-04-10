#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Operations.hpp"

class Line
{
    public:
        Point* start;
        Point* end;
        double length;

        Line(Point& p_start, Point& p_end);

        std::string toString();
};

#endif