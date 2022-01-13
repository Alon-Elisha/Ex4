all: main.o
	gcc -o graph main.o
main.o: main.c algo.h 
	gcc -c main.c

