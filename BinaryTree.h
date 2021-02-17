/*
AUTHOR: Richard Soria
DESCR:  This header file contains all the information of the Binary tree
        that is needed. It basically creates a new binary tree and navigates through 
        it adding new information for later use.

*/

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

using namespace std;

template <class T>
struct TreeNode
{
    T value;           // The value of node
    TreeNode* left;    // Pointer to left child node
    TreeNode* right;   // Pointer to right child node

    bool isLeaf() { return (left == nullptr) && (right == nullptr); }
};

//Template class for BinaryTree
template <class T>
class BinaryTree
{
private:
    TreeNode<T>* root;       // Pointer to the root node

    // Private work functions
    void insert(TreeNode<T>*&, TreeNode<T>*&);
    void destroySubTree(TreeNode<T>*);
    void deleteNode(T, TreeNode<T>*&);
    void makeDeletion(TreeNode<T>*& nodePtr);

    //traversal functions
    void inorder(TreeNode<T>*);
    void preorder(TreeNode<T>*);
    void postorder(TreeNode<T>*);
    void print(TreeNode<T>*);

public:
    
    BinaryTree()
    {
        root = nullptr;
    }

    // Destructor
    ~BinaryTree()
    {
        destroySubTree(root);
    }

    // Binary tree operations
    void insertNode(T);
    bool searchNode(T);
    void remove(T);

    // print functions
    void inorderPrint();
    void preorderPrint();
    void postorderPrint();

};

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. 
// The function inserts the node into the tree pointed to by  
// the TreeNode pointer. This function is called recursively. 
//*************************************************************
template <class T>
void BinaryTree<T>::insert(TreeNode<T>*& nodePtr, TreeNode<T>*& newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;                  // Insert the node
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);     // Search the left branch
    else
        insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, 
// and passes it to the insert function.                   
//**********************************************************
template <class T>
void BinaryTree<T>::insertNode(T item)
{
    TreeNode<T>* newNode = nullptr;	// Pointer to a new node

    // store num in new node
    newNode = new TreeNode<T>;
    newNode->value = item;
    newNode->left = newNode->right = nullptr;

    // Insert the node in tree
    insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   
// deletes all nodes in the tree.                   
//***************************************************
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode<T>* nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);		//Destroys the left 
        if (nodePtr->right)
            destroySubTree(nodePtr->right);		//Destroys the right 
        delete nodePtr;
    }
}

//***************************************************
// searchNode determines if a value is present in   
// the tree
//***************************************************
template <class T>
bool BinaryTree<T>::searchNode(T item)
{
    TreeNode* nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == item)
            return true;
        else if (item < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

//**********************************************
// remove calls deleteNode to delete the       
// node
//**********************************************
template <class T>
void BinaryTree<T>::remove(T item)
{
    deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value   
// member is the same as num                
//********************************************
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode<T>*& nodePtr)
{
    if (item < nodePtr->value)
        deleteNode(item, nodePtr->left);
    else if (item > nodePtr->value)
        deleteNode(item, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

//***********************************************************
// The node is removed and the branches of the tree below 
// the node are reattached. This function might be wrong!!!    
//***********************************************************
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode<T>*& nodePtr)
{
    // Define a temporary pointer to use in reattaching
    // the left subtree
    TreeNode<T>* tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;   // Reattach the left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;  // Reattach the right child
        delete tempNodePtr;
    }
    // If the node has two children
    else
    {
        // Move one node the right.
        tempNodePtr = nodePtr->right;
        
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        // Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

//All the printing is done in here
template <class T>
void BinaryTree<T>::inorderPrint()
{
    cout << endl << "Printing in order" << endl;
    inorder(root);
}

template <class T>
void BinaryTree<T>::preorderPrint()
{
    cout << endl << "Printing pre order" << endl;
    preorder(root);
}

template <class T>
void BinaryTree<T>::postorderPrint()
{
    cout << endl << "Printing post order" << endl;
    postorder(root);
}


//**************************************
//All the order are defined and printed 
//from this template class
//**************************************
template <class T>
void BinaryTree<T>::inorder(TreeNode<T>* nodePtr)
{
    if (nodePtr)
    {
        inorder(nodePtr->left);
        print(nodePtr);
        inorder(nodePtr->right);

    }
}

template <class T>
void BinaryTree<T>::preorder(TreeNode<T>* nodePtr)
{
    if (nodePtr)
    {
        print(nodePtr);
        inorder(nodePtr->left);
        inorder(nodePtr->right);

    }
}

template <class T>
void BinaryTree<T>::postorder(TreeNode<T>* nodePtr)
{
    if (nodePtr)
    {
        inorder(nodePtr->left);
        inorder(nodePtr->right);
        print(nodePtr);

    }
}

//*********************************
//This will print out the current
//node as a value
//*********************************
template <class T>
void BinaryTree<T>::print(TreeNode<T>* printNode)
{
    cout << printNode->value << endl;
}

#endif