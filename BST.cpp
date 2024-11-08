//==============================================================
// Names: Aisha Barry, Omar Perez, Amaya Joshi
// Class: CS 271-01
// Date: 11/07/2024
// About: BST.cpp contains the implementations for
// the BST class. Handling tree-wide structure and management.
//==============================================================



#include "BST.hpp"

//================================================================
// Amaya Joshi
// Default Constructor: makes a default node
// Parametrs: None
// Return: None
//=================================================================
template <typename T>
BST<T>::BST() : root(nullptr), nodeCount(0) {}


//================================================================
// Aisha Barry
// Copy Constructor: makes a copy of the parameter 
// Parametrs: BST<T>& other
// Return: None
//=================================================================
template <typename T>
BST<T>::BST(const BST<T>& other) : root(nullptr), nodeCount(0) {
    copyTree(this->root, other.root);
    this->nodeCount = other.nodeCount;
}



//================================================================
// Omar Perez
// Destructor: Deletes the node and the pointers
// Parametrs: None
// Return: None
//=================================================================
template <typename T>
BST<T>::~BST() {
    destroyTree(root);
}



//================================================================
// Amaya Joshi
// Assignment Operator: assigns parameter to this
// Parametrs: BST<T>& other
// Return: None
//=================================================================
template <typename T>
BST<T>& BST<T>::operator=(const BST<T>& other) {
    if (this != &other) {
        destroyTree(this->root);
        this->root = nullptr;
        copyTree(this->root, other.root);
        this->nodeCount = other.nodeCount;
    }
    return *this;
}



//================================================================
// Aisha Barry
// copyTree: thisRoot to otherRoot
// Parametrs: BSTNode<T>*& thisRoot, BSTNode<T>* otherRoot
// Return: None
//=================================================================
template <typename T>
void BST<T>::copyTree(BSTNode<T>*& thisRoot, BSTNode<T>* otherRoot) {
    if (otherRoot == nullptr) {
        thisRoot = nullptr;
    } else {
        thisRoot = new BSTNode<T>();
        thisRoot->data = otherRoot->data;
        copyTree(thisRoot->left, otherRoot->left);
        if (thisRoot->left != nullptr) {
            thisRoot->left->parent = thisRoot;
        }
        copyTree(thisRoot->right, otherRoot->right);
        if (thisRoot->right != nullptr) {
            thisRoot->right->parent = thisRoot;
        }
    }
}



//================================================================
// Omar Perez
// destroyTree: deletes the entire tree rooted at this
// Parametrs: BSTNode<T>* node
// Return: None
//=================================================================
template <typename T>
void BST<T>::destroyTree(BSTNode<T>* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}



//================================================================
// Amaya Joshi
// printPreOrder: helper for printPreOrderTraversal()
// Parametrs: BSTNode<T>* node
// Return: None
//=================================================================
template <typename T>
void BST<T>::printPreOrder(BSTNode<T>* node) const {
    if (node != nullptr) {
        cout << node->data << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}


//================================================================
// Aisha Barry
// printInOrder: helper for printInOrderTraversal()
// Parametrs: BSTNode<T>* node
// Return: None
//=================================================================
template <typename T>
void BST<T>::printInOrder(BSTNode<T>* node) const {
    if (node != nullptr) {
        printInOrder(node->left);
        cout << node->data << " ";
        printInOrder(node->right);
    }
}


//================================================================
// Omar Perez
// printPostOrder: helper for printPostOrderTraversal()
// Parametrs: BSTNode<T>* node
// Return: None
//=================================================================
template <typename T>
void BST<T>::printPostOrder(BSTNode<T>* node) const {
    if (node != nullptr) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << " ";
    }
}


