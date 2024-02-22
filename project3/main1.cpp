//===============================
// main1.cpp
// Name: EunHo Lee,Ritika, Tomer  
// Date: 22 Feb 2024
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
// RETURN: int 
//==============================================
int main(void) {
    cout << "--------------- INT datatype Test Start---------------" << endl;
    cout << "                                                       " << endl;
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
    cout << "Heap 1 = " << heap_from_array << endl;
    assert( heap_from_array.max() == 70);

    heap_from_array.heapSort();
    cout << "Sorted Heap 1  = " << heap_from_array << endl;
    heap_from_array.buildHeap();

    // Already sorted array
    int arr_s[5]= {1,2,3,4,5};
    Heap<int> heap_sorted(arr_s, 5);
    heap_sorted.heapSort();
    cout << "Heap_sorted = " << heap_sorted << endl;
    heap_sorted.buildHeap();

    int arr2[5]= {1,1,1,1,2};
    Heap<int> heap_from_array2(arr2, 5);
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
    heap.heapSort();
    cout << "empty_heap = " << heap<< endl;
    assert(heap.empty() == true);
    cout << "Test 5 Pass" << endl;

    // Test 6: Empty check
    cout << "---------------Test 6 Start---------------" << endl;
    Heap<int> single_heap;
    single_heap.insert(1);
    single_heap.heapSort();
    cout << "single_heap = " << single_heap<< endl;
    assert(single_heap.max() == 1);
    assert(single_heap.extract() == 1);
    assert(single_heap.empty() == true);
    assert(single_heap.length() == 0);
    cout << "Test 6 Pass" << endl;

    // Test 7: Neg number check
    cout << "---------------Test 7 Start---------------" << endl;
    Heap<int> heap_neg;
    heap_neg.insert(-1);
    heap_neg.insert(-2);
    heap_neg.insert(-3);
    assert(heap_neg.extract() == -1);
    assert(heap_neg.extract() == -2);
    assert(heap_neg.extract() == -3);
    cout << "heap_neg = " << heap_neg << endl;
    cout << "Test 7 Pass" << endl;

    // Test 8: sorted check
    cout << "---------------Test 8 Start---------------" << endl;
    int sorted_array[5] = {1, 2, 3, 4, 5};
    Heap<int> heap_sorted2(sorted_array, 5);
    heap_sorted2.buildHeap();
    assert(heap_sorted2.max() == 5);
    cout << "heap_sorted2 = " << heap_sorted2 << endl;
    cout << "Test 8 Pass" << endl;

    // Test 9: Extract and empty function check
    cout << "---------------Test 9 Start---------------" << endl;
    Heap<int> heap_extract;
    for (int i = 0; i < 5; ++i) {
        heap_extract.insert(i);
    }
    while (!heap_extract.empty()) {
        heap_extract.extract();
    }
    assert(heap_extract.empty() == true);
    cout << "Test 9 Pass" << endl;

    // Test 10: Pos Neg check
    cout << "---------------Test 10 Start---------------" << endl;
    Heap<int> heap_pn;
    heap_pn.insert(-100);
    heap_pn.insert(100);
    heap_pn.insert(0);
    assert(heap_pn.extract() == 100);
    assert(heap_pn.extract() == 0);
    assert(heap_pn.extract() == -100);
    cout << "Test 10 Pass" << endl;

    // Test 10: Large size array
    cout << "---------------Test 11 Start---------------" << endl;
    Heap<int> large_heap;
    for (int i = 0; i < 100000; ++i) large_heap.insert(i);
    assert(large_heap.length() == 100000);
    cout << "Test 10 Pass" << endl;

    cout << "---------------Test 12 Start---------------" << endl;
    // Test last: Error handling, e.g., extract from an empty heap
    try {
        int_heap.extract();
    } catch (const std::out_of_range& e) {
        std::cout << "Check: " << e.what() << std::endl;
    }

    cout << "Test 12 Pass" << endl;



    cout << "                                                       " << endl;
    cout << "--------------- CHAR datatype Test Start---------------" << endl;
    cout << "                                                       " << endl;
    // Test 1: Inserting
    cout << "---------------Test 1 Start---------------" << endl;
    Heap<char> C_heap;
    C_heap.insert('a');
    C_heap.insert('b');
    C_heap.insert('c');
    C_heap.insert('A');
    assert(C_heap.length() == 4);
    cout << "C_Heap1 = " << C_heap << endl;    

    //Exceeding capcity
    Heap<char> C_heap2(2);
    C_heap2.insert('A');
    C_heap2.insert('a');
    C_heap2.insert('a');
    C_heap2.insert('a');
    assert(C_heap2.length() == 4); 
    cout << "C_heap2 = " << C_heap2 << endl;

    // Test 2: Extract maximum
    cout << "---------------Test 2 Start---------------" << endl;
    char C_max = C_heap.extract();
    assert(C_max == 'c');
    assert(C_heap.length() == 3);
    cout << "C_Heap 1 = " << C_heap << endl;
    cout << "Heap max extracted= " << C_heap.max() << endl;

    C_heap.extract();
    C_heap.extract();
    //extracting the last item
    C_heap.extract();

    //empty heap
    assert(C_heap.length() == 0);
    cout << "Heap = " << C_heap << endl;
    cout << "Test 2 Pass" << endl;

    // Test 3: Heapify and heap sort
    cout << "---------------Test 3 Start---------------" << endl;
    char C_arr[5]= {'a','b','f','d','e'};
    Heap<char> C_heap_from_array(C_arr, 5);
    C_heap_from_array.buildHeap();
    cout << "C_heap_from_array = " << C_heap_from_array << endl;
    assert( C_heap_from_array.max() == 'f');

    // Test 4: Copy constructor and assignment operator
    cout << "---------------Test 4 Start---------------" << endl;
    char C_arr2[5]= {'f','d','a','e','b'};
    Heap<char> C_heap_from_array2(C_arr2, 5);
    cout << "C_heap_from_array2 = " << C_heap_from_array2 << endl;

    C_heap_from_array2.heapify(1);
    cout << "C_heap_from_array2 hepified = " << C_heap_from_array2 << endl;

    Heap<char> C_copyHeap( C_heap_from_array2); // Using the copy constructor
    cout << "C_copyHeap = " << C_copyHeap << endl;
    cout << "C_heap_from_array2 = " << C_heap_from_array2 << endl;

    //if assigning heap is empty
    Heap<char> C_copyHeap2;
    C_copyHeap = C_copyHeap2;
    cout << "C_copyHeap = " << C_copyHeap << endl;
    assert(assigned_heap.length() == 0);


    // Test 5: Empty check
    cout << "---------------Test 5 Start---------------" << endl;
    assert(C_heap2.empty() == false);
    int len2= C_heap2.length();
    for (int i= 0;i < len2 ;i++){
        C_heap2.extract(); // Remove remaining elements
    }
    assert(C_heap2.empty() == true);
    cout << "Test 5 Pass" << endl;

    // Test 6: Empty check
    cout << "---------------Test 6 Start---------------" << endl;
    Heap<char> single_char_heap;
    single_char_heap.insert('k');
    assert(single_char_heap.max() == 'k');
    assert(single_char_heap.extract() == 'k');
    assert(single_char_heap.empty() == true);
    assert(single_char_heap.length() == 0);
    cout << "Test 6 Pass" << endl;

 



    std::cout << "All Pass" << std::endl;
    return 0;
}
