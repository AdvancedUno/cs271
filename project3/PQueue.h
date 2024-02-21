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
    PQueue		 ( int array[], int size); // priority queue with array and size
    ~PQueue      (void); //destructor

    PQueue<T>     operator=	    ( const PQueue<T> &my_pqueue ); //assignment operator
    void          enqueue       (T item);
    int           length        (void);
    bool          empty         (void);
    T*            peek          (void);
    T*            dequeue       (void);



    

	// Friend function
    friend ostream & operator<< ( ostream &os, PQueue<T> &my_pqueue )
    {
        os << "[ ";

        for(int i = 0 ; i < my_pqueue.length i ++){

            os << my_pqueue[i] << " ";
        }

        os << "]";
        return os;	
    }
};

 //=================================
 // default constructor
 //=================================
 template <class T>
 PQueue<T>::PQueue        (void){

 }
 //=================================
 // copy constructor
 //=================================
 template <class T>
 PQueue<T>::PQueue        (const PQueue<T> &my_pqueue){
    
 }

 //=================================
 // constructor with array and size
 //=================================
 template <class T>
 PQueue<T>::PQueue        (int array[], int size){
    
 }

 //=================================
 // desturctor
 //=================================
 template <class T>
 PQueue<T>::~PQueue        (){
    
 }

 //=================================
 // assignment operator
 //=================================
 template <class T>
 PQueue<T>  PQueue<T>::operator=	    ( const PQueue<T> &my_pqueue ){
    
 }

 //=================================
 // enqueue
 //=================================
 template <class T>
 void PQueue<T>::enqueue	    ( T item){
    
 }
 //=================================
 // length
 //=================================
 template <class T>
 int           PQueue<T>::length        (void){

 }

 //=================================
 // empty
 //=================================
 template <class T>
 bool           PQueue<T>::empty       (void){

 }
 //=================================
 // peek
 //=================================
 template <class T>
 T*            PQueue<T>::peek          (void){

 }
 //=================================
 // dequeue
 //=================================
 template <class T>
 T*            PQueue<T>::dequeue         (void){
    
 }



 



#endif