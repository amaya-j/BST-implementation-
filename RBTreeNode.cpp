//==============================================================
// Names: Aisha Barry, Omar Perez, Amaya Joshi
// Class: CS 271-01
// Date: 11/07/2024
// About: RBTreeNode.cpp contains the implementations for
// the RBTreeNode class. Handling tree-wide structure and management.
//==============================================================


#include "RBTreeNode.hpp"


//================================================================
// Amaya Joshi
// Default Constructor: makes a default node
// Parametrs: None
// Return: None
//=================================================================
template <typename T>
RBTreeNode<T>::RBTreeNode()
    : data(T()), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}



//================================================================
// Aisha Barry
// Copy Constructor: makes a copy of the parameter 
// Parametrs: RBTreeNode<T>& other
// Return: None
//=================================================================
template <typename T>
RBTreeNode<T>::RBTreeNode(const RBTreeNode<T>& other)
    : data(other.data), left(nullptr), right(nullptr), parent(nullptr), color(other.color) {
    if (other.left) {
        left = new RBTreeNode<T>(*other.left);
        left->parent = this;
    }
    if (other.right) {
        right = new RBTreeNode<T>(*other.right);
        right->parent = this;
    }
}



//================================================================
// Amaya Joshi
// Assignment Operator: assigns parameter to this
// Parametrs: RBTreeNode<T>& other
// Return: RBTreeNode<T>&
//=================================================================
template <typename T>
RBTreeNode<T>& RBTreeNode<T>::operator=(const RBTreeNode<T>& other) {
    if (this != &other) {
        data = other.data;
        color = other.color;

        // Delete existing left and right subtrees
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }

        // Copy left subtree
        if (other.left) {
            left = new RBTreeNode<T>(*other.left);
            left->parent = this;
        }

        // Copy right subtree
        if (other.right) {
            right = new RBTreeNode<T>(*other.right);
            right->parent = this;
        }
    }
    return *this;
}



//================================================================
// Omar Perez
// treeMin: return pointer to the minimum value in the tree
// Parametrs: none
// Return: RBTreeNode<T>*
//=================================================================
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMin() {
    RBTreeNode<T>* current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}


//================================================================
// Amaya Joshi
// treeMax: return pointer to the maximum value in the tree
// Parametrs: none
// Return: RBTreeNode<T>*
//=================================================================
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMax() {
    RBTreeNode<T>* current = this;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}


//================================================================
// Omar Perez
// printPreOrderTraversal: prints value in tree in preorder.
// Parametrs: none
// Return: None
//=================================================================
template <typename T>
void RBTreeNode<T>::printPreOrderTraversal() const {
    cout << data << " ";
    if (left)
        left->printPreOrderTraversal();
    if (right)
        right->printPreOrderTraversal();
}



//================================================================
// Amaya Joshi
// printInOrderTraversal: prints value in tree in inorder.
// Parametrs: none
// Return: None
//=================================================================
template <typename T>
void RBTreeNode<T>::printInOrderTraversal() const {
    if (left)
        left->printInOrderTraversal();
    cout << data << " ";
    if (right)
        right->printInOrderTraversal();
}




//================================================================
// Aisha Barry
// printPostOrderTraversal: prints value in tree in postorder.
// Parametrs: none
// Return: None
//=================================================================
template <typename T>
void RBTreeNode<T>::printPostOrderTraversal() const {
    if (left)
        left->printPostOrderTraversal();
    if (right)
        right->printPostOrderTraversal();
    cout << data << " ";
}
