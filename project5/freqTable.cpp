//===============================
// freqTable.cpp
// Name: EunHo Lee , Ritika, Tomer  
// Date: 28 mar 2024
// This file creates the frequency tble file.
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
  

using namespace std;

//==========================================
//function decleration
//==========================================
void countcharacters(vector<int> &charCounts );
void saveCodeToFile(map<char, int> myCodeMap, string filename);


//==============================================
// main
// Create frequency table
// INPUT: none
// RETURN: int 
//==============================================
int main ( void)
{

    vector<int> charCounts(26);
    map<char,int> freqCode;

    countcharacters(charCounts);

    //Create a map from each letter to it's frequency
    for (int i =0; i < 26; i++)
    {
        char letter = i +'a';
        freqCode[letter] = charCounts[i];
        // cout << letter << "  " << charCounts[i] << endl;
    }
    
    saveCodeToFile(freqCode, "FreqTable.txt");

    return 0;
}

//==============================================
// saveCodeToFile
// Creates a text file for frequency table
// INPUT: map<char, string> myCodeMap, string filename
// RETURN: void 
//==============================================
void saveCodeToFile(map<char, int> myCodeMap, string filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (pair<char, int> code_pair : myCodeMap) {
            outputFile << code_pair.first << " : " << code_pair.second << endl;
        }
        outputFile.close();
        cout << "Frequency Table saved to file: " << filename << endl;
    } else {
        cout << "error in " << filename << endl;
    }
}

//==============================================
// countcharacters
// read a text file from stdin and count the frequency of each
// character between a-z in the text file.
// INPUT: vector<int> &charCounts
// RETURN: void 
//==============================================
void countcharacters(vector<int> &charCounts )
{

    charCounts.assign(26,0);
    string inputText;
    while(getline(cin,inputText)){
        for(char c:inputText){
            c = tolower(c);
            if(isalpha(c))
            {
                int index = c - 'a';
                charCounts[index]++;
            }
            
        }
    }
}