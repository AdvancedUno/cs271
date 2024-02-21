//===============================
// Heap.h
// Heap data structure with method implementations
// Name: EunHo Lee, Ritika Shrestha, Tomer
// Date: 23 Feb 2024
//===============================

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

#ifndef HEAP_H
#define HEAP_H

template <class T> 
class Heap
{
private:

    int         size = 0;
    int         capacity = 0;

    void        swapVal         (int a, int b);
    int         findParent      (int index);   
    List<T>     heap_array;
     


	
public:
	Heap		                ( void );
	Heap		                ( const Heap<T> &myHeap ); // copy constructor
    Heap		                ( int capacity); // empty heap with the specified capacity
    Heap		                ( List<T> array, int size); // heap with array and size
	~Heap		                ( void ); // destructor

    Heap<T>     operator=	    ( const Heap<T> &myHeap );

    void        heapify         (int large_index); 
    void        buildHeap       (void);
    List<T>     heapSort        (void); 
    void        increaseKey     (int index);
    void        insert          (T item);
    int         length          (void);
    bool        empty           (void);
    T           max             (void);
    T           extract         (void);



    friend ostream & operator<< ( ostream &os, List<T> &mylist )
    {
        os << "[ ";

        for(int i = 0 ; i < mylist.size; i ++){

            os << mylist[i] << " ";
        }

        os << "]";
        return os;	
    }


};

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: Heap(){
  size =0;
  capacity =0;
  heap_array.clear();
}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: Heap( const Heap<T> &myHeap ){

    heap_array = myHeap.heap_array;
    size = myHeap.size;


}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: Heap( int arr_capacity ){
    capacity = arr_capacity;
    heap_array = NULL;
    heap_array.capacity = arr_capacity;
}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: Heap( List<T> array, int arr_size ){

    heap_array = array;
    size = arr_size;


}


//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: ~Heap(void){
  

    size = 0;
    heap_array.clear();


}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T>  Heap<T> ::operator= ( const Heap<T> &myHeap ){

    
    heap_array = myHeap.heap_array;
    size = myHeap.size;

    return *this;
    
}

//==============================================
// Heap<T> ::heapify (int index)
// Implement the heapify function
// INPUT: int index
// RETURN: void
//==============================================
template <class T>
void Heap<T> ::heapify (int index){

    // set large index to input index as initialize
    int large_index = index;

    // find the left and right child index
    int left_index = index*2 +1;
    int right_index = index*2+2;

    // if left child index is valid and left child is larger than its parents set large_index to left child index
    if(left_index < size && heap_array[left_index] > heap_array[large_index]){
        large_index = left_index;
    }

    // if rogjt child index is valid and right child is larger than the large_index element, set large_index to right child index
    if(right_index < size && heap_array[right_index] > heap_array[large_index]){
        large_index = right_index;
    }

    // if the childs are larger than their parents, then swap parent with a child with larger value
    if(large_index != index){
        
        T temp = heap_array[large_index];
        heap_array[large_index] = heap_array[index];
        heap_array[index] = temp;

        // call heapify with the swapted index to check error in that node
        heapify(large_index);
    }



    return;
}

//==============================================
// buildHeap (void)
// This converts an array into a max-heap by calling heapify in a bottom-up manner.
// INPUT: none
// RETURN: none
//==============================================
template <class T>
void Heap<T> ::buildHeap (void){
    for (int i = findParent(size-1); i >= 0; i--){
        heapify(i);
    }
}



//==============================================
// heapSort (void)
// It sorts an array in decending order by calling buildHeap to build max-heap on the array. 
// INPUT: 
// RETURN: 
//==============================================
template <class T>
void Heap<T>::increaseKey(int index){

    int parent_index = findParent(index);

    if(index >0 && heap_array[parent_index] < heap_array[index]){
        swapVal(index , parent_index);
        index = parent_index;
        increaseKey(index);
    }


    return;
}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
void Heap<T>::insert(T item){

    heap_array.append(item);
    size++;

    increaseKey(size-1);


}


//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
void Heap<T>::swapVal(int a, int b){

    T temp = heap_array[a];
    heap_array[a] = heap_array[b];
    heap_array[b] = temp;

}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
int Heap<T>::findParent(int index){

    return (index -1)/2;
}

//==============================================
// heapSort (void)
// It sorts an array in decending order by calling buildHeap to build max-heap on the array. 
// INPUT: 
// RETURN: 
//==============================================
template <class T>
List<T> Heap<T>::heapSort (void){

    buildHeap();// input??
    // i should be the length of the array to sort !! 
    for (int i = size-1; i >0 ; i--){
        swapVal(0, i);
        size --;
        heapify(0);
    }
    
    return heap_array;
}

//==============================================
// length (void)
// It returns the number of items in the heap.
// INPUT: none
// RETURN: int
//==============================================
template <class T>
int Heap<T> ::length (void){
    return size;
}

//==============================================
// empty(void)
// Returns true if the heap is empty, false otherwise.
// INPUT: none
// RETURN: bool
//==============================================
template <class T>
bool Heap<T> ::empty (void){
    return size == 0;
}

//==============================================
// max (void)
// It returns the max item in the heap without removing it.
// INPUT: none
// RETURN: Template datatype
//==============================================
template <class T>
T Heap<T>::max (void){
    if(size == 0){
        cout << "Heap is empty" << endl;
        throw std::out_of_range("Heap<T>::max (void) : heap is empty");

    }
    return heap_array[0];
}

//==============================================
// extract (void)
// It removes and returns the max item in the heap.
// INPUT: none
// RETURN: Template datatype
//==============================================
template <class T>  
T Heap<T> ::extract (void){
    if(size == 0){
        cout << "Heap is empty" << endl;
        throw std::out_of_range("Heap<T>::extract (void) : heap is empty");
        
    }  
    T max_item = heap_array[0]; 
    //Replacing the max item with the last item in the heap
    heap_array[0] = heap_array[size-1];
    heap_array.remove(heap_array.length()-1);
    size --;
    heapify(0);
    return max_item;
}





#endif 











