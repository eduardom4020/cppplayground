#include <iostream>
#include <map>

#include "Operations.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "Lines Intersect?" << std::endl;

  Point p1 = Point(2, 0, 0);
  Point p2 = Point(6, 0, 0);
  Point p3 = Point(4, 2, 0);
  Point p4 = Point(4, -2, 0);

  Line l1 = Line(p1, p2);
  Line l2 = Line(p3, p4);

  std::string res = op::intersect(l1, l2) ? "Yes!" : "No...";

  std::cout << res << std::endl;
  
  getchar();
  return 0;
}