all: main

main: main.o 
	g++ -std=c++11 -Wall -g -o main main1.o 

main.o: main1.cpp Heap.h PQueue.h
	g++ -std=c++11 -c -g -Wall main1.cpp
