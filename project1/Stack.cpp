//===================================
// EunHo Lee
// A templated stack class file with method implementations
// 1 Dec 2023
//===================================

#include "Stack.h"

//============================
// Default constructor
//============================
template<typename T> Stack<T>::Stack(void){




}

//============================
// Default constructor
//============================
template<typename T> Stack<T>::Stack    (const Stack<T> &s):
list(s.list)
{

    // copy constructor called with s.list
    

}

//============================
// Destructor
//============================
template<typename T> Stack<T>::~Stack(void){

    // implict calle to list destructor

}

//============================
// Assignment operator
//============================
template<typename T>
Stack<T>        Stack <T>::operator= (const Stack<T> &s)
{
    // destructor
    list = s.list;
    return *this;
}


//============================
// Push
//============================
template<typename T>
void            Stack<T>::push          (const T &item){

    list.insert(item,0);

}

//============================
// pop
//============================
template<typename T>
T            Stack<T>::pop          (void){


    if(empty()){
        cout << "Stack empty" << endl;
        exit(1);
    }

    T item = list[0];
    list.remove(0);

    return item;

}

//============================
// peak
//============================
template<typename T>
T            Stack<T>::peak          (void){
    if(empty()){
        cout << "Stack empty" << endl;
        exit(1);
    }


    T item = list[0];

    return item;

}


//============================
// Size
//============================
template<typename T>
int             Stack<T>::size      (void)
{
    return list.length();
}


//============================
// empty
//============================

template<typename T>
bool             Stack<T>::empty      (void)
{
    return list.isEmpty();
}

//============================
// clear
//============================

template<typename T>
void             Stack<T>::clear      (void)
{

    list.clear();

}





