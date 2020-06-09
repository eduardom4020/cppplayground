#include "./Wedge.hpp"

Wedge::Wedge(Point& _start, Point& _end) : Line(_start, _end)
{
    Fcw = nullptr;
    Fccw = nullptr;

    ccwPrev = nullptr;
    ccwNext = nullptr;
    cwPrev = nullptr;
    cwNext = nullptr;
}

Wedge::Wedge(Point& _start, Point& _end, Face& cwFace) : Line(_start, _end)
{
    setFcw(cwFace);
    Fccw = nullptr;

    ccwPrev = nullptr;
    ccwNext = nullptr;
    cwPrev = nullptr;
    cwNext = nullptr;
}

Wedge::Wedge(Point& _start, Point& _end, Face& ccwFace, Face& cwFace) : Line(_start, _end)
{
    setFccw(ccwFace);
    setFcw(cwFace);

    ccwPrev = nullptr;
    ccwNext = nullptr;
    cwPrev = nullptr;
    cwNext = nullptr;
}

void Wedge::setFccw(Face& ccwFace)
{
    Point* leastCcwPoint = ccwFace.getLeastPoint(start, end);
    Face ccwFaceCandidate = Face(*start, *end, *leastCcwPoint);
    
    if(ccwFaceCandidate.isCW())
    {
        throw "ccwFace is not correct";
    }

    Fccw = &ccwFace;
}

Face* Wedge::getFccw()
{
    return Fccw;
}

void Wedge::setFcw(Face& cwFace)
{
    Point* leastCwPoint = cwFace.getLeastPoint(start, end);
    Face cwFaceCandidate = Face(*start, *end, *leastCwPoint);
    
    if(!cwFaceCandidate.isCW())
    {
        throw "cwFace is not correct";
    }

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

std::string Wedge::toString()
{
    std::string out = "e[ ";
    out.append(start->toString());
    out.append(", ");
    out.append(end->toString());
    out.append(" ]");
    return out;
}

bool Wedge::operator==(Wedge& edge)
{
    // std::cout << "start == edge.start " << (start == edge.start ? "true" : "false") << std::endl;
    // std::cout << "end == edge.end " << (end == edge.end ? "true" : "false") << std::endl;
    return (start == edge.start && end == edge.end) || (start == edge.end && end == edge.start);
}