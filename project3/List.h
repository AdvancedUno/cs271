/*=======================================================
EunHo Lee
 List.h
 Feb 20 2024

 This file contains the class definition for the List class.
 
 ------------------------------------------------------------
 DESCRIPTION:
 The List class is an ordered collection of items.  The items must
 all be of the same datatype specified by a template.

 The number of items in the list is specified by the length()
 of the list.  Items in the list are indexed from 0 (first item)
 to length-1 (last item).  It is generally a run-time error to
 attempt to index a list outside of this range.  The list grows
 dynamically so that it is never full.

 Items may be inserted into the list and removed from the list.
 Values at individual indices may be accessed and/or changed.

 ------------------------------------------------------------
 CONSTRUCTORS:
 There is a default constructor creating an empty list.
 There is a copy constructor to create a new list from an
     existing one.

 ------------------------------------------------------------
 ACCESS:
 isEmpty: returns true if the list is empty, false otherwise.
 length: returns the number of items in the list.
 operator[i]: accesses (by reference) the int at position i.
 toString: returns a string containing the list items.
          example: "( 1, 2, 3 )"
 cout <<: overloads the cout << operator for printing the list.

 ------------------------------------------------------------
 MODIFIERS:
 append: adds a new item onto the end of the list.
 insert: inserts a new item in the list at the specified position,
         moves the other items down to make room.
 remove: removes the item at the specified position.
 assignment operator: can assign one list from another.
 operator+: concatenates two lists into a new list.
 clear: removes all items from the list.
 desctructor: cleans up the memory of the list.

 =======================================================*/

#include <iostream>
using namespace std;

#ifndef LIST_H
#define LIST_H

#define DEFAULT_LIST_SIZE 10

template <typename T>
class List
{
public:
            List        ( void );
            List        ( const List<T> &l );
           ~List        ( void );
    List<T> operator=   ( const List<T> &l );
    void    append      ( T item );
    void    insert      ( T item, int position );
    int     length      ( void ) const;
    T &     operator[]  ( int position );
    void    remove      ( int position );
    bool    isEmpty     ( void ) const;
    List<T> operator+   ( const List<T> &l ) const;
    void    clear       ( void );

    friend ostream & operator << ( ostream &os, const List<T> &l )
    {
        os << "[ ";
        for ( int i = 0; i < l.size-1; i++ )
            os << l.list[i] << ", ";
        if ( l.size != 0 )
            os << l.list[l.size-1] << " ]";
        else
            os << " ]";
        return os;
    }

private:
    // the maximum capacity of the array storing the list
    int     capacity;
    // the current number of items in the list
    int     size;
    // the dynamically allocated array storing the list
    T       *list;

    // make the array twice as big to hold more items
    void    reallocate  ( void );
};



//==============================================
// List(void)
// Contructor for List class
// INPUT: none
// RETURN: none
//==============================================
template <typename T>
List<T>::List(void){
    list = new T[DEFAULT_LIST_SIZE];
    size = 0;
    capacity = DEFAULT_LIST_SIZE;
}

//==============================================
// List( const List<T> &l )
// Contructor for List class with List<T> class parameter
// INPUT: List<T> class parameter
// RETURN: none
//==============================================
template <typename T>
List<T>::List( const List<T> &l ){

    list = new T[l.capacity];
    for(int i = 0; i < l.size; i++){
        list[i] = l.list[i];
    }
    size = l.size;
    capacity = l.capacity;

}

//==============================================
// ~List( void )
// Destructor for List class
// Delete dynamically allocated memory for the list
// INPUT: none
// RETURN: none
//==============================================
template <typename T>
List<T>::~List( void ){
    delete[] list;
}

//==============================================
// operator=(const List<T> &l)
// Assignment operator for List class
// INPUT: List<T> class parameter
// RETURN: new List<T>
//==============================================
template <typename T> 
List<T> List<T>::operator=(const List<T> &l){
    delete[] list;

    list = new T[l.capacity];
    for(int i = 0; i < l.size; i++){
        list[i] = l.list[i];
    }
    size = l.size;
    capacity = l.capacity;

    return *this;

}

//==============================================
// append(T item)
// Append item to the end of the list
// INPUT: item with a Type T
// RETURN: none
//==============================================
template <typename T>
void List<T>::append(T item){
    if(size == capacity){
        reallocate();
    }
    list[size] = item;
    size++;
}

//==============================================
// insert(T item, int position)
// Insert item at position
// INPUT: item with a Type T, position
// RETURN: none
//==============================================
template <typename T>
void List<T>::insert(T item, int position){

    if(position < 0 || position > size){
        cout << "Invalid position" << endl;
        throw std::out_of_range("List<T>::insert(T item, int position) : Invalid position");

    }

    if(size == capacity){
        reallocate();
    }

    for(int i = size-1; i >= position; i--){
        list[i+1] = list[i];
    }
    
    list[position] = item;
    size++;
}

//==============================================
// length(void)
// Return the length of the list
// INPUT: none
// RETURN: length of the list
//==============================================
template <typename T>
int List<T>::length( void ) const{

    return size;
}

//==============================================
// operator[](int position)
// Return the item reference at position
// INPUT: position
// RETURN: item reference at position
//==============================================
template <typename T>
T &  List<T>::operator[](int position){
    if(position < 0 || position > size-1){
        cout << "Invalid position" << endl;
        throw std::out_of_range("List<T>::operator[](int position) : Invalid position");

    }

    return list[position];

}

//==============================================
// remove(int position)
// Remove item at position
// INPUT: position
// RETURN: none
//==============================================
template <typename T>
void List<T>::remove(int position){

    if(position < 0 || position > size-1){
        cout << "Invalid position" << endl;
        throw std::out_of_range("List<T>::remove(int position) : Invalid position");

    }

    for(int i = position; i < size-1; i++){
        list[i] = list[i+1];
    }
    size--;
}

//==============================================
// isEmpty(void)
// Check if the list is empty
// INPUT: none
// RETURN: true if empty, false otherwise
//==============================================
template <typename T>
bool List<T>::isEmpty(void)const{
    return size == 0;
}

//==============================================
// operator+( const List<T> &l )
// Add two lists together
// INPUT: List<T> class parameter
// RETURN: new List<T>
//==============================================
template <typename T>
List<T> List<T>::operator+( const List<T> &l ) const{

    List<T> result;

    result.list = new T[capacity + l.capacity];
    result.size = size + l.size;
    result.capacity = capacity + l.capacity;

    for(int i = 0; i < size; i++){
        result.list[i] = list[i];
    }
    for(int i = 0; i < l.size; i++){
        result.list[size + i] = l.list[i];
    }
    return result;
}

//==============================================
// clear(void)
// Clear the list
// INPUT: none
// RETURN: none
//==============================================
template <typename T>
void List<T>::clear(void){
    size = 0;
}

//==============================================
// reallocate(void)
// Reallocate the list
// INPUT: none
// RETURN: none
//==============================================
template <typename T>
void List<T>::reallocate(void){
    capacity *= 2;
    T *temp_list = list;
    list = new T[capacity];
    for(int i = 0; i < size; i++){
        list[i] = temp_list[i];
    }
    delete[] temp_list;
}




#endif
