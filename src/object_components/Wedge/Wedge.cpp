#include "./Wedge.hpp"

Wedge::Wedge(Point& _start, Point& _end) : Line(_start, _end)
{
}

Wedge::Wedge(Point& _start, Point& _end, Face& ccwFace, Face& cwFace) : Line(_start, _end)
{
    setFccw(ccwFace);
    setFcw(cwFace);
}

void Wedge::setFccw(Face& ccwFace)
{
    // Point* leastCcwPoint = ccwFace.getLeastPoint(start, end);
    // Face ccwFaceCandidate = Face(*start, *end, *leastCcwPoint);
    // std::cout << "ccwFaceCandidate\t\t" << ccwFaceCandidate.toString() << std::endl;
    // if(!ccwFaceCandidate.isCCW())
    // {
    //     throw "ccwFace is not correct";
    // }

    Fccw = &ccwFace;
}

Face* Wedge::getFccw()
{
    return Fccw;
}

void Wedge::setFcw(Face& cwFace)
{
    // Point* leastCwPoint = cwFace.getLeastPoint(start, end);
    // Face cwFaceCandidate = Face(*start, *end, *leastCwPoint);
    
    // if(cwFaceCandidate.isCCW())
    // {
    //     throw "cwFace is not correct";
    // }

    Fcw = &cwFace;
}

Face* Wedge::getFcw()
{
    return Fcw;
}

std::string Wedge::toTerminal()
{
    Point* leastCcwPoint = Fccw->getLeastPoint(start, end);
    Point* leastCwPoint = Fcw->getLeastPoint(start, end);

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