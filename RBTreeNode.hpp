//==============================================================
// Names: Aisha Barry, Omar Perez, Amaya Joshi
// Class: CS 271-01
// Date: 11/07/2024
// About: RBTreeNode.hpp contains the declerations for implementations of
// the RBTreeNode class.
//==============================================================


#ifndef RBTREENODE_HPP
#define RBTREENODE_HPP

#include <iostream>

using namespace std;

// Define the Color enumeration for Red and Black
enum Color { RED, BLACK };

template <typename T>
class RBTreeNode {
public:
    T data;
    RBTreeNode<T>* left;
    RBTreeNode<T>* right;
    RBTreeNode<T>* parent;
    Color color;

    // Default constructor
    RBTreeNode();

    // Copy constructor
    RBTreeNode(const RBTreeNode<T>& other);

    // Assignment operator
    RBTreeNode<T>& operator=(const RBTreeNode<T>& other);

    // Methods
    RBTreeNode<T>* treeMin();
    RBTreeNode<T>* treeMax();
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;
};

#include "RBTreeNode.cpp"  // Include implementation for template class

#endif // RBTREENODE_HPP
