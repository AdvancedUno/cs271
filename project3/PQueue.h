//========================================================
// CS271 - Ritika Shrestha, Eunho Lee, Tomer Osmo
// Spring 2024
// PQueue.h
// This file contains the PQueue declaration and implementation.  
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef PQUEUE_H
#define PQUEUE_H

template <class T> 
class PQueue
{
private:
    Heap<T> pq;


public:
	// Primary methods
    PQueue      (void); //default constructor
    PQueue      (const PQueue<T> &my_pqueue); // copy constructor
    PQueue		 ( T array[], int size); // priority queue with array and size
    ~PQueue      (void); //destructor

    PQueue<T>     operator=	    ( const PQueue<T> &my_pqueue ); //assignment operator
    void          enqueue       (T item);
    int           length        (void);
    bool          empty         (void);
    T             peek          (void);
    T             dequeue       (void);



    

	// Friend function
   friend ostream & operator<< ( ostream &os, PQueue<T> &my_pqueue )
   {
      os << my_pqueue.pq << " ";

      return os;	
   }
};

 //=================================
 // default constructor
 // params: none
 // return val: none
 //=================================
 template <class T>
 PQueue<T>::PQueue        (void){
    pq = Heap<T>();

 }
 //=================================
 // copy constructor
 // params: PQueue<T> &my_pqueue)
 // return val: none
 //=================================
 template <class T>
 PQueue<T>::PQueue        (const PQueue<T> &my_pqueue){
   pq = Heap<T>(my_pqueue.pq);
 }

 //=================================
 // constructor with array and size
 // params: T array[], int size
 // return val: none
 //=================================
 template <class T>
 PQueue<T>::PQueue        (T array[], int size){
   pq = Heap<T>(array, size);
 }

 //=================================
 // desturctor
 // params: none
 // return val: none
 //=================================
 template <class T>
 PQueue<T>::~PQueue        (){
   
 }

 //=================================
 // assignment operator
 // params: PQueue<T> &my_pqueue)
 // return val: PQueue<T> 
 //=================================
  template <class T>
 PQueue<T>  PQueue<T>::operator=	    ( const PQueue<T> &my_pqueue ){

   pq=  Heap<T>(my_pqueue.pq);
   return *this;
    
 }

 //=================================
 // enqueue
 // It inserts a new item by priority.
 // params: T item
 // return val: none
 //=================================
 template <class T>
 void PQueue<T>::enqueue	    ( T item){

    return pq.insert(item);

 }
 //=================================
 // length
 // It returns the number of items in the priority queue.
 // params: none
 // return val: int
 //=================================
 template <class T>
 int           PQueue<T>::length        (void){

    return pq.length();

 }

 //=================================
 // empty
 // true if empty, false otherwise
 // params: none
 // return val: boolean expression( true if the Pqueue is empty, false otherwise)
 //=================================
 template <class T>
 bool           PQueue<T>::empty       (void){

    return pq.empty();

 }
 //=================================
 // peek
 // It returns the first item in the priority queue without removing it.
 // params: none
 // return val: T item
 //=================================
 template <class T>
 T             PQueue<T>::peek          (void){

    return pq.max();

 }
 //=================================
 // dequeue
 // It removes and returns the first item in the priority queue.
 // params: none
 // return val: T item
 //=================================
 template <class T>
 T            PQueue<T>::dequeue         (void){

    return pq.extract();
    
 }



 



#endif