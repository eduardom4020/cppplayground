#include "./Angle.hpp"

#include <iostream>
#include <math.h>

Angle::Angle(const Vector& v)
{
    _v1 = &v;
    _v2 = &_u;
}

Angle::Angle(const Vector& v1, const Vector& v2)
{
    _v1 = &v1;
    _v2 = &v2;
}

double calcCos(const Vector& v1, const Vector& v2)
{
    double dot = op::dot(v1, v2);
    double lenV1 = op::len(v1);
    double lenV2 = op::len(v2);

    return dot / ( lenV1 * lenV2 );
}

double calcAngle(const Vector& v1, const Vector& v2)
{
    double Cos = calcCos(v1, v2);
    double angle = acos( Cos );
    return angle;
}

double Angle::value()
{
    return calcAngle(*_v1, *_v2);
}

double Angle::orientedValue()
{
    double angleV1 = _v1->y >= 0 ? calcAngle(_u, *_v1) : 2 * 3.1415 - calcAngle(_u, *_v1);
    double angleV2 = _v2->y >= 0 ? calcAngle(_u, *_v2) : 2 * 3.1415 - calcAngle(_u, *_v2);

    return angleV1 - angleV2;
}

double Angle::pseudoValue()
{
    double Cos = calcCos(*_v1, *_v2);
    return 1 - Cos;
}