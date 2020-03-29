#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <map>

class Point
{    
    public:
        double x, y, z;

        Point();
        Point(double X, double Y, double Z);
        Point(const std::map<std::string, double>& coords);

        std::string toString();

    private:
        
};

#endif