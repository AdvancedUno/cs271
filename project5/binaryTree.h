//===============================
// binaryTree.h
// Name: EunHo Lee, Ritika Shrestha, Tomer
// Date: 22 Mar 2024
// This file contains declaration of Binary tree class and impleamention of all Binary tree class methods.
//===============================

#include <iostream>
#include <string>
#include "info.h"

using namespace std;

#ifndef BT_H
#define BT_H


 
class BT{
private:

    // Node structure for binary tree
    struct Node {
        Info  item;
        Node* left;
        Node* right;
        Node* parent;

        Node(Info item) : item(item),  left(nullptr), right(nullptr), parent(nullptr) {}
    };


    Node*   root;

 



    
    void    printBT      (Node* root);
           // //==============================================
    // // deepCopy 
    // // 
    // // INPUT: None
    // // RETURN: None
    // //==============================================
    
    Node* deepCopy(Node* rootNode){

        if(rootNode == NULL)return rootNode;

        Node* newRoot = new Node(rootNode->item);

        newRoot->left = deepCopy(rootNode->left);
        newRoot->right = deepCopy(rootNode->right);


       return newRoot;


    }

    
public:
	BT		                ( void );   //Default constructor
	BT		                ( const BT &myBT ); // copy constructor
    BT		                ( Info& item); // constructor
	~BT		                ( void ); // destructor



    BT    operator=	    ( const BT &myBT );
    BT    operator+	    ( const BT &myBT );
    

    Info        getRootItem     (void);


    int      length          (void) const;
    bool     empty           (void) const;
    //void        printBT         (Node* root);



    friend ostream & operator<< ( ostream &os, BT &myBT )
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

BT::BT( void ){
    root = NULL;
}

//==============================================
// BT(void)
// Contructor for BT class
// INPUT: none
// RETURN: none
//==============================================
BT::BT( Info& item ){
    root = new Node(item);
}



//==============================================
// BT(const BT &myBT)
// Contructor for BT class
// Create a new BT from an existing one.
// INPUT: const BT &myBT
// RETURN: none
//==============================================
BT::BT( const BT &myBT ){
    // root = NULL;

    // if (myBT.root == NULL) {
    //     // If the input BT is empty, return
    //     return;
    // } 

    root = deepCopy(myBT.root);

    


    
}


//==============================================
// ~BT(void)
// Destructor for BT class
// Cleans up the memory of the BT.
// INPUT: none
// RETURN: none
//==============================================
BT::~BT	( void ){




}

//==============================================
// operator= ( const BT &myBT )
// Assignment operator.
// Assign BT to the class
// INPUT: const BT &myBT 
// RETURN: BT
//==============================================
BT BT::operator= ( const BT &myBT ){


    

    return *this;

}

//==============================================
// operator+ ( const BT &myBT )
// Addition operator.
// Add two Binary tree object
// INPUT: const BT &myBT 
// RETURN: BT
//==============================================

BT  BT::operator+	    ( const BT &myBT ){



    Node* newNode = new Node();
    newNode->item = myBT.root->item + root->item;


    newNode->left = root;
    root = newNode;


    newNode->right = myBT.root;

    


    return newNode;






}


T BT::getRootItem(void){

    //cout << root->item << endl;
    return root->item;


}




// //==============================================
// // printBT ( )
// // Prints the element in the binary tree.
// // INPUT: None
// // RETURN: None
// //==============================================
// 
// void BT::printBT(Node* root) {
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

int		BT::	length		( void ) const{

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

bool	BT::	empty		( void ) const{

    return length() == NULL;

}



;