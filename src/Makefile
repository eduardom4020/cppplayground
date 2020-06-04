# My first makefile

COMPILED_PATHS = ../build/compiled/main.o ../build/compiled/vector.o ../build/compiled/point.o ../build/compiled/operations.o ../build/compiled/line.o ../build/compiled/normal.o ../build/compiled/angle.o ../build/compiled/polygon.o ../build/compiled/triangle.o ../build/compiled/polygonal_operations.o ../build/compiled/face.o ../build/compiled/wedge.o

REQUISITES = main.o vector.o point.o operations.o normal.o angle.o line.o polygon.o triangle.o polygonal_operations.o face.o wedge.o

all: geo_c
	clear

geo_c: $(REQUISITES) main.o
	g++ -std=c++1y -o ../build/geo_c $(COMPILED_PATHS)

main.o: $(REQUISITES)
	g++ -std=c++1y -o ../build/compiled/main.o -c ./main.cpp

vector.o: point.o
	g++ -std=c++1y -o ../build/compiled/vector.o -c ./primitives/Vector/Vector.cpp

point.o:
	g++ -std=c++1y -o ../build/compiled/point.o -c ./primitives/Point/Point.cpp

operations.o: point.o vector.o
	g++ -std=c++1y -o ../build/compiled/operations.o -c ./operations/Operations.cpp

angle.o: operations.o
	g++ -std=c++1y -o ../build/compiled/angle.o -c ./primitives/Angle/Angle.cpp

normal.o: operations.o
	g++ -std=c++1y -o ../build/compiled/normal.o -c ./primitives/Normal/Normal.cpp

line.o: operations.o
	g++ -std=c++1y -o ../build/compiled/line.o -c ./shapes/Line/Line.cpp

polygon.o: operations.o
	g++ -std=c++1y -o ../build/compiled/polygon.o -c ./shapes/Polygon/Polygon.cpp

triangle.o: operations.o
	g++ -std=c++1y -o ../build/compiled/triangle.o -c ./shapes/Triangle/Triangle.cpp

polygonal_operations.o: operations.o polygon.o triangle.o
	g++ -std=c++1y -o ../build/compiled/polygonal_operations.o -c ./operations/PolygonalOperations.cpp

face.o: operations.o
	g++ -std=c++1y -o ../build/compiled/face.o -c ./object_components/Face/Face.cpp

wedge.o: operations.o
	g++ -std=c++1y -o ../build/compiled/wedge.o -c ./object_components/Wedge/Wedge.cpp

clean:
	rm -rf *.o *~ geo_mod