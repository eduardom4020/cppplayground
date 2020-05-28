#include "./Face.hpp"

Face::Face(Point& p1, Point&p2, Point& p3) : Triangle(p1, p2, p3)
{
}

Point* Face::getLeastPoint(Point& start, Point& end)
{
    if(&start == points[0] && &end == points[1])
    {
        return points[2];
    }
    else if(&start == points[1] && &end == points[2])
    {
        return points[0];
    }
    else {
        return points[1];
    }
}