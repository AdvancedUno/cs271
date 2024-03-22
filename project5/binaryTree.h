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

#ifndef BT_H
#define BT_H
#define DEFAULT_HEAP_SIZE 10

template <class T> 
class BT
{
private:

	// struct for Node for linked list
	struct Node
	{
		T	item;
		Node 	*left;
		Node  	*right;
        Node    *parent;
	};


    int         size = 0;     


	
public:
	BT		                ( void );   //Default constructor
	BT		                ( const BT<T> &myBT ); // copy constructor
	~BT		                ( void ); // destructor


    BT<T>     operator=	    ( const BT<T> &myBT );
    BT<T>     operator+	    ( const BT<T> &myBT );


    void        insert          (T item);
    int         length          (void);
    bool        empty           (void);
    T           max             (void);
    T           extract         (void);



    friend ostream & operator<< ( ostream &os, BT<T> &myHeap )
    {
        os << "[ ";

        for(int i = 0 ; i < myHeap.size; i ++){

            os << myHeap.heap_array[i] << " ";
        }

        os << "]";
        return os;	
    }


};


#endif