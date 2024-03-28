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
#include <map>
  

using namespace std;


//==============================================
// main
// Reads the text block from stdin and encodes it
// INPUT: none
// RETURN: int 
//==============================================
int main (){

    // //Reading code vectors for each letter(code.txt)
     map<char, string> code_vector;
    // string code_vector_file;
    // cin >> code_vector_file;
    // while(getline(cin,code_vector_file)){
    //     code_vector[code_vector_file[0]] = "1001";
    //     // cout << code_vector_file[0] <<endl;

    // }
    for (char i='a';i <= 'z';i++ ){
      code_vector[i] = "101";
    }

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

    // //Printing the encoded song text
    // for( char i : codedText){
    //   cout << i;
    // }

    for (char i='a';i <= 'z';i++ ){
      
      for (char each:code_vector[i]){
        if (each == '0'){
          cout << "left" << " " ;
        }
        if (each == '1'){
          cout << "right" << " ";
        }

      }
      cout << code_vector[i] << endl;
    }

    return 0;
}
