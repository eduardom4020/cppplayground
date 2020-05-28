#ifndef WEDGE_H
#define WEDGE_H

#include <iostream>
#include "../../operations/Operations.hpp"
#include "../../shapes/Line/Line.hpp"
#include "../Face/Face.hpp"

class Wedge : public Line
{
    public:
        Face* Fccw;
        Face* Fcw;

        Wedge* ccwPrev;
        Wedge* ccwNext;
        Wedge* cwPrev;
        Wedge* cwNext;

        Wedge(Point& _start, Point& _end, Face& ccwFace, Face& cwFace);

        std::string toTerminal();
};

#endif