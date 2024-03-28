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

map<char, string> getCodeMap();
//==============================================
// main
// Reads the text block from stdin and encodes it
// INPUT: none
// RETURN: int 
//==============================================
int main (){

    // //Reading code vectors for each letter(code.txt)
     map<char, string> code_vector;
     code_vector = getCodeMap();



    //Reading block of text from stdin line by line and encoding it using code vector
    string codedText;
    string inputText;
    while(getline(cin,inputText)){
        for(char i:inputText){
          i = tolower(i);
          if ( i >= 'a' && i <= 'z'){
            // cout << i ;
            codedText = codedText + code_vector[i] ;
          }
        }
      //preserving the new lines
      codedText = codedText + "\n" ;
    }

    //Printing the encoded song text
    for( char i : codedText){
      cout << i;
    }

 

    return 0;
}



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
