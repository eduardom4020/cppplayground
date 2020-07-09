#include "./Triangle.hpp"

Triangle::Triangle(Point& p1, Point&p2, Point& p3)
{
    points.push_back(&p1);
    points.push_back(&p2);
    points.push_back(&p3);

    center = Point
    (
        (p1.x + p2.x + p3.x) / 3,
        (p1.y + p2.y + p3.y) / 3,
        (p1.z + p2.z + p3.z) / 3
    );
}

Point* Triangle::operator[](int index)
{
    return points[index];
}