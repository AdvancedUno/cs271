#include "List.h"

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
        exit(0);
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
        exit(0);
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
        exit(0);
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
    capacity = DEFAULT_LIST_SIZE;
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


