# My first makefile

all: geo_mod

geo_mod: main.o vector.o point.o operations.o angle.o line.o
	g++ -std=c++1y -o ../build/geo_mod ../build/compiled/main.o ../build/compiled/vector.o ../build/compiled/point.o ../build/compiled/operations.o ../build/compiled/line.o

main.o: vector.o point.o operations.o angle.o line.o
	g++ -std=c++1y -o ../build/compiled/main.o -I./operations -I./primitives/Point -I./primitives/Vector -I./primitives/Line -c ./main.cpp

vector.o: point.o
	g++ -std=c++1y -o ../build/compiled/vector.o -I./primitives/Point -c ./primitives/Vector/Vector.cpp

point.o:
	g++ -std=c++1y -o ../build/compiled/point.o -c ./primitives/Point/Point.cpp

angle.o: operations.o
	g++ -std=c++1y -o ../build/compiled/angle.o -I./operations -I./primitives/Point -I./primitives/Vector -c ./primitives/Angle/Angle.cpp

line.o: operations.o angle.o
	g++ -std=c++1y -o ../build/compiled/line.o -I./operations -I./primitives/Point -I./primitives/Vector -c ./primitives/Line/Line.cpp

operations.o: point.o vector.o
	g++ -std=c++1y -o ../build/compiled/operations.o -I./primitives/Point -I./primitives/Vector -c ./operations/Operations.cpp

clean:
	rm -rf *.o *~ geo_mod