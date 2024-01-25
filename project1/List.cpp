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
    

    if (mylist.head == NULL) {
        head = NULL;
        tail = NULL;
        return;
    } 
    
    head = new Node;
    head->item = mylist.head->data;
    Node* ptr = head;
    Node* qtr = mylist.head->next;
    
    while (qtr != NULL) {
        ptr->next = new Node;
        ptr->next->item = qtr->item;
        
        ptr = ptr->next;
        qtr = qtr->next;
    }

    tail = ptr;
    size = mylist.size;

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
        tail = NULL
        return *this;
    } 

    head = new Node;
    head->item = mylist.head->data;
    Node* ptr = head;
    Node* qtr = mylist.head->next;
    
    while (qtr != NULL) {
        ptr->next = new Node;
        ptr->next->item = qtr->item;
        
        ptr = ptr->next;
        qtr = qtr->next;
    }

    tail = ptr;
    size = mylist.size;

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

    Node* ptr = new Node;
    ptr->item = item;
    ptr->next = NULL;
    ptr->prev = NULL;

    if(head == NULL)
    {
        head = ptr;
        tail = ptr;
        return;
    }
    tail->next = ptr;
    ptr->prev = tail;
    tail = ptr;
    
}

//==============================================
// prepend (const T &item)
// Prepends a new item onto the front of the list.
// INPUT: const T &item
// RETURN: none
//==============================================
template <class T> 
void	List<T>::prepend( const T &item	){

    Node* ptr = new Node;
    ptr->item = item;
    ptr->next = NULL;
    ptr->prev = NULL;
    
    if (head == NULL)
    {
    	head = tail;
    	head = ptr;
    	return;
    }
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    
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

template <typename T>
int List<T>::search(const T& item) const{
	Node* ptr = head
	int index = 0;
	
	while (ptr != NULL) 
	{
		if (ptr->item == item)
		{
			return index;
		}
		ptr = ptr->next;
		index++;
	}
	return -1;
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
        exit(0);
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

    // clear all the dynamically allocated memeory to the list nodes
    while(head != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
    }

    // set the tail to NULL
    tail = NULL;



}


}

