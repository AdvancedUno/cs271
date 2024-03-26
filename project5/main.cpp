//===============================
// main2.cpp
// Name: EunHo Lee , Ritika, Tomer  
// Date: 22 Feb 2024
// This file contains all test case for the priority queue class.
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
//functiom decleration
//==========================================
void countcharacters(const string &filename, vector<int> &charCounts );


struct CompareBT
{
  bool operator()(const BT<char>& ltree, const BT<char>& rtree) const
  {
    return  ltree.rootFreq() < rtree.rootFreq() ;
  }
};


//==============================================
// main
// Run test case on heap class
// INPUT: none
// RETURN: int 
//==============================================
int main ( void)
{

    vector<int> charCounts(26);
    string filename = "WarPeace.txt";

    countcharacters(filename, charCounts);
    for (int i =0; i < 26; i++)
    {
        char letter = i +'a';
        cout << letter << "  " << charCounts[i] << endl;
    }


    std::priority_queue<BT<char>, CompareBT> pq;

    for(int i =0; i < 26; i ++){
        BT<char> b_tree;
        

        pq.push(b_tree);
    }

    
 




    return 0;
}

//==============================================
// countcharacters
// open and read a text file and count the frequency of each
// character between a-z in the text file.
// INPUT: const string &filename, vector<int> &charCounts
// RETURN: void 
//==============================================
void countcharacters(const string &filename, vector<int> &charCounts )
{

    std::ifstream file(filename);
    if (!file.is_open())
        throw runtime_error("Error opening file");
    char c;
    charCounts.assign(26,0);

    while(file.get(c))
    {
        c = tolower(c);
        if(isalpha(c))
        {
            int index = c - 'a';
            charCounts[index]++;
        }
        
    }
    file.close(); // not neccesarry, we need to decide.
}

