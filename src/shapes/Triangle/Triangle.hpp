#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "../Polygon/Polygon.hpp"

class Triangle : public Polygon
{    
    public:
        Triangle(Point& p1, Point&p2, Point& p3);

        Point* operator[](int index);

        Point center;
        
    private:
        
};

#endif