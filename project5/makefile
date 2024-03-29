all: createTree encode decode freqTable

freqTable: freqTable.o 
	g++ -std=c++11 -Wall -g -o freqTable freqTable.o 

freqTable.o: freqTable.cpp nodeinfo.h binaryTree.h
	g++ -std=c++11 -c -g -Wall freqTable.cpp

createTree: createTree.o 
	g++ -std=c++11 -Wall -g -o createTree createTree.o 

createTree.o: freqTable.cpp createTree.cpp nodeinfo.h binaryTree.h
	g++ -std=c++11 -c -g -Wall createTree.cpp

encode: encode.o 
	g++ -std=c++11 -Wall -g -o encode encode.o 

encode.o: freqTable.cpp createTree.cpp binaryTree.h encode.cpp decode.cpp nodeinfo.h
	g++ -std=c++11 -c -g -Wall encode.cpp

decode: decode.o 
	g++ -std=c++11 -Wall -g -o decode decode.o 

decode.o: freqTable.cpp createTree.cpp binaryTree.h encode.cpp decode.cpp nodeinfo.h
	g++ -std=c++11 -c -g -Wall decode.cpp
