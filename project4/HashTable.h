#include <iostream>
#include <string>
using namespace std;
#ifndef HASHTABLE_H_
#define HASHTABLE_H
#include "List.h"
#define DEFAULT_HASHTABLE_SIZE 10

template <typename T>
class HashTable
{
private:
    List<T> *table;
    int table_size;


public:
    HashTable		                ( void );   //Default constructor
	HashTable		                ( const HashTable<T> &myHash ); // copy constructor
    HashTable<T>      operator=	    ( const HashTable<T> &myHash );
    ~HashTable                       (void);
    HashTable		                ( int table_size );
    
    void        remove          ( T &item );
    void        insert          ( T &item );
    void        clearAll        ( void );
    int         getSlotCount    ( int slot );
    int         getNumSlots     ( void );   
    bool query ( const T &item );

    friend ostream & operator<< ( ostream &os, Hash<T> &myHash )
    {
        Node *ptr = mylist.head;
        os << "[ ";
        while ( ptr != NULL )
        {
            if ( ptr->next != NULL )
                os << ptr->item << ", ";
            else
                os << ptr->item << " ";
            ptr = ptr->next;
        }
        os << "]";
        return os;
    }
};

HashTable<T>:: HashTable		      ( void )
{
    table_size = 10;
    table = new List<T>[table_size];
}

HashTable<T>:: HashTable		      ( int size)
{
    table_size = size;
    table = new List<T>[table_size];
}

HashTable<T>::HashTable		         ( const HashTable<T> &myHash )
{

}



HashTable<T>:: ~HashTable		      ( void )
{
    delete []table;
    table_size = 0;
}

