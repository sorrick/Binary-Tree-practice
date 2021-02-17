/*
AUTHOR: Richard Soria
DESCR:  This main file populates a binary tree and inserts values into it,
        these values will later be used to sort through. This file is meant to demonstrate
        my abilites and knowledge on Binary trees.
*/


#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // TESTING INT TYPE
  
    // Create the binary tree
    BinaryTree<int> intTree;

    // Insert some data
	//This data will print out in different orders
    intTree.insertNode(39);
    intTree.insertNode(56);
    intTree.insertNode(8);
    intTree.insertNode(23);
    intTree.insertNode(90);
    intTree.insertNode(2);
    intTree.insertNode(79);
    intTree.insertNode(34);
    intTree.insertNode(21);

    // print the tree preorder
    intTree.preorderPrint();

    // print the tree inorder
    intTree.inorderPrint();

    // print the tree postorder
    intTree.postorderPrint();

    // remove some nodes for testing
    intTree.remove(56);
    intTree.remove(34);

    // print the tree preorder
    intTree.preorderPrint();

    // print the tree inorder
    intTree.inorderPrint();

    // print the tree postorder
    intTree.postorderPrint();

	system("PAUSE");

    
    // TESTING STRING TYPE
    

    // Create the binary tree.
    BinaryTree<string> stringTree;

    // Insert some data
    stringTree.insertNode("hi");
    stringTree.insertNode("james");
    stringTree.insertNode("klm");
    stringTree.insertNode("opq");
    stringTree.insertNode("rst");
    stringTree.insertNode("uv");
    stringTree.insertNode("smith");
    stringTree.insertNode("789");
    stringTree.insertNode("630");

    // print the tree preorder
    stringTree.preorderPrint();

    // print the tree inorder
    stringTree.inorderPrint();

    // print the tree postorder
    stringTree.postorderPrint();

    // remove some nodes for testing
    stringTree.remove("rst");
    stringTree.remove("789");

    // print the tree preorder
    stringTree.preorderPrint();

    // print the tree inorder
    stringTree.inorderPrint();

    // print the tree postorder
    stringTree.postorderPrint();

	system("PAUSE");
}
