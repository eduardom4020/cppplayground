#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "Operations.hpp"

class Polygon
{    
    public:
        std::vector<Point *> points;

        double area();
        bool isCCW();

    private:
        
};

#endif