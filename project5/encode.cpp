//===============================
// Encode.cpp
// Name: EunHo Lee , Ritika, Tomer  
// Date: 28 mar 2024
// This file encodes the plain text/files.
//===============================

#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream> 
#include <sstream>
#include <map>

using namespace std;


//==========================================
//function decleration
//==========================================
map<char, string> getCodeMap();


//==============================================
// main
// Reads the text block from stdin and encodes it
// INPUT: none
// RETURN: int 
//==============================================
int main (){

    //Reading code vectors for each letter(code.txt)
    map<char, string> code_vector;
    code_vector = getCodeMap();

    //Reading block of text from stdin line by line and encoding it using code vector
    string codedText;
    string inputText;
    while(getline(cin,inputText)){
        for(char i:inputText){
          i = tolower(i);
          if ( i >= 'a' && i <= 'z'){
            codedText = codedText + code_vector[i] ;
          }
        }
      //preserving the new lines
      codedText = codedText + "\n" ;
    }

    string filename= "encoded.txt";
    ofstream outputFile(filename);

    //Printing the encoded song text and saving it as a "decoded.txt" file
    for( char i : codedText){
      cout << i;
    }

    if (outputFile.is_open()) {
          outputFile << codedText << endl;
        outputFile.close();
        cout << "Map saved to file: " << filename << endl;
    } else {
        cout << "error in " << filename << endl;
    }   


    return 0;
}




//==============================================
// getCodeMap
// Reads a text file and createa a map 
// INPUT: 
// RETURN: map<char, string> 
//==============================================
map<char, string> getCodeMap(){
    
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
