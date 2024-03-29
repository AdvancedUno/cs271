//===============================
// createTree.cpp
// Name: EunHo Lee , Ritika, Tomer  
// Date: 28 mar 2024
// This file creates the code file using binary tree.
//===============================

#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cassert>
#include <sstream>
#include "binaryTree.h"
#include <queue>
#include <fstream> 
  

using namespace std;

//==========================================
//function decleration
//==========================================
void saveCodeToFile(map<char, string> myCodeMap, string filename);
map<char, int> getCodeMap(string filename);


//==============================================
// CompareBT class
// Comparison class for priority queue
//==============================================
class CompareBT {
    public:
    bool operator()(BT& ltree,  BT& rtree)  {
        //cout << "ltree.getFreq() : " <<ltree.getFreq() << " rtree.getFreq() : " << rtree.getFreq()<< endl;
        return ltree.getFreq() > rtree.getFreq(); // Prioritize lower frequencies
    }
};


//==============================================
// main
// Creates Binary tree from freqTable.txt
// INPUT: none
// RETURN: int 
//==============================================
int main ( void)
{

    //Reading frequency table txt
    map<char, int> charCounts;
    charCounts = getCodeMap("freqTable.txt");

    priority_queue<BT, vector<BT>, CompareBT> pq;


    for(int i =0; i < 26; i ++){
        NodeInfo info = NodeInfo(char(i+97), charCounts[char(i+97)]);
        cout << char(i+97) << "  " << charCounts[char(i+97)] << endl;
        BT b_tree(info);
        pq.push(b_tree);

    }
    
    

    while(pq.size() > 1){
        BT combined_tree = pq.top();
        
        pq.pop();

        combined_tree = combined_tree + pq.top();


        pq.pop();


        pq.push(combined_tree);

    }

    BT final_tree = pq.top(); pq.pop();

    map<char,string> code = final_tree.buildCodeChar();

    for(char i = 'a'; i <= 'z'; i ++){
        cout << i << "   :  " << code[i] << endl;
    }
    saveCodeToFile(code, "code.txt");


    return 0;
}

//==============================================
// saveCodeToFile
// Creates a text file for frequency table
// INPUT: map<char, string> myCodeMap, string filename
// RETURN: void 
//==============================================
void saveCodeToFile(map<char, string> myCodeMap, string filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (pair<char, string> code_pair : myCodeMap) {
            outputFile << code_pair.first << " : " << code_pair.second << endl;
        }
        outputFile.close();
        cout << "Map saved to file: " << filename << endl;
    } else {
        cout << "error in " << filename << endl;
    }
}

//==============================================
// getCodeMap
// Reads a text file and createa a map 
// INPUT: 
// RETURN: map<char, string> 
//==============================================
map<char, int> getCodeMap(string filename){
    
    map<char, int> charMap;
    ifstream file(filename);
    if (!file.is_open()) {
        cout  << "Error " << endl;
        return charMap;
    }

    string line;
    while (getline(file, line)) {

        istringstream iss(line);
        char character;
        string separator, freq;

        // Split each line into character and binary string
        if (iss >> character >> separator >> freq && separator == ":") {
            // Store the character and binary string in the map
            charMap[character] = stoi(freq);
        } 
    }

    file.close();
    return charMap;
}
