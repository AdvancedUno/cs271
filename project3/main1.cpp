//===============================
// main1.cpp
// Name: EunHo Lee,Ritika, Tomer  
// Date: 1 Feb 2024
// This file contains all test case for the heap class.
//===============================

#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <string>
#include "Heap.h"
using namespace std;

//==============================================
// main
// Run test case on heap class
// INPUT: none
// RETURN: none
//==============================================
int main(void) {
    
    // Test 1: Inserting
    cout << "---------------Test 1 Start---------------" << endl;
    Heap<int> heap;
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    assert(heap.length() == 4);
    cout << "Heap1 = " << heap << endl;

    //Exceeding capcity
    Heap<int> heap2(5);
    heap2.insert(1);
    heap2.insert(1);
    heap2.insert(1);
    heap2.insert(10);
    heap2.insert(10);
    heap2.insert(10);
    heap2.insert(10);
    assert(heap2.length() == 7); 
    cout << "Heap2 = " << heap2 << endl;

    Heap<int> int_heap;
    int_heap.insert(20);
    int_heap.insert(5);
    int_heap.insert(100);
    int_heap.insert(100);
    assert(int_heap.length() == 4);
    cout << "Heap3 = " << int_heap << endl;
    cout << "Test 1 Pass" << endl;


    // Test 2: Extract maximum
    cout << "---------------Test 2 Start---------------" << endl;
    int max = int_heap.extract();
    assert(max == 100);
    assert(int_heap.length() == 3);
    cout << "Heap 1 = " << int_heap << endl;
    cout << "Heap max extracted= " << int_heap.max() << endl;

    int max2 = int_heap.extract();
    assert(max2 == 100);
    cout << "Heap 1 = " << int_heap << endl;

    int_heap.extract();
    cout << "Heap 1 = " << int_heap << endl;
    cout << "Heap max= " << int_heap.max() << endl;

    //extracting the last item
    int max3 = int_heap.extract();
    assert(max3 == 5);
    //empty heap
    assert(int_heap.length() == 0);
    cout << "Heap = " << int_heap << endl;
    cout << "Test 2 Pass" << endl;

    
    // Test 3: Heapify and heap sort
    cout << "---------------Test 3 Start---------------" << endl;
    int arr[5]= {1,2,70,10,9};
    Heap<int> heap_from_array(arr, 5);
    heap_from_array.buildHeap();
    cout << "Heap 1 = " << heap_from_array << endl;
    assert( heap_from_array.max() == 70);

    // !!!!!
    heap_from_array.heapSort();
    cout << "Sorted Heap 1  = " << heap_from_array << endl;

    int arr2[5]= {1,1,1,1,2};
    Heap<int> heap_from_array2(arr2, 5);
    heap_from_array2.buildHeap();
    cout << "Heap 2 = " << heap_from_array2 << endl;
    assert( heap_from_array2.max() == 2);

    //Already heap array
    int arr3[4]= {4,3,2,1};
    Heap<int> heap_from_array3(arr3, 4);
    heap_from_array3.buildHeap();
    cout << "Heap 3 = " << heap_from_array3 << endl;

    //negatives array
    int arr4[4]= {-4,3,-2,1};
    Heap<int> heap_from_array4(arr4, 4);
    heap_from_array4.buildHeap();
    cout << "Heap 4 = " << heap_from_array4 << endl;

    //hepifying with one violation
    int arr5[9]= {70,2,9,10,1,3,4,5,6};
    Heap<int> heap_from_array5(arr5, 9);
    cout << "Heap 5 = " << heap_from_array5 << endl;
    heap_from_array5.heapify(1);
    cout << "Heap 5 = " << heap_from_array5 << endl;

    cout << "Test 3 Pass" << endl;


    // Test 4: Copy constructor and assignment operator
    cout << "---------------Test 4 Start---------------" << endl;
    Heap<int> copyHeap(heap2); // Using the copy constructor
    cout << "Heap copied = " << copyHeap << endl;
    cout << "Heap2 = " << heap2 << endl;
    Heap<int> assigned_heap(arr4, 4);
    cout << "assigned_heap = " << assigned_heap << endl;

    //Replacing assigned_heap with copyHeap
    assigned_heap = copyHeap; // Using the assignment operator
    cout << "assigned_heap = " << assigned_heap << endl;
    assert(copyHeap.extract() == assigned_heap.extract());

    //if assigning heap is empty
    Heap<int> copyHeap2;
    assigned_heap = copyHeap2;
    cout << "assigned_heap = " << assigned_heap << endl;
    assert(assigned_heap.length() == 0);

    //Using Capacity constructor
    Heap<int> copyHeap3(2);
    copyHeap3 = heap2;
    cout << "copyHeap3 = " << copyHeap3 << endl;
    assert(copyHeap3.length() == 7);

    cout << "Test 4 Pass" << endl;


    // Test 5: Empty check
    cout << "---------------Test 5 Start---------------" << endl;
    assert(heap.empty() == false);
    int len= heap.length();
    for (int i= 0;i < len ;i++){
        heap.extract(); // Remove remaining elements
    }
    assert(heap.empty() == true);
    cout << "Test 5 Pass" << endl;

    // Test 6: Empty check
    cout << "---------------Test 6 Start---------------" << endl;
    Heap<int> single_heap;
    single_heap.insert(1);
    assert(single_heap.max() == 1);
    assert(single_heap.extract() == 1);
    assert(single_heap.empty() == true);
    assert(single_heap.length() == 0);
    cout << "Test 6 Pass" << endl;

    cout << "---------------Test 7 Start---------------" << endl;
    // Test last: Error handling, e.g., extract from an empty heap
    try {
        int_heap.extract();
        
    } catch (const std::out_of_range& e) {
        std::cout << "Check: " << e.what() << std::endl;
    }


    std::cout << "All Pass" << std::endl;
    return 0;
}
