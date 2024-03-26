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


template <class T> 
class BT{
private:

    // Node structure for binary tree
    struct Node {
        T     item;
        Node* left;
        Node* right;
        Node* parent;

        Node(T item) : item(item),  left(nullptr), right(nullptr), parent(nullptr) {}
    };


    Node* root;

    
    void       printBT      (Node* root);
    
public:
	BT		                ( void );   //Default constructor
	BT		                ( const BT<T> &myBT ); // copy constructor
    BT		                ( T item); // constructor
	~BT		                ( void ); // destructor


    BT<T>     operator=	    ( const BT<T> &myBT );
    BT<T>     operator+	    ( const BT<T> &myBT );

    T          getRootItem     (void);


    int         length          (void) const;
    bool        empty           (void) const;
    //void        printBT         (Node* root);


    friend ostream & operator<< ( ostream &os, BT<T> &myBT )
    {
        os << "[ ";
        os << myBT.root->item;
        //myBT.printBT(myBT.root);
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
}

//==============================================
// BT(void)
// Contructor for BT class
// INPUT: none
// RETURN: none
//==============================================
template <class T> 
BT<T>::BT( T item ){
    root = new Node(item);
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
    // root = NULL;

    // if (myBT.root == NULL) {
    //     // If the input BT is empty, return
    //     return;
    // } 

    // Node *temp = root;
    
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


    

    return *this;

}

//==============================================
// operator+ ( const BT<T> &myBT )
// Addition operator.
// Add two Binary tree object
// INPUT: const BT<T> &myBT 
// RETURN: BT<T>
//==============================================
template <class T> 
BT<T>     BT<T>::operator+	    ( const BT<T> &myBT ){

    cout << root << endl;


    Node* newNode = new Node;
    newNode->nodeFreq = root->nodeFreq + myBT.root->nodeFreq;
    newNode->item = NULL;


    newNode->left = root;
    root = newNode;


    newNode->right = myBT.root;

    


    return *this;






}

template <class T> 
T BT<T>::getRootItem(void){

    cout << root->item << endl;
    return root->item;


}

// //==============================================
// // printBT ( )
// // Prints the element in the binary tree.
// // INPUT: None
// // RETURN: None
// //==============================================
// template <class T> 
// void BT<T>::printBT(Node* root) {
//     cout << root->item << " ";
//     printBT(root->left);
//     printBT(root->right);

// }



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
    return 0;

}




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







;
