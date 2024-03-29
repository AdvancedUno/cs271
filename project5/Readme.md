##Project 5: Binary Tree Huffman Coding

We have four Excecutables in our make file:

1. ./freqTable: This program executes freqTable.cpp which reads the WarPeace.txt file (via stdin redirection) and counts instances of letters (converted to lower case).  It outputs a frequency table as FreqTable.txt file. 

2. ./createTree: This program executes createTree.cpp which reads the opens and reads the file "FreqTable.txt" and uses my BinaryTree class along with the STL priority queue to build the tree. Then it parse the tree and print out the code vectors for each letter and save this in a second text file "codes.txt"

3. ./encode : This program reads "codes.txt" file and then reads some block of text (from stdin) and translates the block of text into a encoded text and saves it as "encoded.txt"

4. ./decode: This program re-creates the BinaryTree. Then reads (from stdin) an encoded file.  It uses the BinaryTree to parse the code vectors and translate them back into plain text.  It prints out the plain text.  