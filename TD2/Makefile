all: ecosys

ecosys: ecosys.o main_tests.o
	gcc -o ecosys ecosys.o main_tests.o

ecosys.o: ecosys.c
	gcc -o ecosys.o -c ecosys.c -W -Wall -ansi -pedantic

main_tests.o: main_tests.c ecosys.h
	gcc -o main_tests.o -c main_tests.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf ecosys
