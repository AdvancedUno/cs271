//===============================
// inversions.cpp
// Count the total number of inversion using devide and concour method and for loop
// Name: EunHo Lee, Ashwin   
// Date: 1 Feb 2024
//===============================

#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cassert>
#include "Heap.h"
#include "PQueue.h"

using namespace std;

//==============================================
// main( int argc, char *argv [])
// main function that takes in argument (number of random element in the array) 
// as a parameter and execute the inversion counting 
// INPUT: int argc, char *argv []
// RETURN: int 
//==============================================
int main ( void)
{
    // Test 1: test length and enqueue
    cout << "---------------Test 1 Start---------------" << endl;
    PQueue<int> pri_queue;
    pri_queue.enqueue(10);
    pri_queue.enqueue(20);
    pri_queue.enqueue(5);
    assert(pri_queue.length() == 3);
    cout << "test 1 pass" << endl;

    // Test 2: Extract maximum
    cout << "---------------Test 2 Start---------------" << endl;
    int max = pri_queue.dequeue();
    assert(max == 20);
    assert(pri_queue.length() == 2);
    cout << "Test 2 Pass" << endl;

    // Test 3: Empty
    cout << "---------------Test 3 Start---------------" << endl;
    PQueue<int> pri_queue2;
    assert(pri_queue2.empty());
    pri_queue2.enqueue(5);
    assert(!pri_queue2.empty());
    int max2 = pri_queue2.dequeue();
    assert(pri_queue2.empty());
    cout << "Test 3 Pass" << endl;

    // Test 4: Copy and peek
    cout << "---------------Test 4 Start---------------" << endl;
    PQueue<int> pri_queue3(pri_queue);
    assert(pri_queue3.length()==2);
    int max3 = pri_queue3.peek();
    assert(max==10);
    cout << "Test 4 Pass" << endl;

     // Test 5: Assignment operator
     cout << "---------------Test 5 Start---------------" << endl;
     for(int i = 0; i<20;i++)
     {
        pri_queue2.enqueue(i);
     }
     pri_queue = pri_queue2;
     assert(pri_queue.length==20);
     assert(pri_queue.peek()==19);
     cout << "Test 5 Pass" << endl;
    

    

    
    



}

