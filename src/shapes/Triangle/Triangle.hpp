#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Polygon.hpp"

class Triangle : public Polygon
{    
    public:
        Triangle(Point& p1, Point&p2, Point& p3);

        // double area();
        // bool isCCW();
        
    private:
        
};

#endif