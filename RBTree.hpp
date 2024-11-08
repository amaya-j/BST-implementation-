//==============================================================
// Names: Aisha Barry, Omar Perez, Amaya Joshi
// Class: CS 271-01
// Date: 11/07/2024
// About: RBTree.hpp contains the declerations for implementations of
// the RBTree class.
//==============================================================

#ifndef RBTREE_HPP
#define RBTREE_HPP
#include "CustomExceptions.hpp"
#include "RBTreeNode.hpp"
#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class RBTree {
private:
    RBTreeNode<T>* root;
    long nodeCount;

    // Helper functions
    void leftRotate(RBTreeNode<T>* x);
    void rightRotate(RBTreeNode<T>* y);
    void insertFixup(RBTreeNode<T>* z);
    //void transplant(RBTreeNode<T>* u, RBTreeNode<T>* v);
    void deleteFixup(RBTreeNode<T>* x);
    void copyTree(RBTreeNode<T>*& thisRoot, RBTreeNode<T>* otherRoot, RBTreeNode<T>* otherNil);
    void destroyTree(RBTreeNode<T>* node);

    // Traversal helpers
    void printPreOrder(RBTreeNode<T>* node) const;
    void printInOrder(RBTreeNode<T>* node) const;
    void printPostOrder(RBTreeNode<T>* node) const;

public:

    RBTreeNode<T>* nil; // Sentinel node representing NIL

    // Default constructor
    RBTree();

    // Copy constructor
    RBTree(const RBTree<T>& other);

    // Destructor
    ~RBTree();

    // Assignment operator
    RBTree<T>& operator=(const RBTree<T>& other);

    // Methods
    void transplant(RBTreeNode<T>* u, RBTreeNode<T>* v);
    bool isEmpty() const;
    long size() const;
    RBTreeNode<T>* insert(T value);
    void remove(T value);
    RBTreeNode<T>* search(T value) const;
    RBTreeNode<T>* treeMin() const;
    RBTreeNode<T>* treeMax() const;
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;

};

#include "RBTree.cpp" // Include implementation for template class

#endif // RBTREE_HPP
