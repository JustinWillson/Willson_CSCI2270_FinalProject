all: Project clean

Project: Driver.o WordTable.o
	g++ -std=c++11 Driver.o WordTable.o -o Project_EXE

Driver.o: Driver.cpp
	g++ -c -std=c++11 Driver.cpp

WordTable.o: WordTable.cpp
	g++ -c -std=c++11 WordTable.cpp

clean:
	rm -f Driver.o
	rm -f WordTable.o
