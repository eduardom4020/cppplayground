#include "./Face.hpp"

Face::Face(Point& p1, Point&p2, Point& p3) : Triangle(p1, p2, p3)
{
    Vector v1 = Vector(p1, p2);
    Vector v2 = Vector(p1, p3);

    crossRes = op::cross(v1, v2);
    normal = Normal(crossRes);
}

Point* Face::getLeastPoint(Point* start, Point* end)
{
    if(start == points[0] && end == points[1])
    {
        return points[2];
    }
    else if(start == points[1] && end == points[2])
    {
        return points[0];
    }
    else {
        return points[1];
    }
}

std::string Face::toString()
{
    std::string out = "[ ";
    out.append(points[0]->toString());
    out.append(" ");
    out.append(points[1]->toString());
    out.append(" ");
    out.append(points[2]->toString());
    out.append(" ]");
    return out;
}

Face Face::toCW()
{
    if(!this->isCW())
    {
        return Face(*points[1], *points[0], *points[2]);
    }

    return Face(*points[0], *points[1], *points[2]);
}

bool Face::isCW()
{
    Vector crossXY = op::cross(Vector(*points[0]), Vector(*points[1]));
    Vector crossYZ = op::cross(Vector(*points[1]), Vector(*points[2]));
    Vector crossZX = op::cross(Vector(*points[2]), Vector(*points[0]));

    Vector S = op::sum( op::sum(crossXY, crossYZ), crossZX );

    double dot = op::dot(S, normal);
    std::cout << "dot\t" << dot << std::endl;
    return dot > 0;
}

bool Face::operator==(Face& face)
{
    return ( points[0] == face.points[0] || points[0] == face.points[1] || points[0] == face.points[2] )
        && ( points[1] == face.points[0] || points[1] == face.points[1] || points[1] == face.points[2] )
        && ( points[2] == face.points[0] || points[2] == face.points[1] || points[2] == face.points[2] );
}