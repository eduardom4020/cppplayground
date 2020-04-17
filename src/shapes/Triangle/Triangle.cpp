#include "./Triangle.hpp"

Triangle::Triangle(Point& p1, Point&p2, Point& p3)
{
    points.push_back(&p1);
    points.push_back(&p2);
    points.push_back(&p3);
}