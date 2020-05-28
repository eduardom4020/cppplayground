#include "./Wedge.hpp"

Wedge::Wedge(Point& _start, Point& _end, Face& ccwFace, Face& cwFace) : Line(_start, _end)
{
    Point* leastCcwPoint = ccwFace.getLeastPoint(_start, _end);
    Face ccwFaceCandidate = Face(_start, _end, *leastCcwPoint);

    if(!ccwFaceCandidate.isCCW())
    {
        throw "ccwFace is not correct";
    }

    Point* leastCwPoint = cwFace.getLeastPoint(_start, _end);
    Face cwFaceCandidate = Face(_start, _end, *leastCwPoint);

    if(cwFaceCandidate.isCCW())
    {
        throw "cwFace is not correct";
    }

    Fccw = &ccwFace;
    Fcw = &cwFace;
}

std::string Wedge::toTerminal()
{
    Point* leastCcwPoint = Fccw->getLeastPoint(*start, *end);
    Point* leastCwPoint = Fcw->getLeastPoint(*start, *end);

    std::string out = "\t\t\t    ";
    out.append(end->toString());
    out.append("\t\t\t\t\t\t\n");
    out.append("\t\t\t\t /\t  |    \t   \\ \n");
    out.append(leastCcwPoint->toString());
    out.append("\t  |    \t   ");
    out.append(leastCwPoint->toString());
    out.append("\n\t\t\t\t \\\t  |    \t   / \n");
    out.append("\t\t\t    ");
    out.append(start->toString());
    return out;
}