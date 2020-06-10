#include <iostream>
#include <fstream>
#include <map>

#include "./operations/PolygonalOperations.hpp"
#include "./object_components/Face/Face.hpp"
#include "./object_components/Wedge/Wedge.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "3D Hull Builder" << std::endl;

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
    std::ofstream convexHull;
    convexHull.open ("convex-hull.obj");

    std::vector<Face> hull = op::giftWrap3D(pointsCloud);

    for(auto* point : pointsCloud)
    {
      convexHull << "v " << point->x << " " << point->y << " " << point->z << "\n";
    }

    for(auto& face : hull)
    {
      convexHull << "vn " << face.normal.x << " " << face.normal.y << " " << face.normal.z << "\n";
    }

    for(int j=0; j < hull.size(); j++)
    {
      int p1Index = -1;
      int p2Index = -1;
      int p3Index = -1;

      for(int i=0; i < pointsCloud.size(); i++)
      {
        if(pointsCloud[i] == hull[j].points[0])
        {
          p1Index = i + 1;
        }

        if(pointsCloud[i] == hull[j].points[1])
        {
          p2Index = i + 1;
        }

        if(pointsCloud[i] == hull[j].points[2])
        {
          p3Index = i + 1;
        }
      }

      if(p1Index >= 0 && p2Index >= 0 && p3Index >= 0)
      {
        convexHull << "f " << p1Index << "//" << j + 1 << " " << p2Index << "//" << j + 1 << " " << p3Index << "//" << j + 1 << "\n";
      }
    }
    std::cout << "Hull size " << hull.size() << std::endl;
    convexHull.close();

    std::ofstream convexHullExport;
    convexHullExport.open ("convex-hull.hull");

    for(auto* point : pointsCloud)
    {
      convexHullExport << "p " << point->x << " " << point->y << " " << point->z << "\n";
    }

    convexHullExport << "hull" << "\n";
    for(auto& face : hull)
    {
      int p1Index = -1;
      int p2Index = -1;
      int p3Index = -1;

      for(int i=0; i < pointsCloud.size(); i++)
      {
        if(pointsCloud[i] == face.points[0])
        {
          p1Index = i + 1;
        }

        if(pointsCloud[i] == face.points[1])
        {
          p2Index = i + 1;
        }

        if(pointsCloud[i] == face.points[2])
        {
          p3Index = i + 1;
        }
      }

      if(p1Index >= 0 && p2Index >= 0 && p3Index >= 0)
      {
        convexHullExport << "f " << p1Index << " " << p2Index << " " << p3Index << "\n";
      }
    }

    convexHullExport.close();
  }
  catch(char const* exception)
  {
    std::cout << "ERROR!" << std::endl;
    std::cout << exception << std::endl;
  }
  
  return 0;
}