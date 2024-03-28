//===============================
// main.cpp
// Name: EunHo Lee , Ritika, Tomer  
// Date: 28 mar 2024
// This file creates the frequency count file.
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


// Comparison function for priority queue
class CompareBT {
    public:
    bool operator()(BT& ltree,  BT& rtree)  {
        //cout << "ltree.getFreq() : " <<ltree.getFreq() << " rtree.getFreq() : " << rtree.getFreq()<< endl;
        return ltree.getFreq() < rtree.getFreq(); // Prioritize lower frequencies
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
        //cout << letter << "  " << charCounts[i] << endl;
    }




    priority_queue<BT, vector<BT>, CompareBT> pq;

    for(int i =0; i < 3; i ++){
        NodeInfo info = NodeInfo(char(i+97), charCounts[i]);
        cout << char(i+97) << "  " << charCounts[i] << endl;
        BT b_tree(info);
        pq.push(b_tree);
    }
    
    


    while(pq.size() > 0){
        BT combined_tree = pq.top();
        
        cout << combined_tree.getFreq() << endl;
        pq.pop();


        //combined_tree = combined_tree + pq.top();

        //pq.pop();
        //pq.push(combined_tree);
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

