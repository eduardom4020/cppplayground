#include "./Line.hpp"

Line::Line(const Point& p_start, const Point& p_end)
{
    start = const_cast<Point *>(&p_start);
    end = const_cast<Point *>(&p_end);
    length = op::len( Vector(p_start, p_end) );
}

std::string Line::toString()
{
    std::string out = "\nLine Info:\n";
    out.append("\nStart\n");
    out.append(start->toString());
    out.append("\nEnd\n");
    out.append(end->toString());
    out.append("\n\nLength: \t");
    out.append(std::to_string(length));
    return out;
}

Vector Line::toVector()
{
    return Vector(*start, *end);
}