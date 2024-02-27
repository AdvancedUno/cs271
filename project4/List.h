//========================================================
// Matt Kretchmar
// November 2023
// List.h
// This file contains the List class declaration.
//========================================================
#include <iostream>
#include <string>
using namespace std;
#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
private:
// struct for Node for linked list
    struct Node
    {
        T item;
        Node *next;
    };
    Node *head; // the pointer for the linked list
public:
    List ( void );
    List ( const List<T> &mylist );
    ~List ( void );
    List<T> operator= ( const List<T> &mylist );
    //string to_string ( void ) const;
    void append ( const T &item );
    T & operator[] ( int index );
    void insert ( const T &item, int index );
    void remove ( int index );
    void remove_by_item (T &item);
    List<T> operator+ ( const List<T> &mylist ) const;
    int length ( void ) const;
    bool isEmpty ( void ) const;
    void clear ( void );
    bool query ( const T &item );
    friend ostream & operator<< ( ostream &os, List<T> &mylist )
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


//========================================================
// Default Constructior
// this method creates initializes a List object.
// Params: none
// return value: none
//========================================================
template <typename T>
List<T>::List ( void )
{
    head = nullptr;
}
//========================================================
//Copy Constructor
// this method creates a list object using deep copy
// parmas: a list object mylist
// return value: none
//========================================================
template <typename T>
List<T>::List ( const List<T> &mylist )
{
// creating two copies, one for the
// Initialize head to nullptr
    head = nullptr;
// Loop through the nodes in mylist and append to the current list
    Node *temp_mylist = mylist.head;
    Node *temp_head = nullptr;
    while (temp_mylist)
    {
        if (!head)
        {
        // If the list is empty, create a new node for the head
            head = new Node{temp_mylist->item, nullptr};
            temp_head = head;
        }
        else
        {
            // Append a new node to the list
            temp_head->next = new Node{temp_mylist->item, nullptr};
            temp_head = temp_head->next;
        }
        temp_mylist = temp_mylist->next;
    }       
}
//========================================================
// destructor
// this method destroy a list object
// params: none
// return value: none
//========================================================
template <typename T>
List<T>::~List (void)
{
    clear();
}
//========================================================
// Assignment operator
// this method assigns a list object into another.
// using the destructor, copy constructor and *this
// params: a list object mylist
// return value: a list object (*this)
//========================================================
template <typename T>
List<T> List<T>::operator= (const List<T> &mylist )
{
    clear();
    head = nullptr;
    // Loop through the nodes in mylist and append to the current list
    Node *temp_mylist = mylist.head;
    Node *temp_head = nullptr;
    while (temp_mylist)
    {
        if (!head)
        {
            // If the list is empty, create a new node for the head
            head = new Node{temp_mylist->item, nullptr};
            temp_head = head;
        }
        else
        {
            // Append a new node to the list
            temp_head->next = new Node{temp_mylist->item, nullptr};
            temp_head = temp_head->next;
        }       
        temp_mylist = temp_mylist->next;
    }
    return *this;
}
//========================================================
// append
// this method append an item to a list,
// parms: a T item
// return value: none
//========================================================
template <typename T>
void List<T>::append ( const T &item)
{
    if (!head)
    {
        // If the list is empty, create a new node for the head
        head = new Node{item, nullptr};
    }
    else
    {
        // Append a new node to the list
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new Node{item, nullptr};
    }
}
//========================================================
// insert
// this method insert a T item into the list at the index
// of index
// params: T item, int index
// return value: none
//========================================================
template <typename T>
void List<T>::insert ( const T &item, int index )
{
    if (index < 0 || index > length() ) // checking for invalud inputs
    {
        cout << "run-time error" << endl;
        exit(EXIT_FAILURE);
    }
    Node *temp1 = head;
    Node *new_node = new Node;
    new_node->item = item;
    if (index == 0) // special case
    {
        new_node->next = temp1;
        head = new_node;
    }
    else
    {
        for(int i = 1; i < index; i++)
        {
        temp1 = temp1->next;
        }
        Node *temp2 = temp1->next; // temp2 will point to the node after temp1
        new_node->next = temp2; // the next node after new node will be t2
        temp1->next = new_node; // the next node after temp1 will be new node
    }
}
//========================================================
// Length
// this method return the length of the list
// params: none
// return value: counter (integer)
//========================================================
template <typename T>
int List<T>::length ( void ) const
{
    Node *temp = head;
    int counter = 0;
    while(temp)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}
