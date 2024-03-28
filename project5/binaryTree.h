//===============================
// binaryTree.h
// Name: EunHo Lee, Ritika Shrestha, Tomer
// Date: 22 Mar 2024
// This file contains declaration of Binary tree class and impleamention of all Binary tree class methods.
//===============================

#include <iostream>
#include <string>
#include "nodeinfo.h"
#include <map>

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
        Node* parent;

        Node(NodeInfo item) : item(item),  left(nullptr), right(nullptr), parent(nullptr) {}
    };


    Node*   root;

 
    Node* deepCopy(Node* rootNode);



    
    void   printBT      (Node* root);
    void   clear(Node* root);
           
    
public:
	BT		                ( void );   //Default constructor
	BT                      ( const BT &myBT ); // copy constructor
    BT		                ( NodeInfo item); // constructor
	~BT		                ( void ); // destructor



    BT    operator=	    ( const BT &myBT );
    BT    operator+	    ( const BT &myBT );
    BT    CreateBT      ( map<char,string> &code_vector );



    int      getFreq         (void);
    bool     empty           (void) const;


    friend ostream & operator<< ( ostream &os, BT &myBT )
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
BT::BT(const BT &myBT) {

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
    if(root!=NULL)
    {
        //Recursively work way to bottom node 
        clear(root->left);
        clear(root->right);

        //one more time here
        delete root;
    }

}


//==============================================
// CreateBT ( map<char, string> &code_vector  )
// Creates binary tree.
// INPUT: map<char, string> &code_vector 
// RETURN: BT
//==============================================
BT   BT::CreateBT(map<char,string> &code_vector ){

    NodeInfo DummyItem(0,0);
    Node* tempRoot = root;

    for (char i='a';i <= 'z';i++ ){
      for (char each:code_vector[i]){
        if (each == '0'){
            if (root->left == NULL){
                root->left = new Node(DummyItem); 
                root->left->parent = root;              
            }
          root= root->left;
        }
        if (each == '1'){
            if (root->right == NULL){
                root->right = new Node(DummyItem);  
                root->right->parent = root;               
            }
          root= root->right;
        }
      }
      root->item = NodeInfo(i,0);
      root = tempRoot;
    }   

    return *this;

}



//==============================================
// operator= ( const BT &myBT )
// Assignment operator.
// Assign BT to the class
// INPUT: const BT &myBT 
// RETURN: BT
//==============================================
BT BT::operator= ( const BT &myBT ){



    // Perform deep copy from myBT
    root = deepCopy(myBT.root);

    

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


    BT newBT(myBT.root->item + root->item);
    // Node* newNode = new Node(myBT.root->item + root->item);
    // newNode->item = myBT.root->item + root->item;


    newBT.root->left = root;
    root =  newBT.root;


    newBT.root->right = myBT.root;


    // return newNode;
    return newBT;







}


//==============================================
// printBT ( )
// Prints the element in the binary tree.
// INPUT: None
// RETURN: None
//==============================================

void BT::printBT(Node* root) {
    cout << root->item << " ";
    printBT(root->left);
    printBT(root->right);

}



//==============================================
// length( void )
// Returns the number of items in the BT.
// INPUT: none
// RETURN: int
//==============================================

int		BT::	getFreq		( void ){


    return root->item.getFreq();

}


// deepCopy - Recursively performs a deep copy of the binary tree
BT::Node* BT::deepCopy(Node* rootNode) {
    if (rootNode == nullptr) {
        return nullptr; // Base case: if the original node is null, return null
    }

    // Create a new node with the same data as the original node
    Node* newRoot = new Node(rootNode->item);

    // Recursively copy the left and right children of the original node
    newRoot->left = deepCopy(rootNode->left);
    newRoot->right = deepCopy(rootNode->right);

    return newRoot; // Return the new node
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
