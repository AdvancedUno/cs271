//===============================
// Heap.h
// Heap data structure with method implementations
// Name: EunHo Lee, Ritika Shrestha, Tomer
// Date: 23 Feb 2024
// This file contains declaration of heap class and impleamention of all heap class methods.
//===============================

#include <iostream>
#include <string>

using namespace std;

#ifndef HEAP_H
#define HEAP_H
#define DEFAULT_HEAP_SIZE 10

template <class T> 
class Heap
{
private:

    int         size = 0;
    int         capacity = 0;

    void        swapVal         (int a, int b);
    int         findParent      (int index);   
    T*          heap_array;

    // make the array twice as big to hold more items
    void        reallocate      ( void );
     


	
public:
	Heap		                ( void );   //Default constructor
	Heap		                ( const Heap<T> &myHeap ); // copy constructor
    Heap		                ( int capacity); // empty heap with the specified capacity
    Heap		                ( T* array, int size); // heap with array and size
	~Heap		                ( void ); // destructor

    Heap<T>     operator=	    ( const Heap<T> &myHeap );

    void        heapify         (int large_index); 
    void        buildHeap       (void); 
    void        heapSort        (void); 
    void        increaseKey     (int index);
    void        insert          (T item);
    int         length          (void);
    bool        empty           (void);
    T           max             (void);
    T           extract         (void);



    friend ostream & operator<< ( ostream &os, Heap<T> &myHeap )
    {
        os << "[ ";

        for(int i = 0 ; i < myHeap.size; i ++){

            os << myHeap.heap_array[i] << " ";
        }

        os << "]";
        return os;	
    }


};

//==============================================
// Heap(void)
// default constructor
// Create a empty heap with default capacity
// INPUT: none
// RETURN: none
//==============================================
template <class T>
Heap<T> :: Heap(void){
  size =0;
  capacity =DEFAULT_HEAP_SIZE;
  heap_array = new T[DEFAULT_HEAP_SIZE];
  
}

//==============================================
// Heap( const Heap<T> &myHeap )
// Copy Contructor 
// Create a new heap from an existing one.
// INPUT: const Heap<T> &myHeap 
// RETURN: none
//==============================================
template <class T>
Heap<T> :: Heap( const Heap<T> &myHeap ){

    heap_array = new T[myHeap.capacity];
    for(int i = 0; i < myHeap.size; i++){
        heap_array[i] = myHeap.heap_array[i];
    }
    size = myHeap.size;
    capacity = myHeap.capacity;

}

//==============================================
// Heap( int arr_capacity )
// Contructor 
// Creates a new heap of specified capacity 
// INPUT: int arr_capacity 
// RETURN: none
//==============================================
template <class T>
Heap<T> :: Heap( int arr_capacity ){
    
    if(arr_capacity < 0){
        cout << "capacity cannot be negative" << endl;
        throw std::out_of_range("Heap<T> :: Heap( int arr_capacity ) : capacity cannot be negative");
    }  
    size = 0;
    capacity = arr_capacity;
    heap_array = new T[arr_capacity];
    
}

//==============================================
// Heap( T* array, int arr_size )
// Contructor for heap class
// Create a new heap with specified array and size
// INPUT: int arr_capacity 
// RETURN: none
//==============================================
template <class T>
Heap<T> :: Heap( T* array, int arr_size ){

    heap_array = new T[arr_size];
    for(int i = 0; i < arr_size; i++){
        heap_array[i] = array[i];
    }
    size = arr_size;
    capacity = arr_size;
    buildHeap();
}


//==============================================
// ~Heap(void)
// Destructor for heap class
// Cleans up the heap.
// INPUT: none
// RETURN: none
//==============================================
template <class T>
Heap<T> :: ~Heap(void){
    delete[] heap_array;
    size = 0;
    capacity = 0;
}

//==============================================
// operator= 
// Assignment operator.
// Assign heap to the class
// INPUT: const Heap<T> &myHeap 
// RETURN: Heap<T> 
//==============================================
template <class T>
Heap<T>  Heap<T> ::operator= ( const Heap<T> &myHeap ){
    //Clearing the current heap
    delete[] heap_array;
    size = 0; 
    capacity = 0;

    heap_array = new T[myHeap.capacity];
    for(int i = 0; i < myHeap.size; i++){
        heap_array[i] = myHeap.heap_array[i];
    }
    size = myHeap.size;
    capacity = myHeap.capacity;

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
    if(index < 0 || index > size){
        cout << "Invalid Index" << endl;
        throw std::out_of_range("Heap<T> ::heapify (int index) : Invalid Index");
        exit(0);
    }

    // set large index to input index as initialize
    int large_index = index;

    // find the left and right child index
    int left_index = index*2 +1;
    int right_index = index*2+2;

    // if left child index is valid and left child is larger than its parents set large_index to left child index
    if(left_index < size && heap_array[left_index] > heap_array[large_index]){
        large_index = left_index;
    }

    // if right child index is valid and right child is larger than the large_index element, set large_index to right child index
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
// increaseKey(int index)
// Position the inserted item to maintain the max-heap property
// INPUT: int index
// RETURN: none
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
//insert(T item)
// Inserts an item in the heap and position it properly by calling increase key
// INPUT: T item
// RETURN: none
//==============================================
template <class T>
void Heap<T>::insert(T item){

    if(size == capacity){
        reallocate();
    }
    heap_array[size] = item;
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
    if(size <2)return -1;
    return (index -1)/2;
}

//==============================================
// heapSort (void)
// It sorts an array in decending order by calling buildHeap to build max-heap on the array. 
// INPUT: None 
// RETURN: None
//==============================================
template <class T>
void Heap<T>::heapSort (void){

    int len = size-1;
    for (int i = len; i > 0 ; i--){
        swapVal(0, i);
        size--;
        heapify(0);
    }
    //Adjusting the array size to sorted part
    size = len +1;

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
    size--;
    heapify(0);
    return max_item;
}

//==============================================
// reallocate(void)
// Reallocate the heap with double the capacity 
// INPUT: none
// RETURN: none
//==============================================
template <typename T>
void Heap<T> ::reallocate(void){
    capacity *= 2;
    T *temp_heap = heap_array;
    heap_array = new T[capacity];
    for(int i = 0; i < size; i++){
        heap_array[i] = temp_heap[i];
    }
    delete[] temp_heap;
}





#endif  











