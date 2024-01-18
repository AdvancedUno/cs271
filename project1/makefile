all: main driver

main: main.o 
	g++ -std=c++11 -Wall -g -o main main.o 

driver: driver.o 
	g++ -std=c++11 -Wall -g -o driver driver.o 

main.o: main.cpp List.h List.cpp Stack.h Stack.cpp
	g++ -std=c++11 -c -g -Wall main.cpp

driver.o: driver.cpp List.h List.cpp Stack.h Stack.cpp
	g++ -std=c++11 -c -g -Wall driver.cpp



