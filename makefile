sine: main.o mathfuncs.o
	g++ -g main.o mathfuncs.o -o sine

main.o: main.cpp mathfuncs.h
	g++ -g -c main.cpp
mathfuncs.o: mathfuncs.cpp mathfuncs.h
	g++ -g -c mathfuncs.cpp

clean:
	rm *.o
