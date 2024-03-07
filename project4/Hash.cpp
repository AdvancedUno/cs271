//================================================================
// EunHo, Ritika, Tomer
// Mar 3 2024
// Hash.cpp
// This file contains the Hash class implementation.
//================================================================


#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include "Hash.h"

using namespace std;

//========================================================
// Default Constructior
// this method creates initializes a HashTable object.
// Params: none
// return value: none
//========================================================

template <typename T>
HashTable<T>:: HashTable		      ( void )
{
    table_size = DEFAULT_HASHTABLE_SIZE;
    table = new List<T>[table_size];

}

//========================================================
// Default Constructior using size
// this method creates initializes a List object with a given
// size from the parameter
// Params: int size
// return value: none
//========================================================

template <typename T>
HashTable<T>:: HashTable		      ( int size)
{
    table_size = size;
    table = new List<T>[table_size];
}


//========================================================
// Copy Constructor
// this method creates initializes a List object using deep copy
// Params: HashTable<T> &myHash
// return value: none
//========================================================
template <typename T>
HashTable<T>::HashTable		         ( const HashTable<T> &myHash )
{
    table_size = myHash.table_size; // copy the size
    table = new List<T>[table_size]; // create a new array of linked list with the parameter size
    for (int i = 0; i < table_size; i++) // traverse through the table
    {
        table[i] = new List<T>(myHash.table[i]);


    }
    
}
//========================================================
// Destructor
// this method delete a HashTable object.
// Params: none
// return value: none
//========================================================

template <typename T>
HashTable<T>::~HashTable		      ( void )
{
    delete []table;
    table_size = 0;
}
//========================================================
// Assignment operator
// this method assign a HashTable to another
// Params: HashTable<T> &myHash
// return value: HashTable<T>  
//========================================================
template <typename T>
HashTable<T>     HashTable<T>:: operator=	    ( const HashTable<T> &myHash )
{
    delete []table;
    table_size = 0;

    table_size = myHash.table_size;
    table = new List<T>[table_size];
    for (int i = 0; i < table_size; i++)
    {
        table[i] = new List<T>(myHash.table[i]);

    }

    return *this;

}

//========================================================
// remove 
// This method removes from the table the first occurance
// of the item given in the parameter.
// params: T item
// return value: none
//========================================================
template <typename T>
void          HashTable<T>::remove          ( T &item )
{
    if (table_size == 0 ){
        return ;
    }
    int slot = item.getHashValue(table_size);
    table[slot].remove_by_item(item);
}
//========================================================
// insert
// This method insert the item given in the parameter
// to the end of the list at that slot.
// params: T item
// return value: none
//========================================================
template <typename T>
void          HashTable<T>::insert         ( T &item )
{
    if (table_size == 0 ){
        return ;
    }    
    int slot = item.getHashValue(table_size);
    if(!query(item)){
        table[slot].append(item);
    }
    
}
//========================================================
// clearAll
// This method clear all the elements in the table
// params: none
// return value: none
//========================================================
template <typename T>
void        HashTable<T>::clearAll        ( void )
{
    for (int i = 0; i <table_size;i++)
    {
        table[i].clear();
    }
}
//========================================================
// query
// This method returns true if the item given in the parameter
// exists in the table and false if not.
// params: T item
// return value: boolean
//========================================================
template <typename T>
bool         HashTable<T>::query           ( const T &item )
{
    if (table_size == 0 ){
        return false;
    }  
    int slot = item.getHashValue(table_size);
    if(table[slot].query(item))
        return true;

    return false;
}
//========================================================
// getSlotCount
// This method returns the number of items in a given slot.
// params: int slot
// return value: int
//========================================================
template <typename T>
int        HashTable<T>::getSlotCount    ( int slot )
{
    return table[slot].length();
}
//========================================================
// getNumSlots
// This method returns the number of slots in the table.
// params: none
// return value: int
//========================================================
template <typename T>
int        HashTable<T>::getNumSlots    ( void )
{
    return table_size;
}