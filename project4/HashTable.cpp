#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include "HashTable.h"
#include "List.h"
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
    table_size = 10;
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
// Copy Constructior
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
        List<T> other = myHash.table[i];
        Node *temp = other.head;
        while(temp != NULL)
        {
            table[i].append(temp->item); // copy the elements of linked list i
            temp = temp->next;
        }

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
        List<T> other = myHash.table[i];
        Node *temp = other.head;
        while(temp != NULL)
        {
            table[i].append(temp->item);
            temp = temp->next;
        }

    }

    return *this;

}
// not sure if the assignment wants us to remove the first occurance of item
// in the entire table (like implemented here) or to remove the first occurance of item
// in each link list 
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
    int val = getHashValue(item);
    table[val].remove_by_item(item);
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
    int val = getHashValue(item);
    table[val].append(item);
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
    // for(int i = 0; i < table_size; i++)
    // {
    //     if(table[i].query(item))
    //         return true;
    // }

    int val = getHashValue(item);
    if(table[val].query(item))
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