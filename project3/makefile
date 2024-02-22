all: main1 main2

main1: main.o 
	g++ -std=c++11 -Wall -g -o main1 main1.o 

main2: pq.o  
	g++ -std=c++11 -Wall -g -o main2 main2.o 

main.o: main1.cpp Heap.h
	g++ -std=c++11 -c -g -Wall main1.cpp

pq.o: main2.cpp PQueue.h Heap.h
	g++ -std=c++11 -c -g -Wall main2.cpp