//================================================================
// Amaya Joshi
// transplant: implementing transplant from the textbook
// Parametrs: BSTNode<T>* oldNode, BSTNode<T>* newNode
// Return: None
//=================================================================
template <typename T>
void BST<T>::transplant(BSTNode<T>* oldNode, BSTNode<T>* newNode) {
    if (oldNode->parent == nullptr) {
        root = newNode;
    } else if (oldNode == oldNode->parent->left) {
        oldNode->parent->left = newNode;
    } else {
        oldNode->parent->right = newNode;
    }
    if (newNode != nullptr) {
        newNode->parent = oldNode->parent;
    }
}


//================================================================
// Aisha Barry
// isEmpty: checks if the tree is empty
// Parametrs: BSTNode<T>* node
// Return: bool
//=================================================================
template <typename T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}



//================================================================
// Omar Perez
// size: returns the #nodes in the BST
// Parametrs: none
// Return: long
//=================================================================
template <typename T>
long BST<T>::size() const {
    return nodeCount;
}



//================================================================
// Amaya Joshi
// insert: inserts a node into the BST
// Parametrs: T value
// Return: BSTNode<T>*
//=================================================================
template <typename T>
BSTNode<T>* BST<T>::insert(T value) {
    BSTNode<T>* y = nullptr;
    BSTNode<T>* x = root;
    BSTNode<T>* z = new BSTNode<T>();
    z->data = value;

    while (x != nullptr) {
        y = x;
        if (value < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == nullptr) {
        root = z;
    } else if (value < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    nodeCount++;
    return z;
}



//================================================================
// Aisha Barry
// remove: removes a node from the BST
// Parametrs: T value
// Return: none
//=================================================================
template <typename T>
void BST<T>::remove(T value) {
    BSTNode<T>* z = search(value);
    if (z == nullptr) {
        throw ValueNotInTreeException();
    }

    if (z->left == nullptr) {
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        transplant(z, z->left);
    } else {
        BSTNode<T>* y = z->right->treeMin();
        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            if (y->right != nullptr) {
                y->right->parent = y;
            }
        }
        transplant(z, y);
        y->left = z->left;
        if (y->left != nullptr) {
            y->left->parent = y;
        }
    }

    delete z;
    nodeCount--;
}


//================================================================
// Omar Perez
// search: returns the pointer to the value to be searched
// Parametrs: T value
// Return: BSTNode<T>*
//=================================================================
template <typename T>
BSTNode<T>* BST<T>::search(T value) const {
    BSTNode<T>* x = root;
    while (x != nullptr && x->data != value) {
        if (value < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}


//================================================================
// Amaya Joshi
// treeMin: return pointer to the minimum value in the tree
// Parametrs: none
// Return: BSTNode<T>*
//=================================================================
template <typename T>
BSTNode<T>* BST<T>::treeMin() const {
    if (isEmpty()) {
        throw EmptyTreeException();
    }
    BSTNode<T>* x = root;
    while (x->left != nullptr) {
        x = x->left;
    }
    return x;
}



//================================================================
// Aisha Barry
// treeMax: return pointer to the maximum value in the tree
// Parametrs: none
// Return: BSTNode<T>*
//=================================================================
template <typename T>
BSTNode<T>* BST<T>::treeMax() const {
    if (isEmpty()) {
        throw EmptyTreeException();
    }
    BSTNode<T>* x = root;
    while (x->right != nullptr) {
        x = x->right;
    }
    return x;
}


//================================================================
// Omar Perez
// printPreOrderTraversal: prints value in tree in preorder.
// Parametrs: none
// Return: None
//=================================================================
template <typename T>
void BST<T>::printPreOrderTraversal() const {
    printPreOrder(root);
    cout << endl;
}



//================================================================
// Amaya Joshi
// printInOrderTraversal: prints value in tree in inorder.
// Parametrs: none
// Return: None
//=================================================================
template <typename T>
void BST<T>::printInOrderTraversal() const {
    printInOrder(root);
    cout << endl;
}



//================================================================
// Aisha Barry
// printPostOrderTraversal: prints value in tree in postorder.
// Parametrs: none
// Return: None
//=================================================================
template <typename T>
void BST<T>::printPostOrderTraversal() const {
    printPostOrder(root);
    cout << endl;
}
