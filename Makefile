main.o: main.cpp structs.h trade.h battleenemy.h askname.h presskey.h
	g++ -c main.cpp

main: main.o
	g++ -pedantic-errors -std=c++11 main.o -o main

clean:
	rm -f main main.o

.PHONY: clean 
