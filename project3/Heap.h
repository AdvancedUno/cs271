//===============================
// Heap.h
// Heap data structure with method implementations
// Name: EunHo Lee, Ritika Shrestha, Tomer
// Date: 23 Feb 2024
//===============================

#include <iostream>
#include <string>
#include <List.h>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

template <class T> 
class Heap
{
private:

    int size = 0;
    int capacity = 0;
    List<T> heap_array;


	
public:
	Heap		                ( void );
	Heap		                ( const Heap<T> &myHeap ); // copy constructor
    Heap		                ( int capacity); // empty heap with the specified capacity
    Heap		                ( List<T> array, int size); // heap with array and size
	~Heap		                ( void ); // destructor

    Heap<T>     operator=	    ( const Heap<T> &myHeap );

    void        heapify         (int large_index); 
    void        buildHeap       (void);
    T*          heapSort        (void); 
    void        increaseKey     (int index);
    void        insert          (T item, int position);
    int         length          (void);
    bool        empty           (void);
    T           max             (void);
    T           extract         (void);



    friend ostream & operator<< ( ostream &os, List<T> &mylist )
    {
        os << "[ ";

        for(int i = 0 ; i < size; i ++){

            os << heap_array[i] << " ";
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
  heap_array = NULL;
}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: Heap( const Heap<T> &myHeap ){



}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: Heap( int capacity ){
    capacity = capacity;
    heap_array = NULL;
}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: Heap( List<T> array, int size ){

    

}


//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: ~Heap(void){
  
}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T>  Heap<T> ::operator= ( const Heap<T> &myHeap ){


    
}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
void Heap<T> ::heapify (int index){

    int large_index = index;
    int left_index = index*2 +1;
    int right_index = index*2+2;

    if(left_index < size && heap_array[left_index] > heap_array[large_index]){
        large_index = left_index;
    }

    if(right_index < size && heap_array[right_index] > heap_array[large_index]){
        large_index = right_index;
    }

    if(large_index != index){
        
        T temp = heap_array[large_index];
        heap_array[large_index] = heap_array[index];
        heap_array[index] = temp;

        heapify(large_index);
    }



    return;
}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
void Heap<T> ::buildHeap (void){
    
}


//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
T* Heap<T> ::heapSort (void){
    




}












#endif











