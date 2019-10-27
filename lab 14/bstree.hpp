// Lab 14 -- binary search tree
//
// Programmer name: Kyle Landrith
// Date completed:  10/5/19
// Resources: https://stackoverflow.com/questions/8062080/deleting-the-entire-binary-search-tree-at-once
//            GeeksforGeeks
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
    bool found = false;
    Node* temproot = troot;
    while (temproot != nullptr && found == false) {
      // pass right subtree as new tree
      if (newData > temproot->data) {
        temproot = temproot->rightChild;
      }
      // pass left subtree as new tree
      else if (newData < temproot->data) {
        temproot = temproot->leftChild;
      }
      else if (newData == temproot->data) {
        found = true; // target is found in tree
      }
    }
    // newData not found, will be inserted into tree recursively if not first node
    if (!found) {
      if (troot == nullptr) {
        Node* newNode = new Node(newData);
        troot = newNode;
        // increment size variable and return true for successful insertion
        size++;
        return true;
      }
      else if (newData < troot->data) {
        insert(newData, troot->leftChild);
      }
      else {
        insert(newData, troot->rightChild);
      }
    }
    else {
      return false;
    }

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
