#include <iostream>
#include <fstream>
#include <map>

#include "./operations/PolygonalOperations.hpp"
#include "./object_components/Face/Face.hpp"
#include "./object_components/Wedge/Wedge.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "3D Hull Builder" << std::endl;
  
  Point p1Grass = Point(3.618037, -0.811649, 2.667051);
  Point p2Grass = Point(-1.381940, -0.811650, 4.291671);
  Point p3Grass = Point(-4.472131, -0.811645, 0.038424);
  Point p4Grass = Point(-1.381940, -0.811650, -4.214822);
  Point p5Grass = Point(3.618037, -0.811649, -2.590202);
  Point p6Grass = Point(1.381940, 0.082790, 4.291671);
  Point p7Grass = Point(-3.618037, 0.082790, 2.667051);
  Point p8Grass = Point(-3.408270, -0.093344, -2.256607);
  Point p9Grass = Point(1.381940, 0.082790, -4.214822);
  Point p10Grass = Point(4.472131, 0.082786, 0.038424);
  Point p11Grass = Point(0.000000, 0.400925, 0.038424);
  Point p12Grass = Point(0.000010, -0.850908, 0.038424);
  Point p13Grass = Point(1.314344, -0.890167, 4.083483);
  Point p14Grass = Point(4.253239, -0.890166, 0.038424);
  Point p15Grass = Point(-3.440947, -0.890166, 2.538409);
  Point p16Grass = Point(-3.440947, -0.890166, -2.461560);
  Point p17Grass = Point(1.314344, -0.890167, -4.006634);
  Point p18Grass = Point(4.755289, -0.364430, 1.583488);
  Point p19Grass = Point(4.755289, -0.364430, -1.506639);
  Point p20Grass = Point(0.000000, -0.364430, 5.038424);
  Point p21Grass = Point(2.938928, -0.364430, 4.083508);
  Point p22Grass = Point(-4.755289, -0.364430, 1.583488);
  Point p23Grass = Point(-2.938928, -0.364430, 4.083508);
  Point p24Grass = Point(-2.938928, -0.364430, -4.006659);
  Point p25Grass = Point(-4.755289, -0.364430, -1.506639);
  Point p26Grass = Point(2.938928, -0.364430, -4.006659);
  Point p27Grass = Point(0.000000, -0.364430, -4.961575);
  Point p28Grass = Point(3.440947, 0.161307, 2.538409);
  Point p29Grass = Point(-1.314344, 0.161308, 4.083483);
  Point p30Grass = Point(-4.253239, 0.161306, 0.038424);
  Point p31Grass = Point(-1.104578, -0.014826, -3.673039);
  Point p32Grass = Point(3.440947, 0.161307, -2.461560);
  Point p33Grass = Point(0.812278, 0.251579, 2.538401);
  Point p34Grass = Point(2.628649, 0.251576, 0.038424);
  Point p35Grass = Point(-2.126613, 0.251579, 1.583482);
  Point p36Grass = Point(-2.126613, 0.251579, -1.506633);
  Point p37Grass = Point(0.812278, 0.251579, -2.461552);

  Point p38Grass = Point(1.5, -0.6, 0.5);
  Point p39Grass = Point(2, -0.5, -0.3);
  Point p40Grass = Point(2.5, -0.4, -0.8);
  Point p41Grass = Point(2.5, -0.3, 0.25);
  Point p42Grass = Point(-2.1, -0.12, 0.15);
  Point p43Grass = Point(1.8, 0.2, 0.3);
  Point p44Grass = Point(0.8, 0.25, -0.3);
  Point p45Grass = Point(-0.8, 0.25, -0.3);

  std::vector<Point *> pointsCloudGrass = { &p1Grass, &p2Grass, &p3Grass, &p4Grass, &p5Grass, &p6Grass, &p7Grass, &p8Grass, &p9Grass, &p10Grass, &p11Grass, &p12Grass, &p13Grass, &p14Grass, &p15Grass, &p16Grass, &p17Grass, &p18Grass, &p19Grass, &p20Grass, &p21Grass, &p22Grass, &p23Grass, &p24Grass, &p25Grass, &p26Grass, &p27Grass, &p28Grass, &p29Grass, &p30Grass, &p31Grass, &p32Grass, &p33Grass, &p34Grass, &p35Grass, &p36Grass, &p37Grass, &p38Grass, &p39Grass, &p40Grass, &p41Grass, &p42Grass, &p43Grass, &p44Grass, &p45Grass };

  Point p1Ground1 = Point( 3.618037, -0.811649, 2.667051);
  Point p2Ground1 = Point( -1.381940, -0.811650, 4.291671);
  Point p3Ground1 = Point( -4.472131, -0.811645, 0.038424);
  Point p4Ground1 = Point( -1.381940, -0.811650, -4.214822);
  Point p5Ground1 = Point( 3.618037, -0.811649, -2.590202);
  Point p6Ground1 = Point( -0.812278, -1.340042, 2.538401);
  Point p7Ground1 = Point( 2.126613, -1.340042, 1.583482);
  Point p8Ground1 = Point( 1.314344, -0.890167, 4.083483);
  Point p9Ground1 = Point( 4.253239, -0.890166, 0.038424);
  Point p10Ground1 = Point( 2.126613, -1.340042, -1.506633);
  Point p11Ground1 = Point( -2.880342, -1.545828, 0.086705);
  Point p12Ground1 = Point( -3.440947, -0.890166, 2.538409);
  Point p13Ground1 = Point( -0.812278, -1.340042, -2.461552);
  Point p14Ground1 = Point( -3.440947, -0.890166, -2.461560);
  Point p15Ground1 = Point( 1.314344, -0.890167, -4.006634);
  Point p16Ground1 = Point( 0.000010, -0.850908, 0.038424);
  Point p17Ground1 = Point( -0.050334, -1.664167, 0.048081);

  std::vector<Point *> pointsCloudGround1 = { &p1Ground1, &p2Ground1, &p3Ground1, &p4Ground1, &p5Ground1, &p6Ground1, &p7Ground1, &p8Ground1, &p9Ground1, &p10Ground1, &p11Ground1, &p12Ground1, &p13Ground1, &p14Ground1, &p15Ground1, &p16Ground1, &p17Ground1 };

  Point p1Ground2 = Point( -0.812278, -1.340042, 2.538401);
  Point p2Ground2 = Point( 2.126613, -1.340042, 1.583482);
  Point p3Ground2 = Point( 2.126613, -1.340042, -1.506633);
  Point p4Ground2 = Point( -2.880342, -1.545828, 0.086705);
  Point p5Ground2 = Point( -0.812278, -1.340042, -2.461552);
  Point p6Ground2 = Point( -0.184044, -2.099248, -0.095292);
  Point p7Ground2 = Point( -0.571939, -1.549898, 1.798705);
  Point p8Ground2 = Point( 1.497389, -1.549898, 1.126328);
  Point p9Ground2 = Point( 1.497389, -1.549898, -1.049479);
  Point p10Ground2 = Point( -1.613129, -2.018053, -0.095292);
  Point p11Ground2 = Point( -0.625645, -2.018055, -1.454423);
  Point p12Ground2 = Point( -0.050334, -1.381199, 0.048081);

  std::vector<Point *> pointsCloudGround2 = { &p1Ground2, &p2Ground2, &p3Ground2, &p4Ground2, &p5Ground2, &p6Ground2, &p7Ground2, &p8Ground2, &p9Ground2, &p10Ground2, &p11Ground2, &p12Ground2 };

  Point p1Tree1 = Point( 1.517735, 0.220221, -1.074792);
  Point p2Tree1 = Point( 1.786887, 0.220221, -0.229786);
  Point p3Tree1 = Point( 0.941881, 0.220221, 0.039366);
  Point p4Tree1 = Point( 0.672729, 0.220221, -0.805640);
  Point p5Tree1 = Point( 1.405453, 0.699503, -0.857550);
  Point p6Tree1 = Point( 1.569644, 0.699503, -0.342068);
  Point p7Tree1 = Point( 1.054163, 0.699503, -0.177876);
  Point p8Tree1 = Point( 0.889971, 0.699503, -0.693358);
  Point p9Tree1 = Point( 1.229808, 0.699503, -0.517713);
  Point p10Tree1 = Point( 1.229808, 0.220221, -0.517713);

  std::vector<Point *> pointsCloudTree1 = { &p1Tree1, &p2Tree1, &p3Tree1, &p4Tree1, &p5Tree1, &p6Tree1, &p7Tree1, &p8Tree1, &p9Tree1, &p10Tree1 };

  Point p1Tree2 = Point( 1.229808, 0.699503, -0.517713);
  Point p2Tree2 = Point( 1.350316, 1.178786, -0.750871);
  Point p3Tree2 = Point( 1.462965, 1.178786, -0.397205);
  Point p4Tree2 = Point( 1.109300, 1.178786, -0.284555);
  Point p5Tree2 = Point( 0.996650, 1.178786, -0.638221);
  Point p6Tree2 = Point( 1.461490, 0.699503, -0.965970);
  Point p7Tree2 = Point( 1.678065, 0.699503, -0.286031);
  Point p8Tree2 = Point( 0.998126, 0.699503, -0.069456);
  Point p9Tree2 = Point( 0.781551, 0.699503, -0.749395);
  Point p10Tree2 = Point( 1.229808, 1.178786, -0.517713);

  std::vector<Point *> pointsCloudTree2 = { &p1Tree2, &p2Tree2, &p3Tree2, &p4Tree2, &p5Tree2, &p6Tree2, &p7Tree2, &p8Tree2, &p9Tree2, &p10Tree2 };

  Point p1Tree3 = Point( 1.229808, 1.178786, -0.517713);
  Point p2Tree3 = Point( 1.295178, 1.658069, -0.644192);
  Point p3Tree3 = Point( 1.356286, 1.658069, -0.452342);
  Point p4Tree3 = Point( 1.164437, 1.658069, -0.391234);
  Point p5Tree3 = Point( 1.103329, 1.658069, -0.583084);
  Point p6Tree3 = Point( 1.401124, 1.178786, -0.849175);
  Point p7Tree3 = Point( 1.561270, 1.178786, -0.346396);
  Point p8Tree3 = Point( 1.058491, 1.178786, -0.186251);
  Point p9Tree3 = Point( 0.898345, 1.178786, -0.689030);
  Point p10Tree3 = Point( 1.229808, 1.658069, -0.517713);

  std::vector<Point *> pointsCloudTree3 = { &p1Tree3, &p2Tree3, &p3Tree3, &p4Tree3, &p5Tree3, &p6Tree3, &p7Tree3, &p8Tree3, &p9Tree3, &p10Tree3 };

  Point p1Tree4 = Point( 1.317984, 1.618069, -0.688315);
  Point p2Tree4 = Point( 1.400410, 1.628069, -0.429537);
  Point p3Tree4 = Point( 1.141632, 1.638069, -0.347111);
  Point p4Tree4 = Point( 1.059206, 1.648069, -0.605889);
  Point p5Tree4 = Point( 1.229808, 1.658069, -0.517713);
  Point p6Tree4 = Point( 1.229808, 2.201551, -0.517713);

  std::vector<Point *> pointsCloudTree4 = { &p1Tree4, &p2Tree4, &p3Tree4, &p4Tree4, &p5Tree4, &p6Tree4 };

  Point p1WellSide1 = Point( -0.700901, 0.194623, -0.722902);
  Point p2WellSide1 = Point( -1.220517, 0.194623, -1.022902);
  Point p3WellSide1 = Point( -0.700901, 0.869623, -0.722902);
  Point p4WellSide1 = Point( -1.220517, 0.869623, -1.022902);
  Point p5WellSide1 = Point( -1.220517, 0.194623, -1.052902);
  Point p6WellSide1 = Point( -1.220517, 0.869623, -1.052902);
  Point p7WellSide1 = Point( -1.194536, 0.194623, -1.007902);
  Point p8WellSide1 = Point( -1.194536, 0.869623, -1.007902);
  Point p9WellSide1 = Point( -0.725583, 0.194623, -0.737152);
  Point p10WellSide1 = Point( -0.725583, 0.869623, -0.737152);
  Point p11WellSide1 = Point( -0.674921, 0.194623, -0.737902);
  Point p12WellSide1 = Point( -0.674921, 0.869623, -0.737902);

  try
  {
    std::vector<Face> hullGrass = op::giftWrap3D(pointsCloudGrass);
    std::vector<Face> hullGround1 = op::giftWrap3D(pointsCloudGround1);
    std::vector<Face> hullGround2 = op::giftWrap3D(pointsCloudGround2);

    std::vector<Face> hullTree1 = op::giftWrap3D(pointsCloudTree1);
    std::vector<Face> hullTree2 = op::giftWrap3D(pointsCloudTree2);
    std::vector<Face> hullTree3 = op::giftWrap3D(pointsCloudTree3);
    std::vector<Face> hullTree4 = op::giftWrap3D(pointsCloudTree4);

    std::ofstream convexHullExport;
    convexHullExport.open ("convex-hull.hull");

    std::vector<Point *> pointsCloud = {};
    pointsCloud.insert(pointsCloud.end(), pointsCloudGrass.begin(), pointsCloudGrass.end());
    pointsCloud.insert(pointsCloud.end(), pointsCloudGround1.begin(), pointsCloudGround1.end());
    pointsCloud.insert(pointsCloud.end(), pointsCloudGround2.begin(), pointsCloudGround2.end());
    pointsCloud.insert(pointsCloud.end(), pointsCloudTree1.begin(), pointsCloudTree1.end());
    pointsCloud.insert(pointsCloud.end(), pointsCloudTree2.begin(), pointsCloudTree2.end());
    pointsCloud.insert(pointsCloud.end(), pointsCloudTree3.begin(), pointsCloudTree3.end());
    pointsCloud.insert(pointsCloud.end(), pointsCloudTree4.begin(), pointsCloudTree4.end());

    for(auto* point : pointsCloud)
    {
      convexHullExport << "p " << point->x << " " << point->y << " " << point->z << "\n";
    }

    convexHullExport << "hull color #CFE781" << "\n";
    for(auto& face : hullGrass)
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

    convexHullExport << "hull color #E7CA94" << "\n";
    for(auto& face : hullGround1)
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

    convexHullExport << "hull color #E7CA94" << "\n";
    for(auto& face : hullGround2)
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

    convexHullExport << "hull color #81D4A1" << "\n";
    for(auto& face : hullTree1)
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

    convexHullExport << "hull color #81D4A1" << "\n";
    for(auto& face : hullTree2)
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

    convexHullExport << "hull color #81D4A1" << "\n";
    for(auto& face : hullTree3)
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

    convexHullExport << "hull color #81D4A1" << "\n";
    for(auto& face : hullTree4)
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