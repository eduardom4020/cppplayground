#ifndef FACE_H
#define FACE_H

#include <iostream>
#include "../../shapes/Triangle/Triangle.hpp"
#include "../../primitives/Normal/Normal.hpp"
#include "../../primitives/Vector/Vector.hpp"
#include "../../operations/Operations.hpp"

class Face : public Triangle
{    
    public:
        Normal normal;

        Face(Point& p1, Point&p2, Point& p3);

        Point* getLeastPoint(Point* start, Point* end);

        std::string toString();

        Face toCW();

        bool isCW();

        bool operator==(Face& face);

    private:
        Vector crossRes;
};

#endif