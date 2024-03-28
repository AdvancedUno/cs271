//===============================
// binaryTree.h
// Name: EunHo Lee, Ritika Shrestha, Tomer
// Date: 22 Mar 2024
// This file contains declaration of Binary tree class and impleamention of all Binary tree class methods.
//===============================

#include <iostream>
#include <string>
#include "nodeinfo.h"

using namespace std;


#ifndef BT_H
#define BT_H



 
class BT{
private:

    // Node structure for binary tree
    struct Node {
        NodeInfo  item;
        Node* left;
        Node* right;

        Node(NodeInfo item) : item(item),  left(nullptr), right(nullptr) {}
    };


    Node*   root;

 
    Node* deepCopy(Node* rootNode);



    
    void    printBT      (Node* root);
    void   clear(Node* root);
           


    //==============================================
    // countNodes
    // Computes the number of nodes in the Binary tree
    // INPUT: Node* rootNode
    // RETURN: int
    //==============================================
    int countNodes(Node* rootNode){
        if(rootNode == NULL)return 0;

        //Go left and right recursively and increase the len by 1 
        int len_left  = countNodes(rootNode->left);
        int len_right = countNodes(rootNode->right);


       return len_right + len_left + 1; 
    }

    
public:
	BT		                ( void );   //Default constructor
	BT                      ( const BT &myBT ); // copy constructor
    BT		                ( NodeInfo item); // constructor
	~BT		                ( void ); // destructor



    BT    operator=	    ( const BT &myBT );
    BT    operator+	    ( const BT &myBT );
    



    int      getFreq         (void);
    bool     empty           (void) const;


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
    root = nullptr; // Initialize root to nullptr
}

//==============================================
// BT(void)
// Contructor for BT class
// INPUT: none
// RETURN: none
//==============================================
BT::BT(NodeInfo item){
    NodeInfo newItem(item);
    root = new Node(newItem);
}





//==============================================
// BT(const BT &myBT)
// Copy Contructor for BT class
// Create a new BT from an existing one.
// INPUT: const BT &myBT
// RETURN: none
//==============================================
BT::BT( const BT &myBT ){
    delete root;

    cout << "copy " << myBT.getFreq() << endl;
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

    clear(root);


}

//==============================================
// clear
// Clears the binary tree by deallocating all dynamically allocated memory.
// INPUT: Node* root
// RETURN: void
//==============================================
void BT::clear(Node* root) {
    if (root == nullptr) return; // Base case: if the root is null, return

    // Recursively clear the left and right subtrees
    clear(root->left);
    clear(root->right);

    // Delete the current node
    delete root;
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


    // BT newBT(myBT.root->item + root->item);
    // // Node* newNode = new Node(myBT.root->item + root->item);
    // // newNode->item = myBT.root->item + root->item;


    // newBT.root->left = root;
    // root =  newBT.root;


    // newBT.root->right = myBT.root;


    // // return newNode;
    // return newBT;







}







// //==============================================
// // printBT ( )
// // Prints the element in the binary tree.
// // INPUT: None
// // RETURN: None
// //==============================================

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

int		BT::	getFreq		( void ){


    return root->item.getFreq();

}


// //==============================================
// // deepCopy 
// // 
// // INPUT: None
// // RETURN: None
// //==============================================
BT::Node* BT::deepCopy(Node* rootNode) {
    
    if (rootNode == nullptr) return nullptr;

    Node* newRoot = new Node(rootNode->item);
    
    newRoot->left = deepCopy(rootNode->left);
    newRoot->right = deepCopy(rootNode->right);
    return newRoot;
}


//==============================================
// isEmpty(void)
// Returns true if the BT is empty, false otherwise.
// INPUT: none
// RETURN: bool
//==============================================

bool	BT::	empty		( void ) const{

    return false;

}
