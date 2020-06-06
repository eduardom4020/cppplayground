#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "../../operations/Operations.hpp"

class Polygon
{    
    public:
        Polygon();
        Polygon(std::vector<Point *> _points);
        std::vector<Point *> points;

        double area();
        //TODO: Correct this, it is crashing because giftWrap deppends on it
        bool isCCW();

    private:
        
};

#endif