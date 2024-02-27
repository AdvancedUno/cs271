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
        
        for(int i = 0; i< myHash.table_size; i++)
        {
            List <T> mylist = myHash.table[i];
            os << mylist;
            os << "," << endl;
        }
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

HashTable<T>:: ~HashTable		      ( void )
{
    delete []table;
    table_size = 0;
}

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

