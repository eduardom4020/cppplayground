#include <iostream>
#include <map>

#include "Operations.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "Cross products" << std::endl;

  Vector v1 = Vector(5, 0, 0);
  Vector v2 = Vector(0, 0, 3);

  Vector cross_v1_v2 = op::cross(v1, v2);

  std::cout << cross_v1_v2.toString() << std::endl;

  // Vector v = Vector(1, 0, 0);
  // std::cout << v.toString() << std::endl;
  
  getchar();
  return 0;
}