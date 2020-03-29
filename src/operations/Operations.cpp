#include "./Operations.hpp"

Vector op::sub(const Point& p1, const Point& p2)
{
    return Vector(p2, p1);
}

Vector op::sum(const Vector& v1, const Vector& v2)
{
    double x = v1.x + v2.x;
    double y = v1.y + v2.y;
    double z = v1.z + v2.z;

    return Vector(x, y, z);
}

Vector op::sub(const Vector& v1, const Vector& v2)
{
    double x = v1.x - v2.x;
    double y = v1.y - v2.y;
    double z = v1.z - v2.z;

    return Vector(x, y, z);
}

Vector op::mult(double lambda, const Vector& v)
{
    double x = lambda * v.x;
    double y = lambda * v.y;
    double z = lambda * v.z;

    return Vector(x, y, z);
}

double op::dot(const Vector& v1, const Vector& v2)
{
    double x = v1.x * v2.x;
    double y = v1.y * v2.y;
    double z = v1.z * v2.z;

    return x + y + z;
}

double op::sqrLen(const Vector& v)
{
    double x = pow(v.x, 2);
    double y = pow(v.y, 2);
    double z = pow(v.z, 2);

    return x + y + z;
}

double op::len(const Vector& v)
{
    double sqred_len = sqrLen(v);

    return sqrt(sqred_len);
}