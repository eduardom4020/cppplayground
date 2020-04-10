#include <iostream>
#include <map>

#include "Operations.hpp"
#include "Line.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "Line" << std::endl;

  Point p1 = Point(2, 0, 0);
  Point p2 = Point(6, 0, 0);

  Line l1 = Line(p1, p2);

  std::cout << l1.toString() << std::endl;
  
  getchar();
  return 0;
}