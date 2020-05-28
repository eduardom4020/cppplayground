#ifndef FACE_H
#define FACE_H

#include <iostream>
#include "../../shapes/Triangle/Triangle.hpp"

class Face : public Triangle
{    
    public:
        Face(Point& p1, Point&p2, Point& p3);

        Point* getLeastPoint(Point& start, Point& end);

    private:
        
};

#endif