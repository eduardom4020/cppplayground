#ifndef WEDGE_H
#define WEDGE_H

#include <iostream>
#include "../../operations/Operations.hpp"
#include "../../shapes/Line/Line.hpp"
#include "../Face/Face.hpp"

class Wedge : public Line
{
    public:
        Wedge* ccwPrev;
        Wedge* ccwNext;
        Wedge* cwPrev;
        Wedge* cwNext;

        Wedge(Point& _start, Point& _end);
        Wedge(Point& _start, Point& _end, Face& ccwFace, Face& cwFace);

        void setFccw(Face& ccwFace);
        void setFcw(Face& cwFace);

        Face* getFccw();
        Face* getFcw();

        std::string toTerminal();

    private:
        Face* Fccw;
        Face* Fcw;
};

#endif