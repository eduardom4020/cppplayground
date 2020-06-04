#ifndef NORMAL_H
#define NORMAL_H

#include <iostream>
#include <map>

#include "../Vector/Vector.hpp"
#include "../../operations/Operations.hpp"

class Normal : public Vector
{    
    public:
        Normal();
        Normal(Vector& v);

    private:
};

#endif