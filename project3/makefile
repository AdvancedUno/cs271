all: main pq

main: main.o 
	g++ -std=c++11 -Wall -g -o main main1.o 

pq: pq.o  
	g++ -std=c++11 -Wall -g -o pq main2.o 

main.o: main1.cpp Heap.h
	g++ -std=c++11 -c -g -Wall main1.cpp

pq.o: main2.cpp PQueue.h Heap.h
	g++ -std=c++11 -c -g -Wall main2.cpp
