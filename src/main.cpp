#include <iostream>
#include <map>

#include "./operations/Operations.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "Testing Points!" << std::endl;

  Point point1 = Point();
  Point point2 = Point(1.0,2.0,3.0);

  std::map<std::string, double> xyMap = {
    {"x", 1.0},
    {"y", 2.0}
  };

  std::map<std::string, double> xzMap = {
    {"x", 1.0},
    {"z", 2.0}
  };

  std::map<std::string, double> yzMap = {
    {"z", 1.0},
    {"y", 2.0}
  };

  Point point3 = Point(xyMap);
  Point point4 = Point(xzMap);
  Point point5 = Point(yzMap);

  std::cout << point1.toString() << point2.toString() << point3.toString() << point4.toString() << point5.toString() << std::endl;

  std::cout << "Testing Operations!" << std::endl;
  
  Vector v1 = op::sub(point5, point3);
  Vector v2 = op::sub(point2, point4);
  Vector v3 = op::sum(v1, v2);
  Vector v4 = op::sub(v1, v2);
  Vector v5 = op::mult(3, v4);
  double dot = op::dot(v3, v4);
  double len = op::len(v5);

  std::cout << "point5 - point3" << v1.toString() << std::endl;
  std::cout << "point2 - point4" << v2.toString() << std::endl;
  std::cout << "v1 + v2" << v3.toString() << std::endl;
  std::cout << "v1 - v2" << v4.toString() << std::endl;
  std::cout << "3 * v4" << v5.toString() << std::endl;
  std::cout << "dot v3 v4  " << std::to_string(dot) << std::endl;
  std::cout << "len v5  " << std::to_string(len) << std::endl;

  getchar();
  return 0;
}