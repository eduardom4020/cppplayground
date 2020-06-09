#include <iostream>
#include <map>

#include "./operations/PolygonalOperations.hpp"
#include "./object_components/Face/Face.hpp"
#include "./object_components/Wedge/Wedge.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "3D Hull Test" << std::endl;

  Point p0 = Point(0, 0, 0);
  Point p1 = Point(-1, 0, 0);
  Point p2 = Point(0, -1, 0);
  Point p3 = Point(0, 1, 0);
  Point p4 = Point(0, 0, 1);
  Point p5 = Point(0, 0, -1);
  Point p6 = Point(1, 0, 0);

  std::vector<Point *> pointsCloud = { &p0, &p1, &p2, &p3, &p4, &p5, &p6 };

  try
  {
    std::vector<Face> hull = op::giftWrap3D(pointsCloud);
    for(auto& face : hull)
    {
      std::cout << face.toString() << std::endl;
    }
    std::cout << "Hull size " << hull.size() << std::endl;
  }
  catch(char const* exception)
  {
    std::cout << "ERROR!" << std::endl;
    std::cout << exception << std::endl;
  }
  
  return 0;
}