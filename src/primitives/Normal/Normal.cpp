#include "./Normal.hpp"

Normal::Normal() : Vector()
{
}

Normal::Normal(Vector& v) : Vector(v.x, v.y, v.z)
{
    double len = op::len((const Vector&) v);

    x /= len;
    y /= len;
    z /= len;
}