//===============================
// binaryTree.h
// Name: EunHo Lee, Ritika Shrestha, Tomer
// Date: 22 Mar 2024
// This file contains declaration of Binary tree class and impleamention of all Binary tree class methods.
//===============================

#include <iostream>
#include <string>

using namespace std;

#ifndef BT_H
#define BT_H

// struct for Node for Binary tree
template <class T> 
struct Node
{
	T	item;
	Node 	*left;
	Node  	*right;
    Node    *parent;
};

template <class T> 
class BT{
private:

    Node<T>* root;
    int  size = 0;     
    void printBT(Node<T> &root);

	
public:
	BT		                ( void );   //Default constructor
	BT		                ( const BT<T> &myBT ); // copy constructor
	~BT		                ( void ); // destructor


    BT<T>     operator=	    ( const BT<T> &myBT );
    BT<T>     operator+	    ( const BT<T> &myBT );


    void        insert          (const T &item);
    int         length          (void) const;
    bool        empty           (void) const;
    // T           max             (void);
    // T           extract         (void);



    friend ostream & operator<< ( ostream &os, BT<T> &myBT )
    {
        os << "[ ";
            myBT.printBT(myBT.root);
        os << "]";
        return os;
    }


};


#endif


//==============================================
// BT(void)
// Contructor for BT class
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
BT<T>::BT( void ){
    root = NULL;
    size = 0;
}

//==============================================
// BT(const BT<T> &myBT)
// Contructor for BT class
// Create a new BT from an existing one.
// INPUT: const BT<T> &myBT
// RETURN: none
//==============================================
template <class T> 
BT<T>::BT( const BT<T> &myBT ){
    root = NULL;

    if (myBT.root == NULL) {
        // If the input BT is empty, return
        return;
    } 

    // Node<T> *temp = myBT.root;
    
    // // copy the Node until the end
    // while (temp != NULL) {
    //     insert(temp->item);
    //     temp = temp->left;
    // }


    
}


//==============================================
// ~BT(void)
// Destructor for BT class
// Cleans up the memory of the BT.
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
BT<T>::~BT	( void ){

	// clear();
    // // Call clear function for destruction
    // Node* ptr;

    // // clear all the dynamically allocated memeory to the BT nodes
    // while(head != NULL){
    //     ptr = head;
    //     head = head->next;
    //     delete ptr;
    // }

    // // set the tail to NULL
    // tail = NULL;


}

//==============================================
// operator= ( const BT<T> &myBT )
// Assignment operator.
// Assign BT to the class
// INPUT: const BT<T> &myBT 
// RETURN: BT<T>
//==============================================
template <class T> 
BT<T> BT<T>::operator= ( const BT<T> &myBT ){

    // // clear the existing BT before assign new value for the new BT
    // clear();
    
    // head = NULL;
    // tail = NULL;

    // // if the input BT is empty, return
    // if (myBT.head == NULL) {
    //     return *this;
    // } 

    // Node * qtr = myBT.head;
    // while (qtr != NULL) {
    //     append(qtr->item);
    //     qtr = qtr->next;
    // }
    

    // return *this;

}

//==============================================
// operator+ ( const BT<T> &myBT )
// Addition operator.
// Add two Binary tree object
// INPUT: const BT<T> &myBT 
// RETURN: BT<T>
//==============================================
template <class T> 
BT<T>     operator+	    ( const BT<T> &myBT ){

}

//==============================================
// printBT ( )
// Prints the element in the binary tree.
// INPUT: None
// RETURN: None
//==============================================
template <class T> 
void printBT(Node<T> &root) {
    cout << root->item << " ";
    printBT(root->left);
    printBT(root->right);

}

//==============================================
// insert(const T &item)
// Inserts a new value.
// INPUT: const T &item
// RETURN: none
//==============================================
template <class T> 
void BT<T>::insert(const T& item ){

    // // throw error if it is out of range
    // if(index < 0 || index > length()){
    //     cout << "Invalid position" << endl;
    //     throw std::out_of_range("BT<T>::insert(const T &item, int index ) : index is out of range");

    // }

    // // if it is inserting to the head, then just prepend
    // if (index == 0) {
    //     prepend(item);
    //     return;
    // }

    // // if it is end, jsut call append
    // if(index == length()){
    //     append(item);
    //     return;
    // }

    // // create new node for the insert
    // Node *newNode = new Node;
    // newNode->item = item;
    // newNode->next = NULL;
    // newNode->prev = NULL;

    // Node *qtr = head;
    // // loop to the index where to insert
    // while(index > 1){
    //     index--;  
    //     qtr = qtr->next;
    // }

    // // insert the new node
    // newNode->next = qtr->next;
    // newNode->prev = qtr;
    // if(qtr->next !=NULL){
    //     qtr->next->prev = newNode;
    // }

    // qtr->next = newNode;

}


//==============================================
// length( void )
// Returns the number of items in the BT.
// INPUT: none
// RETURN: int
//==============================================
template <class T> 
int		BT<T>::	length		( void ) const{

    // int cnt = 0;
    // Node *qtr = head;
    
    // // loop until it reach to the end of the BT
    // while(qtr != NULL){
    //     qtr = qtr->next;
    //     cnt ++;
    // }

    // return cnt;
    return size;

}


// //==============================================
// // search( const T &item )
// // Returns the index of items in the BT.
// // INPUT: const T &item
// // RETURN: int
// //==============================================
// template <class T> 
// int		BT<T>::	search		( const T &item ) const{

//     // set defalut index to -1
//     int index = -1;

//     Node *qtr = head;

//     // loop till the end of the BT
//     while(qtr != NULL){
//         index++;
//         if(qtr->item == item){ // If the item is found, return the index
//             return index;
//         }
//         qtr = qtr->next; // move the next node
//     }

//     return -1;


// }


//==============================================
// isEmpty(void)
// Returns true if the BT is empty, false otherwise.
// INPUT: none
// RETURN: bool
//==============================================
template <class T> 
bool	BT<T>::	empty		( void ) const{

    return length() == NULL;

}



// //==============================================
// // concat(const BT<T> &myBT )
// // concat two existing BTs to return the newly created BT.
// // INPUT: const BT<T> &myBT
// // RETURN: BT<T>
// //==============================================
// template <class T> 
// BT<T>	BT<T>::concat( const BT<T> &myBT ) const{

//     //create newly created BT for return
//     BT<T> resultBT;

//     Node* ptr = head;

//     // start appending first BT
//     while (ptr != NULL) {
//         resultBT.append(ptr->item);
//         ptr = ptr->next;
//     }

//     // start appending second BT
//     Node* qtr = myBT.head;
//     while (qtr != NULL) {
//         resultBT.append(qtr->item);
//         qtr = qtr->next;
//     }

//     // tail should be pointing to the last node memory address


//     return resultBT;
// }

 


// //==============================================
// // clear( void )
// // Removes all items from the BT.
// // INPUT: none
// // RETURN: none
// //==============================================
// template <class T> 
// void BT<T>::clear( void ){

//     Node* ptr;

//     // clear all the dynamically allocated memeory to the BT nodes
//     while(head != NULL){
//         ptr = head;
//         head = head->next;
//         delete ptr;
//     }

//     // set the tail to NULL
//     tail = NULL;

// }

