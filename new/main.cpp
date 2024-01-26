//==============================================================
// Matt Kretchmar
// November 2023
// main.cpp
// This file is a driver for the List class.
//==============================================================

#include <iostream>
using namespace std;
#include "List.h"



//==============================================================
// main
//==============================================================

int main ( void )
{
    List<int> l1;

    cout << "start" << endl;

    l1.append(1);
    l1.append(2);
    l1.append(3);
    List<int> l2(l1);
    List<int> l3;

    l1.insert(4,1);
    cout << "l1 = " << l1 << endl;
    cout << "l1.length() = " << l1.length() << endl;

    l1[2] = 10;
    cout << "l1 = " << l1 << endl;
    cout << "l1.length() = " << l1.length() << endl;

    l1.remove(1);
    cout << "l1 = " << l1 << endl;
    cout << "l1.length() = " << l1.length() << endl;

    l3 = l2.concat(l1);
    cout << l2 << endl;
    cout << "l3 = l2 + l1 = " << l3 << endl;
    cout << "l3.length() = " << l3.length() << endl;

    cout << "l2 = " << l2 << endl;

    l2.clear();
    cout << "l2.clear() = " << l2 << endl;
    cout << "l2.length() = " << l2.length() << endl;
    cout << "l2 = " << l2 << endl;

    // Test the "doubling" ability of the list
    List<char> l5;
    for ( char c = 'a'; c <= 'g'; c++ )
        l5.append(c);
    List<char> l6 = l5;
    for ( char c = 'h'; c <= 'z'; c++ )
        l5.append(c);
    List<char> l7 = l5;
    
    l5.remove(19);

    

    cout << "l5 = " << l5 << endl;
    cout << "l6 = " << l6 << endl;
    cout << "l7 = " << l7 << endl;

    cout << "l1 = " << l1 << endl;
    l1.clear();
    l1.insert(9,0);
    l1.append(10);
    l1.prepend(2);
    l1.prepend(1);
    cout << "l1 = " << l1 << endl;



    l1.remove(0);
    l1.append(-2);
    cout << "l1 = " << l1 << endl;
    cout << "search of l1: " << l1.search(-2) << endl;
    cout << "l1 = " << l1 << endl;
    
    cout << l1.search(1) << endl;
    //l1.search(834);
    l1.search(0);
    cout << l1.search(-230) << endl;
    
    cout << "Appending for L3" << endl;
    l3.append(7);
    cout << l3 << endl;
    l3.prepend(-10);
    cout << l3 << endl << endl;
    
    
    l3.insert(0, 0);
    cout << l3 << endl << endl;
    
    l3.insert(20, 4);
    cout << l3 << endl << endl;
    
    cout << endl;
    l3.remove(0);
     cout << l3 << endl << endl;
    
    




    return 0;
}
