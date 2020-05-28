#include "./Polygon.hpp"

Polygon::Polygon()
{
}

Polygon::Polygon(std::vector<Point *> _points)
{
    points = _points;
}

double Polygon::area()
{
    double double_area = 0;
    std::vector<Point *>::size_type i;

    for (i=0; i < points.size() - 1; i++)
        double_area += op::crossR2(*points[i], *points[i + 1]);
    
    double_area += op::crossR2(*points[i], *points[0]);

    return double_area / 2;
}

bool Polygon::isCCW()
{
    double area_res = this->area();
    return area_res >= 0;
}