#include <iostream>
#include <map>

#include "Operations.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "Leftness" << std::endl;

  Vector v1 = Vector(5, 0, 0);
  Vector v2 = Vector(0, 3, 0);

  bool v1_left_of_v2 = op::leftOf(v1, v2);
  Vector v_left = op::left(v1, v2);

  std::string who_is_left = v1_left_of_v2 ? "V1 is at left of V2" : "V2 is at left of V1";

  std::cout << who_is_left << std::endl;
  std::cout << "The vector in left is " << v_left.toString() << std::endl;
  
  getchar();
  return 0;
}