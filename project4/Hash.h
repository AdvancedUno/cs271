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

/*
template <typename T>
HashTable<T>:: HashTable		      ( void )
{
    table_size = 10;
    table = new List<T>[table_size];
}

template <typename T>
HashTable<T>:: HashTable		      ( int size)
{
    table_size = size;
    table = new List<T>[table_size];
}

template <typename T>
HashTable<T>::HashTable		         ( const HashTable<T> &myHash )
{
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
    
}

template <typename T>
HashTable<T>::~HashTable		      ( void )
{
    delete []table;
    table_size = 0;
}

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
template <typename T>
void          HashTable<T>::remove          ( T &item )
{
    int val = getHashValue(item);
    table[val].remove_by_item(item);
}

template <typename T>
void          HashTable<T>::insert         ( T &item )
{
    int val = getHashValue(item);
    table[val].append(item);
}

template <typename T>
void        HashTable<T>::clearAll        ( void )
{
    for (int i = 0; i <table_size;i++)
    {
        table[i].clear();
    }
}

template <typename T>
 bool         HashTable<T>::query           ( const T &item )
 {
    for(int i = 0; i < table_size; i++)
    {
        if(table[i].query(item))
            return true;
    }
    return false;
 }

template <typename T>
 int        HashTable<T>::getSlotCount    ( int slot )
 {
    return table[slot].length();
 }

template <typename T>
  int        HashTable<T>::getNumSlots    ( void )
 {
    return table_size;
 }
*/

#include "Hash.cpp"



#endif