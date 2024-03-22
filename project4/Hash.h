//================================================================
// EunHo, Ritika, Tomer
// Mar 3 2024
// Hash.h
// This file contains the Hash class declaration.
//================================================================
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "List.h"
#include "Board.h"
#define DEFAULT_HASHTABLE_SIZE 10

template <typename T>
class HashTable
{
private:
    List<T>* table;
    int table_size;


public:
    HashTable		                ( void );   //Default constructor
    HashTable		                ( int size );
	HashTable		                ( const HashTable<T> &myHash ); // copy constructor
    ~HashTable                       (void);
    HashTable<T>      operator=	    ( const HashTable<T> &myHash );
    
    void        remove          ( T &item );
    void        insert          ( T &item );
    void        clearAll        ( void );
    int         getSlotCount    ( int slot );
    int         getNumSlots     ( void );   
    bool        query           ( const T &item );

    friend ostream & operator<< ( ostream &os, HashTable<T> &myHash )
    {
        
        for(int i = 0; i< myHash.table_size; i++)
        {
            List <T> mylist = myHash.table[i];
            os << mylist;
            os << "," << endl;
        }
        return os;
    }
};



#include "Hash.cpp"



#endif