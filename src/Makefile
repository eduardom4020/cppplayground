# My first makefile

all: geo_mod

geo_mod: main.o vector.o point.o operations.o
	g++ -o ../build/geo_mod ../build/compiled/main.o ../build/compiled/vector.o ../build/compiled/point.o ../build/compiled/operations.o

main.o: vector.o point.o operations.o
	g++ -o ../build/compiled/main.o -I./operations -I./primitives/Point -I./primitives/Vector -c ./main.cpp

vector.o: point.o
	g++ -o ../build/compiled/vector.o -I./primitives/Point -c ./primitives/Vector/Vector.cpp

point.o:
	g++ -o ../build/compiled/point.o -c ./primitives/Point/Point.cpp

# angle.o: operations.o
# 	g++ -o ../build/compiled/angle.o -I./operations -I./primitives/Point -I./primitives/Vector -c ./primitives/Angle/Angle.cpp

operations.o: point.o vector.o
	g++ -o ../build/compiled/operations.o -I./primitives/Point -I./primitives/Vector -c ./operations/Operations.cpp

clean:
	rm -rf *.o *~ geo_mod

# geo_mod: main.o operations.o angle.o point.o vector.o
# 	g++ -o geo_mod main.o operations.o angle.o point.o vector.o

# main.o: main operations angle point vector
# 	g++ -o main.o main.cpp -c -W -Wall -ansi -pedantic -I

# helloWorld.o: helloWorld.c helloWorld.h
# 	g++ -o helloWorld.o helloWorld.c -c -W -Wall -ansi -pedantic

# clean:
# 	rm -rf *.o *~ geo_mod