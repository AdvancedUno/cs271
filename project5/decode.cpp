//===============================
// Decode.cpp
// Name: EunHo Lee , Ritika, Tomer  
// Date: 28 mar 2024
// This file decodes the encoded files/text.
//===============================

#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cassert>
#include "binaryTree.h"
#include <queue>
#include <fstream> 
#include <sstream>
#include <map>
  
using namespace std;

//function declaration
map<char, string> getCodeMap();
//==============================================
// main
// Decodes the encoded files/text
// INPUT: none
// RETURN: int 
//==============================================
int main ( void)
{

    //Reading code vectors for each letter(code.txt)
    map<char, string> code_vector;
    code_vector = getCodeMap();

    // create a bt using CreareBT function on code vector (map with characters and their)
    NodeInfo item(0,0);
    BT mainBT(item);
    mainBT.CreateBT(code_vector);


    //Reading block of encodes text from stdin line by line and using binary tree
    // to decode them.
    string inputText;
    while(getline(cin,inputText)){

      cout<< mainBT.decode(inputText) <<endl; 
    }

    return 0;
}

map<char, string> getCodeMap(){
    // if there is an error reading the file, print error and return the empty map.
    map<char, string> charToBinaryMap;
    ifstream file("code.txt");
    if (!file.is_open()) {
        cout  << "Error " << endl;
        return charToBinaryMap;
    }


    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        char character;
        string separator, binaryString;

        // Split each line into character and binary string
        if (iss >> character >> separator >> binaryString && separator == ":") {
            // Store the character and binary string in the map
            charToBinaryMap[character] = binaryString;
        } 
    }

    file.close();
    return charToBinaryMap;


}

