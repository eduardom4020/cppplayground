#include <iostream>
#include <fstream>
#include <map>

#include "./operations/PolygonalOperations.hpp"
#include "./object_components/Face/Face.hpp"
#include "./object_components/Wedge/Wedge.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "3D Hull Builder" << std::endl;
  
  std::vector<Point> pointsCloud = {};

  std::vector<std::vector<Face>> hulls = {};

  for (int i = 1; i < argc; i++)
  {
    std::vector<Point> hullPoints = {};
    std::vector<Point*> hullPointsPointers = {};
    
    std::string assetsPath = "../assets/";
    std::string fileName = argv[i];
    std::string extension = ".points";

    std::string filePath = assetsPath + fileName + extension;

    std::cout << filePath << std::endl;

    std::ifstream infile(filePath);

    double x, y, z;

    while (infile >> x >> y >> z)
    {
      Point newPoint = Point(x, y, z);

      bool isPointNew = true;

      for(auto& point : hullPoints)
      {
        if(point == newPoint) isPointNew = false;
      }

      if(isPointNew) hullPoints.push_back(newPoint);  
    }

    for(auto& hullPoint : hullPoints)
    {
      bool isPointNew = true;

      for(int i=0; i < pointsCloud.size(); i++)
      {
        if(pointsCloud[i] == hullPoint) 
        {
          isPointNew = false;
          hullPointsPointers.push_back(&pointsCloud[i]);
        }
      }

      if(isPointNew)
      {
        pointsCloud.push_back(hullPoint);
        hullPointsPointers.push_back(&pointsCloud[pointsCloud.size() - 1]);
      }
    }

    std::vector<Face> hull = {};

    try
    {
      hull = op::giftWrap3D(hullPointsPointers);
    }
    catch(char const* exception)
    {
      std::cout << "ERROR!" << std::endl;
      std::cout << exception << std::endl;
      return 1;
    }

    hulls.push_back(hull);
  }

  std::ofstream convexHullExport;
  convexHullExport.open ("convex-hull.hull");

  std::ofstream convexHullExportObj;
  convexHullExportObj.open ("convex-hull.obj");

  for(auto& point : pointsCloud)
  {
    convexHullExport << "p " << point.x << " " << point.y << " " << point.z << "\n";
    convexHullExportObj << "v " << point.x << " " << point.y << " " << point.z << "\n";
  }

  for(auto& hull : hulls)
  {
    convexHullExport << "hull color #B8B8B8" << "\n";

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
        convexHullExportObj << "f " << p1Index << " " << p2Index << " " << p3Index << "\n";
      }
    }
  }

  convexHullExport.close();
  convexHullExportObj.close();
  
  return 0;
}