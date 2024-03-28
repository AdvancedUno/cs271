all: main encode decode

main: main.o 
	g++ -std=c++11 -Wall -g -o main main.o 

main.o: main.cpp binaryTree.h encode.cpp decode.cpp info.h
	g++ -std=c++11 -c -g -Wall main.cpp

encode: encode.o 
	g++ -std=c++11 -Wall -g -o encode encode.o 

encode.o: main.cpp binaryTree.h encode.cpp decode.cpp info.h
	g++ -std=c++11 -c -g -Wall encode.cpp

decode: decode.o 
	g++ -std=c++11 -Wall -g -o decode decode.o 

decode.o: main.cpp binaryTree.h encode.cpp decode.cpp info.h
	g++ -std=c++11 -c -g -Wall decode.cpp
