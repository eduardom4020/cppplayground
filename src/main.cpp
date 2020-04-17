#include <iostream>
#include <map>

#include "Operations.hpp"
#include "Triangle.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "Triangle Test!" << std::endl;

  Point p1 = Point(2, 0, 0);
  Point p2 = Point(6, 0, 0);
  Point p3 = Point(4, 2, 0);

  std::cout << "\n--------------------------\n" << std::endl;

  Triangle t1 = Triangle(p1, p2, p3);

  std::string area_t1 = std::to_string( t1.area() );
  std::string orientation_t1 = t1.isCCW() ? "Counter Clock Wise" : "Clock Wise";

  std::cout << "Area:\t" << area_t1 << "\n" << "Orientation:\t" << orientation_t1 << std::endl;

  std::cout << "\n--------------------------\n" << std::endl;

  Triangle t2 = Triangle(p1, p3, p2);

  std::string area_t2 = std::to_string( t2.area() );
  std::string orientation_t2 = t2.isCCW() ? "Counter Clock Wise" : "Clock Wise";

  std::cout << "Area:\t" << area_t2 << "\n" << "Orientation:\t" << orientation_t2 << std::endl;
  
  getchar();
  return 0;
}