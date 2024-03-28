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
#include <map>
  
  

using namespace std;

// Node* buildBT();

//==============================================
// main
// Decodes the encoded files/text
// INPUT: none
// RETURN: int 
//==============================================
int main ( void)
{
    map<char, string> code_vector;

    for (char i='a';i <= 'z';i++ ){
      code_vector[i] = "101";
    }   

    BT mainBT();
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

÷