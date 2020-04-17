# My first makefile

LIBS_PATHS = -I./operations -I./primitives/Point -I./primitives/Vector -I./primitives/Angle -I./shapes/Line -I./shapes/Polygon -I./shapes/Triangle

COMPILED_PATHS = ../build/compiled/main.o ../build/compiled/vector.o ../build/compiled/point.o ../build/compiled/operations.o ../build/compiled/line.o ../build/compiled/angle.o ../build/compiled/polygon.o ../build/compiled/triangle.o ../build/compiled/polygonal_operations.o

all: geo_c
	clear

geo_c: main.o vector.o point.o operations.o angle.o line.o polygon.o triangle.o polygonal_operations.o
	g++ -std=c++1y -o ../build/geo_c $(COMPILED_PATHS)

main.o: vector.o point.o operations.o angle.o line.o polygon.o triangle.o polygonal_operations.o
	g++ -std=c++1y -o ../build/compiled/main.o $(LIBS_PATHS) -c ./main.cpp

vector.o: point.o
	g++ -std=c++1y -o ../build/compiled/vector.o $(LIBS_PATHS) -c ./primitives/Vector/Vector.cpp

point.o:
	g++ -std=c++1y -o ../build/compiled/point.o $(LIBS_PATHS) -c ./primitives/Point/Point.cpp

operations.o: point.o vector.o
	g++ -std=c++1y -o ../build/compiled/operations.o $(LIBS_PATHS) -c ./operations/Operations.cpp

angle.o: operations.o
	g++ -std=c++1y -o ../build/compiled/angle.o $(LIBS_PATHS) -c ./primitives/Angle/Angle.cpp

line.o: operations.o
	g++ -std=c++1y -o ../build/compiled/line.o $(LIBS_PATHS) -c ./shapes/Line/Line.cpp

polygon.o: operations.o
	g++ -std=c++1y -o ../build/compiled/polygon.o $(LIBS_PATHS) -c ./shapes/Polygon/Polygon.cpp

triangle.o: operations.o
	g++ -std=c++1y -o ../build/compiled/triangle.o $(LIBS_PATHS) -c ./shapes/Triangle/Triangle.cpp

polygonal_operations.o: operations.o polygon.o triangle.o
	g++ -std=c++1y -o ../build/compiled/polygonal_operations.o $(LIBS_PATHS) -c ./operations/PolygonalOperations.cpp

clean:
	rm -rf *.o *~ geo_mod