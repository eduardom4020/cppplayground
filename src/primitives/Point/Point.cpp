#include "./Point.hpp"

#include <iostream>
#include <map>

bool mapHasKey(const std::map<std::string, double>& map, std::string key) 
{ 
    return map.find(key) != map.end(); 
}

Point::Point() { x = 0; y = 0; z = 0; }

Point::Point(double X, double Y, double Z) { x = X; y = Y; z = Z; }

Point::Point(const std::map<std::string, double>& coords) 
{
    x = 0; y = 0; z = 0;
    
    if ( mapHasKey(coords, "x") ) {
        x = coords.at("x");
    }

    if ( mapHasKey(coords, "y") ) {
        y = coords.at("y");
    }

    if ( mapHasKey(coords, "z") ) {
        z = coords.at("z");
    }
}

std::string Point::toString()
{
    std::string out = "p( ";
    out.append(std::to_string(x));
    out.append(", ");
    out.append(std::to_string(y));
    out.append(", ");
    out.append(std::to_string(z));
    out.append(" )");
    return out;
}