#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <map>

#include "Point.hpp"

class Vector
{    
    public:
        double x, y, z;

        Vector(const Point& p);
        Vector(const Point& start, const Point& end);
        Vector(double X, double Y, double Z);
        Vector(const std::map<std::string, double>& coords);

        std::string toString();

    private:
};

#endif