//========================================================
// operator[]
// this method returns a T value that exists in the list
// at the index of position
// params: int index
// return value: a T value
//========================================================
template <typename T>
T & List<T>::operator[] ( int index)
{
    // checking for invalid inputs
    if (index < 0 || index > (length() - 1))
    {
        cout << "run-time error" << endl;
        exit(EXIT_FAILURE);
    }
    int i = 0;
    Node *temp = head;
    while(temp)
    {
        if(i == index)
            break;
        temp = temp->next;
        i++;
    }
    return temp->item;
}
//========================================================
// remove
// This method remove from the list the item that
// exists at the index of the position
// params: int index
// return value: none
//========================================================
template <typename T>
void List<T>::remove ( int index )
{
    if (index < 0 || index > (length() - 1))// checking for invalid inputs
    {
        cout << "run-time error" << endl;
        exit(EXIT_FAILURE);
    }
    else if (index != 0)
    {
        Node *after;
        Node *current;
        Node *prev = head;
        for(int i =1; i < index; i++)
        {
            prev = prev->next;
        }
        current = prev->next;
        after = prev->next->next;
        delete current;
        prev->next = after;
    }
    else //special case
    {
        Node *after;
        Node *prev = head;
        after = prev->next;
        delete prev;
        head = after;
    }
}
//========================================================
// isEmpty
// this method is checking whether the list is empty
// or not and returns a boolean value accordignly
// params: none
// return value: boolean expression (true or false)
//========================================================
template <typename T>
bool List<T>::isEmpty ( void ) const
{
    return !head;
}
//========================================================
// clear
// this method clears the list by
// deleting every element in the list
// params: none
// return value: none
//========================================================
template <typename T>
void List<T>::clear ( void )
{
    Node *temp1 = this->head;
    while (temp1)
    {
        Node *temp2 = temp1->next; // save the next node before deleting the current one
        delete temp1;
        temp1 = temp2;  
    }   
    head = nullptr; // after clearing the linked_list, set head to nullptr
}
//========================================================
// operator+
// This method Concatenates two lists into a new list
// without changing either exsting list
// params: A list object mylist
// return value: A list object lst
//========================================================
template <typename T>
List<T> List<T>::operator+ ( const List<T> &mylist ) const
{
    List<T> lst(*this); // creates a new list with copying the calling obejct
    Node *mylist_copy = mylist.head;
    Node *lst_copy = lst.head;
    while(lst_copy->next)
    {
        lst_copy = lst_copy->next;
    }
    while (mylist_copy)
    {
        lst_copy->next = new Node{mylist_copy->item, nullptr};
        lst_copy = lst_copy->next;
        mylist_copy = mylist_copy->next;
    }
    return lst;
}

bool    List<T>::query ( const T &item )
{
    Node *temp = head;
    while(temp!=NULL)
    {
        if (temp->item == item)
            return true;
        temp = temp->next;
    }
    return false;
}
void    List<T>::remove_by_item (T &item)
{
    Node *current = head;
    Node *prev = NULL;

    while ((current != NULL) && (current->item != item))
    {
        prev = current;
        current = current->next;
    }
    if (current != NULL)
    {
        if(prev!= NULL)
        {
            prev->next = current->next;
        }
        else
        {
            head = current->next;
        }
        delete current;
    }
}
//#include "List.cpp" // this is necessary because the list
// class is a template and cannot be
// compiled separately.
#endif