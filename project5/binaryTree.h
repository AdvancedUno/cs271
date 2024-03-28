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

        Node(NodeInfo item) : item(item),  left(nullptr), right(nullptr) {}
    };


    Node*   root = nullptr;

 

    map<char, string> store_code;

    
    void   printBT      (Node* root);
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



    BT&    operator=	    ( const BT &myBT );
    BT    operator+	    ( const BT &myBT );
    
    Node* deepCopy(Node* rootNode);




    int      getFreq         (void);
    bool     empty           (void) const;
    map<char,string>    buildCodeChar        (void);


    void    codeChar        (Node* rootNode, string code);


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
    root = new Node(item);
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
// operator= ( const BT &myBT )
// Assignment operator.
// Assign BT to the class
// INPUT: const BT &myBT 
// RETURN: BT
//==============================================
BT& BT::operator= ( const BT &myBT ){


    if (this != &myBT) {
        root = deepCopy(myBT.root);
    }

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


    Node* newNode = new Node(myBT.root->item + root->item);
    newNode->left =myBT.root;
    newNode->right = root;
    root = newNode;


    return *this;




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


//==============================================
// codeChar(void)
// Returns true if the BT is empty, false otherwise.
// INPUT: void
// RETURN: void
//==============================================

void	BT::	codeChar		(Node* rootNode, string code) {


    if (rootNode == nullptr) {
        return;
    }

    if(rootNode->item.getChar() >= 'a' && rootNode->item.getChar() <= 'z'){
        store_code.insert(make_pair(rootNode->item.getChar(),code));
        //cout << rootNode->item.getChar() << "   : " << code << endl;
        return;
    }


    codeChar(rootNode->left, code+ "0");
    codeChar(rootNode->right, code+"1");

}



map<char,string>	BT::buildCodeChar		(void) {


   codeChar(root, "");

   return store_code;

}



