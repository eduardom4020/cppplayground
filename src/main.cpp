#include <iostream>
#include <map>

#include "PolygonalOperations.hpp"
#include "Triangle.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "Point Polygon" << std::endl;

  Point p1 = Point(2, 0, 0);
  Point p2 = Point(6, 0, 0);
  Point p3 = Point(4, 2, 0);

  Triangle t1 = Triangle(p1, p2, p3);

  Point p4 = Point(4, 1, 0);
  Point p5 = Point(0, 0, 0);

  std::string is_p4_inside_t1 = op::isInside(p4, t1) ? "p4 is inside Triangle p1 p2 p3" : "p4 is not inside Triangle p1 p2 p3";

  std::string is_p5_inside_t1 = op::isInside(p5, t1) ? "p5 is inside Triangle p1 p2 p3" : "p5 is not inside Triangle p1 p2 p3";

  std::cout << "\n\n" << is_p4_inside_t1 << "\n" << is_p5_inside_t1 << std::endl;
  
  getchar();
  return 0;
}