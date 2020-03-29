#include "./Vector.hpp"

Vector::Vector(const Point& p)
{
    x = p.x; y = p.y; z = p.z;
}

Vector::Vector(const Point& start, const Point& end)
{
    x = end.x - start.x;
    y = end.y - start.y;
    z = end.z - start.z;
}

Vector::Vector(double X, double Y, double Z)
{
    x = X; y = Y; z = Z;
}

Vector::Vector(const std::map<std::string, double>& coords)
{
    Point p = Point(coords);

    x = p.x; y = p.y; z = p.z;
}

std::string Vector::toString()
{
    std::string out = "\nVector Info:\n";
    out.append("\tx: "); out.append(std::to_string(x)); out.append("\n");
    out.append("\ty: "); out.append(std::to_string(y)); out.append("\n");
    out.append("\tz: "); out.append(std::to_string(z)); out.append("\n");
    return out;
}