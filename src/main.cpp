#include <iostream>
#include <map>

#include "./operations/PolygonalOperations.hpp"
#include "./shapes/Triangle/Triangle.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "Points Ordering" << std::endl;

  Point p1 = Point(2, 0, 0);
  Point p2 = Point(6, 0, 0);
  Point p3 = Point(4, 2, 0);
  Point p4 = Point(4, 1, 0);
  Point p5 = Point(0, 0, 0);
  Point p6 = Point(1, 4, 0);
  Point p7 = Point(3, 3, 0);
  Point p8 = Point(2, 6, 0);
  Point p9 = Point(4, 6, 0);
  Point p10 = Point(1, 1, 0);

  std::vector<Point *> points = { &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10 };
  std::vector<Point *> sortedPoints = op::sortPoints(points);

  for(auto const& point : sortedPoints)
  {
    std::cout << point->toString() << std::endl;
  }
  
  return 0;
}