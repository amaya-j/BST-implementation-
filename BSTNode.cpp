//==============================================================
// Names: Aisha Barry, Omar Perez, Amaya Joshi
// Class: CS 271-01
// Date: 11/07/2024
// About: BSTNode.cpp contains implementations of
// the BSTNode class.
//==============================================================


#include "BSTNode.hpp"

//================================================================
// Amaya Joshi
// Default Constructor: makes a default node
// Parametrs: None
// Return: None
//=================================================================
template <typename T>
BSTNode<T>::BSTNode() : data(T()), left(nullptr), right(nullptr), parent(nullptr) {}


//================================================================
// Aisha Barry
// Copy Constructor: makes a copy of the parameter 
// Parametrs: const BSTNode<T>& other
// Return: None
//=================================================================
template <typename T>
BSTNode<T>::BSTNode(const BSTNode<T>& other) : data(other.data), left(nullptr), right(nullptr), parent(nullptr) {
    if (other.left) {
        left = new BSTNode<T>();
        *left = *other.left;
        left->parent = this;
    }
    if (other.right) {
        right = new BSTNode<T>();
        *right = *other.right;
        right->parent = this;
    }
}



//================================================================
// Omar Perez
// Assignment Operator: assigns parameter to this
// Parametrs: BSTNode<T>& other
// Return: BSTNode<T>&
//=================================================================
template <typename T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode<T>& other) {
    if (this != &other) {
        data = other.data;

        // Delete existing left and right subtrees
        delete left;
        delete right;

        // Copy left subtree
        if (other.left) {
            left = new BSTNode<T>();
            *left = *other.left;
            left->parent = this;
        } else {
            left = nullptr;
        }

        // Copy right subtree
        if (other.right) {
            right = new BSTNode<T>();
            *right = *other.right;
            right->parent = this;
        } else {
            right = nullptr;
        }
    }
    return *this;
}


//================================================================
// Amaya Joshi
// treeMin: return pointer to the minimum value in the tree
// Parametrs: none
// Return: BSTNode<T>*
//=================================================================
template <typename T>
BSTNode<T>* BSTNode<T>::treeMin() {
    BSTNode<T>* current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}



//================================================================
// Aisha Barry
// treeMax: return pointer to the maximum value in the tree
// Parametrs: none
// Return: BSTNode<T>*
//=================================================================
template <typename T>
BSTNode<T>* BSTNode<T>::treeMax() {
    BSTNode<T>* current = this;
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
void BSTNode<T>::printPreOrderTraversal() const {
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
void BSTNode<T>::printInOrderTraversal() const {
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
void BSTNode<T>::printPostOrderTraversal() const {
    if (left)
        left->printPostOrderTraversal();
    if (right)
        right->printPostOrderTraversal();
    cout << data << " ";
}
