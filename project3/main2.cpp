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
#include "Heap.h"
#include "PQueue.h"

using namespace std;

//==============================================
// main
// Run test case on heap class
// INPUT: none
// RETURN: int 
//==============================================
int main ( void)
{
    cout << "--------------- INT datatype Test Start---------------" << endl;
    cout << "                                                       " << endl;
    // Test 1: test length and enqueue
    cout << "---------------Test 1 Start---------------" << endl;
    PQueue<int> pri_queue;
    pri_queue.enqueue(10);
    pri_queue.enqueue(20);
    pri_queue.enqueue(5);
    assert(pri_queue.length() == 3);
    cout << " pri_queue =  " << pri_queue << endl;
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
    assert(pri_queue2.peek() == pri_queue2.dequeue());
    assert(pri_queue2.empty());
    cout << "Test 3 Pass" << endl;

    // Test 4: Copy and peek
    cout << "---------------Test 4 Start---------------" << endl;
    PQueue<int> pri_queue3(pri_queue);
    assert(pri_queue3.length()==2);
    int max3 = pri_queue3.peek();
    assert(max3==10);
    cout << "Test 4 Pass" << endl;

     // Test 5: Assignment operator
     cout << "---------------Test 5 Start---------------" << endl;
     for(int i = 0; i<20;i++)
     {
        pri_queue2.enqueue(i);
     }
     pri_queue = pri_queue2;
     assert(pri_queue.length()==20);
     assert(pri_queue.peek()==19);
     cout << "Test 5 Pass" << endl;
    
     // Test 6: Check empty
    cout << "---------------Test 6 Start---------------" << endl;
    PQueue<int> pq_empty;
    assert(pq_empty.empty() == true);
    cout << "Test 6 Pass" << endl;

    // Test 7: Check basic
    cout << "---------------Test 7 Start---------------" << endl;
    PQueue<int> pq1;
    pq1.enqueue(5);
    pq1.enqueue(8);
    pq1.enqueue(3);
    assert(pq1.peek() == 8);
    assert(pq1.length() == 3);
    assert(pq1.dequeue() == 8);
    assert(pq1.length() == 2);
    cout << "Test 7 Pass" << endl;

    // Test 8: Assign operator
    cout << "---------------Test 8 Start---------------" << endl;
    PQueue<int> pq_ori;
    pq_ori.enqueue(2);
    pq_ori.enqueue(10);
    pq_ori.enqueue(7);
    PQueue<int> pq_assign;
    pq_assign = pq_ori;
    assert(pq_assign.peek() == 10);
    assert(pq_assign.length() == 3);
    pq_ori.dequeue();
    assert(pq_assign.peek() == 10);
    assert(pq_assign.length() == 3);
    cout << "Test 8 Pass" << endl;

    // Test 9: Empty and dequeue
    cout << "---------------Test 9 Start---------------" << endl;
    PQueue<int> pq_dequeue;
    pq_dequeue.enqueue(5);
    pq_dequeue.enqueue(2);
    pq_dequeue.enqueue(10);
    pq_dequeue.enqueue(10);
    pq_dequeue.enqueue(7);
    while (!pq_dequeue.empty()) {
        pq_dequeue.dequeue();
    }
    cout << "Test 9 Pass" << endl;

    // Test 10: Large size
    cout << "---------------Test 10 Start---------------" << endl;
    PQueue<int> pq_large;
    for (int i = 0; i < 100000; ++i) pq_large.enqueue(i);
    assert(pq_large.length() == 100000);
    cout << "Test 10 Pass" << endl;

    // Test 11: Large size
    cout << "---------------Test 11 Start---------------" << endl;
    PQueue<int> pq_consecutive;
    for (int i = 0; i < 100; ++i) {
        pq_consecutive.enqueue(i);
        assert(pq_consecutive.dequeue() == i);
    }
    assert(pq_consecutive.length() == 0);
    assert(pq_consecutive.empty() == true);
    cout << "Test 11 Pass" << endl;

    cout << "                                                       " << endl;
    cout << "--------------- CHAR datatype Test Start---------------" << endl;
    cout << "                                                         "  << endl;
   // Test 1: test length and enqueue
    cout << "---------------Test 1 Start---------------" << endl;
    PQueue<char> char_pri_queue;
    char_pri_queue.enqueue('a');
    char_pri_queue.enqueue('c');
    char_pri_queue.enqueue('e');
    cout << " char_pri_queue =  " << char_pri_queue << endl;
    assert(char_pri_queue.length() == 3);
    // cout << " char_pri_queue =  " << char_pri_queue << endl;
    cout << "test 1 pass" << endl;

    // Test 2: Extract maximum
    cout << "---------------Test 2 Start---------------" << endl;
    char max1 = char_pri_queue.dequeue();
    assert(max1 == 'e');
    assert(char_pri_queue.length() == 2);
    cout << "Test 2 Pass" << endl;

    // Test 3: Empty
    cout << "---------------Test 3 Start---------------" << endl;
    PQueue<char> char_pri_queue2;
    assert(char_pri_queue2.empty());
    char_pri_queue2.enqueue('f');
    assert(!char_pri_queue2.empty());
    assert(char_pri_queue2.peek() == char_pri_queue2.dequeue());
    assert(char_pri_queue2.empty() == true);
    cout << "Test 3 Pass" << endl;

    // Test 4: Copy and peek
    cout << "---------------Test 4 Start---------------" << endl;
    PQueue<char> char_pri_queue3(char_pri_queue);
    assert(char_pri_queue3.length()==2);
    char max2 = char_pri_queue3.peek();
    assert(max2 == 'c');
    cout << "Test 4 Pass" << endl;

     // Test 5: Assignment operator
     cout << "---------------Test 5 Start---------------" << endl;
     char_pri_queue2.enqueue('p');
     char_pri_queue2.enqueue('q');
     char_pri_queue2.enqueue('r');
     char_pri_queue2.enqueue('s');
     char_pri_queue2.enqueue('t');
     char_pri_queue = char_pri_queue2;
     assert(char_pri_queue.length()== 5);
     assert(char_pri_queue.peek()== 't');
     cout << "Test 5 Pass" << endl;


    cout << "Pass All Test Cases" << endl;



    return 0;
}

