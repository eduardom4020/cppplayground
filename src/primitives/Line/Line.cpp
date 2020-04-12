#include "./Line.hpp"

Line::Line(const Point& p_start, const Point& p_end)
{
    start = &p_start;
    end = &p_end;
    length = op::len( Vector(p_start, p_end) );
}

std::string Line::toString()
{
    std::string out = "\nLine Info:\n";
    out.append("\nStart\n");
    out.append(const_cast<Point *>(start)->toString());
    out.append("\nEnd\n");
    out.append(const_cast<Point *>(end)->toString());
    out.append("\n\nLength: \t");
    out.append(std::to_string(length));
    return out;
}

Vector Line::toVector()
{
    return Vector(*start, *end);
}