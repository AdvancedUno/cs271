//===============================
// Encode.cpp
// Name: EunHo Lee , Ritika, Tomer  
// Date: 28 mar 2024
// This file encodes the decoded files.
//===============================

#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cassert>
#include <queue>
#include <fstream> 
#include <map>
  

using namespace std;


//==============================================
// main
// 
// INPUT: none
// RETURN: int 
//==============================================
int main ( int argc, char * argv[] ){

    // //Reading code vectors for each letter(code.txt)
    // map<char, string> code_vector;
    // string code_vector_file;
    // cin >> code_vector_file;
    // while(getline(cin,code_vector_file)){
    //     code_vector[code_vector_file[0]] = "1001";
    //     // cout << code_vector_file[0] <<endl;

    // }

    //Reading block of text from stdin
    string codedText;
    string inputText;
    cin >> inputText;
    while(getline(cin,inputText)){
        for(char i:inputText){
          i = tolower(i);
          if ( i >= 'a' && i <= 'z'){
            // cout << i ;
            codedText = code_vector[i] + codedText;
          }
        }
        codedText = codedText+"\n";
    }

    for( char i : codedText){
        cout << i;
    }

    return 0;
}
