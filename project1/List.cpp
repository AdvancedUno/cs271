//===============================
// List.cpp
// List with Linked List Structure with method implementations
// Name: EunHo Lee
// Date: 27 Nov 2023
//===============================



#include "List.h"

//==============================================
// List(void)
// Contructor for List class
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
List<T>::List( void ){

    head = NULL;

}

//==============================================
// List(const List<T> &mylist)
// Contructor for List class
// Create a new List from an existing one.
// INPUT: const List<T> &mylist
// RETURN: none
//==============================================
template <class T> 
List<T>::List( const List<T> &mylist ){
    

    if (mylist.head == NULL) {
        head = NULL;
        return;
    } 
    
    head = new Node;
    head->next = NULL;
    Node* ptr = head;
    Node* qtr = mylist.head;

    ptr->item = qtr->item;
    qtr = qtr ->next;

    while (qtr != NULL) {
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->item = qtr->item;
        qtr = qtr->next;
    }

    ptr->next = NULL;

}


//==============================================
// ~List(void)
// Destructor for List class
// Cleans up the memory of the list.
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
List<T>::~List	( void ){

    clear();


}

//==============================================
// operator= ( const List<T> &mylist )
// Assignment operator.
// Assign list to the class
// INPUT: const List<T> &mylist 
// RETURN: List<T>
//==============================================
template <class T> 
List<T> List<T>::operator= ( const List<T> &mylist ){



    clear();

    if (mylist.head == NULL) {
        head = NULL;
        return *this;
    } 

    head = new Node;
    head->next = NULL;
    Node* ptr = head;
    Node* qtr = mylist.head;

    ptr->item = qtr->item;
    qtr = qtr ->next;

    while (qtr != NULL) {
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->item = qtr->item;
        qtr = qtr->next;
    }

    ptr->next = NULL;

    return *this;

}


//==============================================
// to_string( void )
// create string
// INPUT: none
// RETURN: string
//==============================================
template <class T> 
string List<T>::to_string	( void ) const{

    return "I have no idea";
}


//==============================================
// append (const T &item)
// Appends a new item onto the back of the list.
// INPUT: const T &item
// RETURN: none
//==============================================
template <class T> 
void	List<T>::append( const T &item	){

    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *qtr = head;

    while(qtr->next != NULL){
        qtr = qtr->next;
    }
    qtr->next = newNode;
}

//==============================================
// operator[](int index)
// Accesses (by reference) the item at the specified index.
// INPUT: int index
// RETURN: T &
//==============================================
template <class T> 
T &		List<T>::	operator[]	( int index ){

    if(index < 0 || index > length() -1){
        cout << "Invalid position" << endl;
        exit(0);
    }

    Node *qtr = head;

    // not sure to include qtr != NULL && index >0
    while(index > 0){
        index --;  
        qtr = qtr->next;
    }

    return qtr->item;



}

//==============================================
// insert(const T &item, int index)
// Inserts a new value at the specified position.
// INPUT: const T &item, int index
// RETURN: none
//==============================================
template <class T> 
void List<T>::insert(const T &item, int index ){

    if(index < 0 || index > length()){
        cout << "Invalid position" << endl;
        exit(0);
    }


    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *qtr = head;
    while(index > 1){
        index--;  
        qtr = qtr->next;
    }

    newNode->next = qtr->next;
    qtr->next = newNode;

}

//==============================================
// remove(int index)
// Removes an item at the specified location.
// INPUT: int index
// RETURN: none
//==============================================
template <class T> 
void	List<T>::	remove		( int index ){


    if(index < 0 || index > length()-1){
        cout << "Invalid position" << endl;
        exit(0);
    }

    Node* temp; 

    if (index == 0) {
        temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *qtr = head;
    while(index > 1){
        index--;  
        qtr = qtr->next;
    }

    temp = qtr->next;
    qtr->next = temp->next;
    delete temp;

}

//==============================================
// operator+(const List<T> &mylist )
// Concatenates two lists into a new list.
// INPUT: const List<T> &mylist
// RETURN: List<T>
//==============================================
template <class T> 
List<T>	List<T>::operator+( const List<T> &mylist ) const{


    List<T> resultList;
    Node* ptr = head;

    while (ptr != NULL) {
        resultList.append(ptr->item);
        ptr = ptr->next;
    }

    Node* qtr = mylist.head;
    while (qtr != NULL) {
        resultList.append(qtr->item);
        qtr = qtr->next;
    }

    

    return resultList;
}


//==============================================
// length( void )
// Returns the number of items in the list.
// INPUT: none
// RETURN: int
//==============================================
template <class T> 
int		List<T>::	length		( void ) const{

    int cnt = 0;
    Node *qtr = head;

    while(qtr != NULL){
        qtr = qtr->next;
        cnt ++;
    }

    return cnt;


}


//==============================================
// isEmpty(void)
// Returns true if the list is empty, false otherwise.
// INPUT: none
// RETURN: bool
//==============================================
template <class T> 
bool	List<T>::	isEmpty		( void ) const{

    return head == NULL;


}


//==============================================
// clear( void )
// Removes all items from the list.
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
void	List<T>::	clear		( void ){


    Node* ptr;

    while(head != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
    }


}

