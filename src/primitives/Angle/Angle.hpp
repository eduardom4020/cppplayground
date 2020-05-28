#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>
#include "../../operations/Operations.hpp"

class Angle
{    
    public:
        Angle(const Vector& v);
        Angle(const Vector& v1, const Vector& v2);

        double value();
        double orientedValue();
        double pseudoValue();

    private:
        Vector _u = Vector(1.0, 0, 0);
        const Vector* _v1;
        const Vector* _v2;
};

#endif