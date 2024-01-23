//===============================
// List.cpp
// List with Linked List Structure with method implementations
// Name: EunHo Lee
// Date: 22 Jan 2024
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
    tail = NULL;

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
    
    head = NULL;
    tail = NULL;
    if (mylist.head == NULL) {
        // If the input list is empty, return
        return;
    } 
    
    // allocate memory for head and initialize
    Node* newNode = new Node;
    newNode->next = NULL;
    newNode->prev = NULL;

 
    head = newNode;
    
    Node* qtr = mylist.head;
    newNode->item = qtr->item;
    qtr = qtr ->next;

    Node* ptr = newNode;

    // copy the Node until the end
    while (qtr != NULL) {
        newNode = new Node;
        newNode->item = qtr->item;
        newNode->next = NULL;
        newNode->prev = ptr; // make new node prev point to the ptr node
        ptr->next = newNode;
        ptr = newNode;
        qtr = qtr->next;
    }
    
    // set the last node -> next as NULL
    ptr->next = NULL;
    
    // set the tail node to the last node pointer
    tail = ptr;

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

    // Call clear function for destruction
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

    // clear the existing list before assign new value for the new list
    clear();
    
    head = NULL;
    tail = NULL;

    // if the input list is empty, return
    if (mylist.head == NULL) {
        return *this;
    } 

    // allocate memory for head and initialize
    head = new Node;
    
    head->next = NULL;
    head->prev = NULL;


    Node* ptr = head;
    Node* qtr = mylist.head;
   

    ptr->item = qtr->item;
    ptr->prev = NULL;
    qtr = qtr ->next;


    // copy the Node until the end
    while (qtr != NULL) {
        ptr->next = new Node;
        ptr->next->prev = ptr; // make new node prev point to the ptr node
        ptr = ptr->next;
        ptr->item = qtr->item;
        qtr = qtr->next;
    }
    
    // set the last node -> next as NULL
    ptr->next = NULL;
    
    // set the tail node to the last node pointer
    tail = ptr;

    return *this;

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
    newNode->prev = NULL;

    //if there is no element in the list then assign new node to the head and tail and return
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // append newNode to the tail
    Node *qtr = tail;
    qtr->next = newNode;
    newNode->prev =qtr;

    // update tail node
    tail = newNode;
}



//==============================================
// prepend (const T &item)
// prepend a new item onto the front of the list.
// INPUT: const T &item
// RETURN: none
//==============================================
template <class T> 
void	List<T>::prepend( const T &item	){

    // create newNode instance
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    //if there is no element in the list then assign new node to the head and tail and return
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // append newNode to the front
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
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
        cout << "Out of range" << endl;
        throw std::out_of_range("List<T>::operator[] : index is out of range");
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
        throw std::out_of_range("List<T>::insert(const T &item, int index ) : index is out of range");

    }

    if (index == 0) {
        prepend(item);
        return;
    }

    if(index == length()){
        append(item);
        return;
    }


    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;
    newNode->prev = NULL;



    Node *qtr = head;
    while(index > 1){
        index--;  
        qtr = qtr->next;
    }

    newNode->next = qtr->next;
    newNode->prev = qtr;
    if(qtr->next !=NULL){
        qtr->next->prev = newNode;
    }

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
        throw std::out_of_range("List<T>::remove( int index ) : index is out of range");
    }

    Node* temp; 

    if (index == 0) {
        temp = head;
        head = head->next;
        head->prev = NULL;
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
    if(temp->next != NULL){
        temp->next->prev = qtr;
    }

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
// concat(const List<T> &mylist )
// concat two existing lists to return the newly created list.
// INPUT: const List<T> &mylist
// RETURN: List<T>
//==============================================
template <class T> 
List<T>	List<T>::concat( const List<T> &mylist ) const{

    //create newly created list for return
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
// clear( void )
// Removes all items from the list.
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
void	List<T>::	clear		( void ){


    Node* ptr;

    // clear all the dynamically allocated memeory to the list nodes
    while(head != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
    }

    // set the tail to NULL
    tail = NULL;



}

