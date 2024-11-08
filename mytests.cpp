//==============================================================
// Names: Aisha Barry, Omar Perez, Amaya Joshi
// Class: CS 271-01
// Date: 11/07/2024
// About: mytests file for testing all the functions.
//==============================================================


#include <iostream>
#include "BST.hpp"
#include "RBTree.hpp"
#include "CustomExceptions.hpp"
using namespace std;

int main() {
    // Testing Binary Search Tree (BST)
    cout << "=== Testing Binary Search Tree (BST) ===" << endl;
    BST<int> bst;

    // Test isEmpty() and size()
    cout << "BST is empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;
    cout << "BST size: " << bst.size() << endl;

    // Insert elements into BST
    cout << "Inserting elements into BST: 50, 30, 70, 20, 40, 60, 80" << endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Test isEmpty() and size() again
    cout << "BST is empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;
    cout << "BST size: " << bst.size() << endl;

    // Test traversals
    cout << "BST Pre-order traversal: ";
    bst.printPreOrderTraversal();

    cout << "BST In-order traversal: ";
    bst.printInOrderTraversal();

    cout << "BST Post-order traversal: ";
    bst.printPostOrderTraversal();

    // Test search()
    int bstSearchValue = 40;
    BSTNode<int>* bstSearchResult = bst.search(bstSearchValue);
    if (bstSearchResult) {
        cout << "Found value " << bstSearchResult->data << " in BST." << endl;
    } else {
        cout << "Value " << bstSearchValue << " not found in BST." << endl;
    }

    // Test treeMin() and treeMax()
    try {
        cout << "BST minimum value: " << bst.treeMin()->data << endl;
        cout << "BST maximum value: " << bst.treeMax()->data << endl;
    } catch (EmptyTreeException& e) {
        cout << e.what() << endl;
    }

    // Test remove()
    cout << "Removing value 70 from BST." << endl;
    bst.remove(70);

    cout << "BST In-order traversal after removing 70: ";
    bst.printInOrderTraversal();

    // Test remove() with value not in the tree
    try {
        cout << "Attempting to remove value 100 from BST (not in tree)." << endl;
        bst.remove(100);
    } catch (ValueNotInTreeException& e) {
        cout << e.what() << endl;
    }

    // Test remove() all elements from BST
    cout << "Removing all elements from BST." << endl;
    bst.remove(50);
    bst.remove(30);
    bst.remove(20);
    bst.remove(40);
    bst.remove(60);
    bst.remove(80);

    cout << "BST is empty after removals? " << (bst.isEmpty() ? "Yes" : "No") << endl;
    cout << "BST size after removals: " << bst.size() << endl;

    // Test treeMin() on empty BST
    try {
        cout << "Attempting to find minimum value in an empty BST." << endl;
        bst.treeMin();
    } catch (EmptyTreeException& e) {
        cout << e.what() << endl;
    }

    // Testing Red-Black Tree (RBTree)
    cout << "\n=== Testing Red-Black Tree (RBTree) ===" << endl;
    RBTree<int> rbTree;

    // Test isEmpty() and size()
    cout << "RBTree is empty? " << (rbTree.isEmpty() ? "Yes" : "No") << endl;
    cout << "RBTree size: " << rbTree.size() << endl;

    // Insert elements into RBTree
    cout << "Inserting elements into RBTree: 10, 20, 30, 15, 25" << endl;
    rbTree.insert(10);
    rbTree.insert(20);
    rbTree.insert(30);
    rbTree.insert(15);
    rbTree.insert(25);

    // Test isEmpty() and size() again
    cout << "RBTree is empty? " << (rbTree.isEmpty() ? "Yes" : "No") << endl;
    cout << "RBTree size: " << rbTree.size() << endl;

    // Test traversals
    cout << "RBTree Pre-order traversal: ";
    rbTree.printPreOrderTraversal();

    cout << "RBTree In-order traversal: ";
    rbTree.printInOrderTraversal();

    cout << "RBTree Post-order traversal: ";
    rbTree.printPostOrderTraversal();

    // Test search()
    int rbTreeSearchValue = 15;
    RBTreeNode<int>* rbTreeSearchResult = rbTree.search(rbTreeSearchValue);
    if (rbTreeSearchResult != rbTree.nil) {
        cout << "Found value " << rbTreeSearchResult->data << " in RBTree." << endl;
    } else {
        cout << "Value " << rbTreeSearchValue << " not found in RBTree." << endl;
    }

    // Test treeMin() and treeMax()
    try {
        cout << "RBTree minimum value: " << rbTree.treeMin()->data << endl;
        cout << "RBTree maximum value: " << rbTree.treeMax()->data << endl;
    } catch (ValueNotInTreeException& e) {
        cout << e.what() << endl;
    }

    // Test remove()
    cout << "Removing value 20 from RBTree." << endl;
    //rbTree.remove(20);

    cout << "RBTree In-order traversal after removing 20: ";
    rbTree.printInOrderTraversal();

    // Test remove() with value not in the tree
    try {
        cout << "Attempting to remove value 100 from RBTree (not in tree)." << endl;
        rbTree.remove(100);
    } catch (ValueNotInTreeException& e) {
        cout << e.what() << endl;
    }

    // Test remove() all elements from RBTree
    //cout << "Removing all elements from RBTree." << endl;
    //rbTree.remove(10);
    //rbTree.remove(15);
    //rbTree.remove(25);
    //rbTree.remove(30);

    //cout << "RBTree is empty after removals? " << (rbTree.isEmpty() ? "Yes" : "No") << endl;
    cout << "RBTree size after removals: " << rbTree.size() << endl;

    // Test treeMin() on empty RBTree
    try {
        cout << "Attempting to find minimum value in an empty RBTree." << endl;
        rbTree.treeMin();
    } catch (ValueNotInTreeException& e) {
        cout << e.what() << endl;
    }

    // Test insert() after clearing the RBTree
    cout << "Inserting elements into RBTree: 40, 35, 45" << endl;
    rbTree.insert(40);
    rbTree.insert(35);
    rbTree.insert(45);

    cout << "RBTree In-order traversal after inserting new elements: ";
    rbTree.printInOrderTraversal();

    return 0;
}
