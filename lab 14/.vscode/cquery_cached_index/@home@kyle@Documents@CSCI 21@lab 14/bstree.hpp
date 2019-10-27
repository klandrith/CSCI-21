// Lab 14 -- binary search tree
//
// Programmer name: Kyle Landrith
// Date completed:  10/5/19
// Resources: https://www.geeksforgeeks.org/iterative-searching-binary-search-tree/
//            https://www.geeksforgeeks.org/insert-a-node-in-binary-search-tree-iteratively/
//            https://stackoverflow.com/questions/8062080/deleting-the-entire-binary-search-tree-at-once

#pragma once

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class BSTree {
public:
  // Default constructor.
  // Initialize the tree with size 0 and null root.
  BSTree() {
    root = nullptr;
    size = 0;
  }

  // Destructor.
  // Clear the tree.
  ~BSTree() {
    clear();
  }

  // Returns the size (number of nodes) of this tree.
  unsigned int getSize() {
    return size;
  }

  // Clear the tree of all nodes. Reset head to nullptr and size to 0.
  void clear() {
    clear(root);
    size = 0;
  }

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool insert(T data) {
    return insert(data, root);
  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder() {
    printInOrder(root);
  }

private:
  unsigned int size; // the number of nodes in the tree

  // A binary search tree node with constructor.
  struct Node {
    T data;
    Node *leftChild;
    Node *rightChild;

    Node(T newData) : data(newData), leftChild(nullptr), rightChild(nullptr) {}
  } * root; // the root of the tree

  // Helper functions to hide internal node pointers from the public API.

  // clear is a recursively called function to delete all nodes in the list and free memory
  void clear(Node *&troot) {
    // execute code block if not an empty tree
    if(troot != nullptr) {
      //a node having no children
      if(troot->leftChild == nullptr && troot->rightChild == nullptr) {
        // delete current troot and change to nullptr
        delete troot;
        troot = nullptr;
      }
      //a node having two children
      else if (troot->leftChild != nullptr && troot->rightChild != nullptr) {
        clear(troot->leftChild); // recursively clear the left tree
        clear(troot->rightChild); //recursively clear the right tree
        clear(troot); //clear the node
      }
      //a node has only a left child
      else if(troot->leftChild != nullptr) {
        clear(troot->leftChild); //recursively clear the left tree
        clear(troot); //clear the node
      }
      //a node has only a right child
      else if(troot->rightChild != nullptr) {
        clear(troot->rightChild); //recursively clear the right tree
        clear(troot); //clear the node
      }
    }
  }

  // insert takes in newData and the root node and if it finds
  // that value already in the tree it returns false and does not insert it,
  // otherwise it inserts the value in order in the tree
  bool insert(T newData, Node *&troot) {
    // Create temproot node as not to disturb passed by reference root node
    // Traverse untill root reaches a dead end and finds newData value
    // and then returns false since data cannot be inserted (duplicate)
    Node* temproot = troot;
    while (temproot != nullptr) {
      // pass right subtree as new tree
      if (newData > temproot->data) {
        temproot = temproot->rightChild;
      }
      // pass left subtree as new tree
      else if (newData < temproot->data) {
        temproot = temproot->leftChild;
      }
      else {
        return false; // newData is found in tree and will not be inserted
      }
    }

    // following block is executed if newData is not found in tree
    // create newNode with newData value
    Node* newNode = new Node(newData);
    // assign temproot pointer to root to start traversing down the nodes
    temproot = troot;
    // pointer to maintain trailing pointer of temp
    Node* trailing = nullptr;

    // traverse down the tree until finding the last node to
    // find where in the tree newData will be inserted
    while (temproot != nullptr) {
      trailing = temproot;
      if (newData < temproot->data) {
        temproot = temproot->leftChild;
      }
      else {
        temproot = temproot->rightChild;
      }
    }

    // if trailing is nullptr (first node to be inserted) assign troot pointer to newNode
    if (trailing == nullptr) {
      troot = newNode;
    }
    // if the new data is less than trailing node data, assign leftChild to newNode
    else if (newData < trailing->data) {
      trailing->leftChild = newNode;
    }
    // if the new data is more than the trailing, assign rightChild to newNode
    else {
      trailing->rightChild = newNode;
    }
    // increment size variable and return true for successful insertion
    size++;
    return true;
  }

  // printInOrder is a recursively called function to print in ascending order
  void printInOrder(Node *troot) {
    if (troot == nullptr)
        return;
    else {
        printInOrder(troot->leftChild);
        cout << troot->data << endl;;
        printInOrder(troot->rightChild);
    }
  }
};
