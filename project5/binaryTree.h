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
        NodeInfo  item;     // create an item object that has freq and char (infronode)
        Node* left;
        Node* right;
        Node* parent;

        Node(NodeInfo item) : item(item),  left(nullptr), right(nullptr), parent(nullptr) {}
    };


    Node*   root;

    
    Node* deepCopy(Node* rootNode);

    map<char, string> store_code;

    
    void   printBT      (Node* root);
    void   clear(Node* root);
           
    
public:
	BT		                ( void );   //Default constructor
	BT                      ( const BT &myBT ); // copy constructor
    BT		                ( NodeInfo item); // constructor with item
	~BT		                ( void ); // destructor



    BT&   operator=	    ( const BT &myBT );
    BT    operator+	    ( const BT &myBT );
    BT    CreateBT      ( map<char,string> &code_vector );

    int      getFreq         (void);
    bool     empty           (void) const;
    map<char,string>    buildCodeChar        (void);
    string  decode(string code);

    void    codeChar        (Node* rootNode, string code);


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
    root = new Node(item); // initilize the root with the item 'item'
}





//==============================================
// BT(const BT &myBT)
// Copy Contructor for BT class
// Create a new BT from an existing one.
// INPUT: const BT &myBT
// RETURN: none
//==============================================
BT::BT(const BT &myBT) {

    

    root = deepCopy(myBT.root); // calling deepcopy function in the copy constructor
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

    NodeInfo DummyItem(0,0);    // create a dummy item for the begining
    Node* tempRoot = root;      // create temproot that will point to the root

// traverse through each of the letters, and then traverse through each digit in
// the letter's encoding, and build the binary tree in a way that if we have 0 we going
// left and if we have a 1 we going right.

    for (char i='a';i <= 'z';i++ ){
      for (char each:code_vector[i]){
        if (each == '0'){
            if (root->left == NULL){
                root->left = new Node(DummyItem); 
                root->left->parent = root; 
                //parent to child relation             
            }
          root= root->left;
        }
        if (each == '1'){
            if (root->right == NULL){
                root->right = new Node(DummyItem);  
                root->right->parent = root;  
                //parent to child relation             
            }
          root= root->right;  
        }
      }
      root->item = NodeInfo(i,0);   // assining to the node it's letter.
      root = tempRoot;              // go back to the root.
    }   

    return *this;

}
//==============================================
// decode(string code)
// decode the given code
// INPUT: string code
// RETURN: string
//==============================================
string  BT::decode(string code){
    string output = "";
    Node* currnetNode = root;
    // go through the line of code
    for(int i =0 ; i < code.length()+1; i ++){
        // if the current node has a character, add the char to the string output, and 
        // point back to the root
        if(currnetNode->item.getChar() >= 'a' && currnetNode->item.getChar() <='z'){
            output += currnetNode->item.getChar();
            currnetNode = root;
        }
        if(code[i] == '0'){
            currnetNode = currnetNode->left;
        }else{
            currnetNode = currnetNode->right;

        }
    }

    return output;



}


//==============================================
// printBT ( )
// Prints the element in the binary tree.
// INPUT: None
// RETURN: None
//==============================================

void BT::printBT(Node* root) {
    if (root == NULL) return;
    cout << root->item << " ";
    printBT(root->left);
    printBT(root->right);

}



//==============================================
// operator= ( const BT &myBT )
// Assignment operator.
// Assign BT to the class
// INPUT: const BT &myBT 
// RETURN: BT
//==============================================
BT& BT::operator= ( const BT &myBT ){

    clear(root);
    root = deepCopy(myBT.root);
    //if (this != &myBT) {
        //root = deepCopy(myBT.root);
    //}

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

    // the new bt root will be the sum of the two roots
    // the left child will be the root of mybt
    // and the right child will be the root of root
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

    // set the parent connection 
    if(newRoot->left != nullptr){
        newRoot->left->parent = rootNode;
    }
    if(newRoot->right != nullptr){
        newRoot->right->parent = rootNode;
    }

    return newRoot; // Return the new node
}



//==============================================
// isEmpty(void)
// Returns true if the BT is empty, false otherwise.
// INPUT: none
// RETURN: bool
//==============================================

bool	BT::	empty		( void ) const{

    return root == NULL;

}


//==============================================
// codeChar(void)
// This method populating the map with pairs of characters and their coding
// INPUT: void
// RETURN: void
//==============================================

void	BT::	codeChar		(Node* rootNode, string code) {


    if (rootNode == nullptr) {
        return;
    }
    // if the character of the current node is between a and z, insert
    // the character and its encoding to store_code

    if(rootNode->item.getChar() >= 'a' && rootNode->item.getChar() <= 'z'){
        store_code.insert(make_pair(rootNode->item.getChar(),code));
        //cout << rootNode->item.getChar() << "   : " << code << endl;
        return;
    }

    // recursively calling the function left and right with the corresponding digit 
    // attached
    codeChar(rootNode->left, code+ "0");
    codeChar(rootNode->right, code+"1");

}



map<char,string>	BT::buildCodeChar		(void) {


   codeChar(root, "");

   return store_code;

}



