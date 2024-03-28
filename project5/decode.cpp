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
#include "nodeinfo.h"
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
      code_vector[i] = "101" + code_vector[i];
    }   

    NodeInfo item(0,0);
    BT mainBT(item);
    mainBT.CreateBT(code_vector);
    cout << "mainBT";
    cout << mainBT;

    //Reading block of decodes text from stdin line by line and using binary tree
    string decodedText;
    string inputText;
    while(getline(cin,inputText)){
      for(char i:inputText){
        
      }

    }

    return 0;
}

