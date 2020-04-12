#include "./Operations.hpp"

Vector op::sub(const Point& p1, const Point& p2)
{
    return Vector(p2, p1);
}

double op::dist(const Point& p1, const Point& p2)
{
    return op::len(op::sub(p1, p2));
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

Vector op::cross(const Vector& v1, const Vector& v2)
{
    double x = v1.y * v2.z - v1.z * v2.y;
    double y = v1.z * v2.x - v1.x * v2.z;
    double z = v1.x * v2.y - v1.y * v2.x;

    return Vector(x, y, z);
}

double op::crossR2(const Vector& v1, const Vector& v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

bool op::leftOf(const Vector& v1, const Vector& v2)
{
    double cross_res = op::crossR2(v2, v1);
    return cross_res >= 0;
}

Vector op::left(const Vector& v1, const Vector& v2)
{
    double cross_res = op::crossR2(v2, v1);
    return cross_res >= 0 ? v1 : v2;
}

bool op::intersect(Line& l1, Line& l2)
{
    Vector l1_base = l1.toVector();
    Vector l1_lower = Vector(*l1.start, *l2.start);
    Vector l1_upper = Vector(*l1.start, *l2.end);

    double l1_base_lower = op::crossR2(l1_base, l1_lower);
    double l1_base_upper = op::crossR2(l1_base, l1_upper);

    Vector l2_base = l2.toVector();
    Vector l2_lower = Vector(*l2.start, *l1.start);
    Vector l2_upper = Vector(*l2.start, *l1.end);

    double l2_base_lower = op::crossR2(l2_base, l2_lower);
    double l2_base_upper = op::crossR2(l2_base, l2_upper);

    bool l1_ok = l1_base_lower * l1_base_upper < 0;
    bool l2_ok = l2_base_lower * l2_base_upper < 0;

    return l1_ok && l2_ok;
}