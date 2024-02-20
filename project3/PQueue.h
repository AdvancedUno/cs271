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


public:
	// Primary methods
    PQueue      (void);
    PQueue      (const PQueue<T> &my_pqueue);
    

	// Friend function
	friend ostream & operator<< ( ostream &os, List<T> &mylist )
	{
		Node *ptr = mylist.head;
		while ( ptr != NULL )
		{
			if ( ptr->next != NULL )
				os << ptr->item << " ";
			else
				os << ptr->item;
			ptr = ptr->next;
		}
		return os;	
	}
};


//#include "List.cpp"

#endif