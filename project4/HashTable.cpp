#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include "HashTable.h"
using namespace std;

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

HashTable<T>::~HashTable		      ( void )
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
// not sure if the assignment wants us to remove the first occurance of item
// in the entire table (like implemented here) or to remove the first occurance of item
// in each link list 
void          HashTable<T>::remove          ( T &item )
{
    int val = getHashValue(item);
    table[val].remove_by_item(item);
}

void          HashTable<T>::insert         ( T &item )
{
    int val = getHashValue(item);
    table[val].append(item);
}

void        HashTable<T>::clearAll        ( void )
{
    for (int i = 0; i <table_size;i++)
    {
        table[i].clear();
    }
}

 bool         HashTable<T>::query           ( const T &item )
 {
    for(int i = 0; i < table_size; i++)
    {
        if(table[i].query(item))
            return true;
    }
    return false;
 }

 int        HashTable<T>::getSlotCount    ( int slot )
 {
    return table[slot].length();
 }

  int        HashTable<T>::getNumSlots    ( void )
 {
    return table_size;
 }