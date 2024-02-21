//===============================
// Heap.h
// Heap data structure with method implementations
// Name: EunHo Lee, Ritika Shrestha, Tomer
// Date: 23 Feb 2024
//===============================

#include <iostream>
#include <string>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

template <class T> 
class Heap
{
private:

    int size = 0;
    int capacity = 0;
    T* heap_array;


	
public:
	Heap		                ( void );
	Heap		                ( const Heap<T> &myHeap ); // copy constructor
    Heap		                ( int capacity); // empty heap with the specified capacity
    Heap		                ( int array[], int size); // heap with array and size
	~Heap		                ( void ); // destructor

    Heap<T>     operator=	    ( const Heap<T> &myHeap );

    void        heapify         (int index); 
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
  
}

//==============================================
// INPUT: 
// RETURN: 
//==============================================
template <class T>
Heap<T> :: Heap( int array[], int size ){
  
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










