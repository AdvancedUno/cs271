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
#include <cassert>
#include <string>
#include "Heap.h"
using namespace std;

//==============================================
// main( int argc, char *argv [])
// main function that takes in argument (number of random element in the array) 
// as a parameter and execute the inversion counting 
// INPUT: int argc, char *argv []
// RETURN: int 
//==============================================
int main(void) {
    
    // Test 1: 
    cout << "---------------Test 1 Start---------------" << endl;
    Heap<int> int_heap;
    int_heap.insert(10);
    int_heap.insert(20);
    int_heap.insert(5);
    assert(int_heap.length() == 3);
    cout << "Test 1 Pass" << endl;


    // Test 2: Extract maximum
    cout << "---------------Test 2 Start---------------" << endl;
    int max = int_heap.extract();
    assert(max == 20);
    assert(int_heap.length() == 2);
    cout << "Test 2 Pass" << endl;

    
    // Test 3: Heapify and heap sort
    cout << "---------------Test 3 Start---------------" << endl;
    List<int> list;
    list.append(3);
    list.append(2);
    list.append(1);
    Heap<int> heap_from_list(list, 3);
    heap_from_list.buildHeap();
    List<int> sorted_list = heap_from_list.heapSort();
    assert(sorted_list[0] <= sorted_list[1] && sorted_list[1] <= sorted_list[2]);
    cout << "Test 3 Pass" << endl;


    // Test 4: Copy constructor and assignment operator
    cout << "---------------Test 4 Start---------------" << endl;
    Heap<int> copyHeap = int_heap; // Using the copy constructor
    Heap<int> assigned_heap;
    assigned_heap = int_heap; // Using the assignment operator
    assert(copyHeap.extract() == assigned_heap.extract());
    cout << "Test 4 Pass" << endl;


    // Test 5: Empty check
    cout << "---------------Test 5 Start---------------" << endl;
    assert(int_heap.empty() == false);
    int_heap.extract(); // Remove remaining elements
    int_heap.extract();
    assert(int_heap.empty() == true);
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

    // Test last: Error handling, e.g., extract from an empty heap
    try {
        int_heap.extract();
    } catch (const std::out_of_range& e) {
        std::cout << "Check: " << e.what() << std::endl;
    }



    std::cout << "All Pass" << std::endl;
    return 0;
}
