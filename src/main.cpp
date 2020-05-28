#include <iostream>
#include <map>

#include "./operations/PolygonalOperations.hpp"
#include "./object_components/Face/Face.hpp"
#include "./object_components/Wedge/Wedge.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "Wedge Test" << std::endl;

  Point p1 = Point(0, 0, 0);
  Point p2 = Point(0, 1, 0);
  Point p3 = Point(1, 0, 0);
  Point p4 = Point(-1, 0, 0);

  Face f1 = Face(p1, p2, p3);
  Face f2 = Face(p1, p4, p2);

  try
  {
    Wedge e1 = Wedge(p1, p2, f2, f1);
    std::cout << e1.toTerminal() << std::endl;
  }
  catch(char const* err)
  {
    std::cout << err << std::endl;
  }
  
  return 0;
}