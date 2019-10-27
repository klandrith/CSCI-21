// Programmer name: Kyle Landrith
// Date completed:  10/22/19
// Resources: https://www.techiedelight.com/deletion-from-bst/
//            https://stackoverflow.com/questions/8062080/deleting-the-entire-binary-search-tree-at-once
//            http://forum.codecall.net/topic/70039-solved-fill-binary-search-tree-using-recursion/

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

  // Find the target data in the tree. Returns true if target is found.
  // Returns false otherwise.
  bool find(T target) {
    return find(target, root);
  }

  // Remove the target data from the tree. Returns true if the target
  // is found and removed. Returns false otherwise.
  bool remove(T target) {
    return remove(target, root);
  }

  // Return a pointer to the target data. Returns nullptr if the target
  // data is not found.
  T *get(T target) {
    return get(target, root);
  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder() {
    printInOrder(root);
  }

  // Print the data in the tree to STDOUT, reverse-order (descending).
  void printReverseOrder() {
    printReverseOrder(root);
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
        delete troot;
        troot = nullptr;
      }
      //a node has only a left child
      else if(troot->leftChild != nullptr) {
        clear(troot->leftChild); //recursively clear the left tree
        delete troot;
        troot = nullptr;
      }
      //a node has only a right child
      else if(troot->rightChild != nullptr) {
        clear(troot->rightChild); //recursively clear the right tree
        delete troot;
        troot = nullptr;
      }
    }
  }

  bool insert(T newData, Node *&troot) {
    // check is newData already exists in tree, if so return false
    // and don't insert it into tree
    if (find(newData, troot)) {
      return false;
    }
    // if traversal down tree resulted in a nullptr on either right or left
    // side of current node, create newNode and assign memory location
    if (troot == nullptr) {
      Node* newNode = new Node(newData);
      troot = newNode;
      // increment size variable and return true for successful insertion
      size++;
      return true;
    }
    // traverse down left side of tree until insertion point if newData
    // is less than troot
    else if (newData < troot->data) {
      return insert(newData, troot->leftChild);
    }
    // traverse down right side of tree until insertion point if newData
    // is more than troot
    else {
      return insert(newData, troot->rightChild);
    }
  }

  bool find(T target, Node *troot) {
    // return false for either an empty tree or a tree without target
    if (troot == nullptr) {
      return false;
    }
    // return true if current troot->data equals target
    else if (troot->data == target) {
      return true;
    }
    // traverse down left side of tree if target is less
    else if (target < troot->data) {
      return find(target, troot->leftChild);
    }
    // traverse down right side of tree if target is more
    else if (target > troot->data) {
      return find(target, troot->rightChild);
    }
  }

  bool remove(T target, Node *&troot) {
    // return false if target not found in tree
    if (!find(target, troot)) {
      return false;
    }
    // traverse down left side of tree if target is less than current temproot
    if (target < troot->data) {
      return remove(target, troot->leftChild);
    }
    // traverse down right side of tree if target is more than current temproot
    else if (target > troot->data) {
      return remove(target, troot->rightChild);
    }
    else if (target == troot->data) {
      // troot has no children and can be deleted
      if (troot->leftChild == nullptr && troot->rightChild == nullptr) {
        delete troot;
        troot = nullptr;
        size--;
        return true;
      }
      // node has two children
      else if (troot->leftChild != nullptr && troot->rightChild != nullptr) {
        T predecessorData;

        removeMax(predecessorData, troot->leftChild);
        troot->data = predecessorData;
        size--;
        return true;
      }
      // node to be deleted has only one child node
      else {
        Node* child;
        // if no left child, child is troot->rightChild
        if (troot->leftChild == nullptr) {
          child = troot->rightChild;
        }
        // if no right child, child is troot->leftChild
        else {
          child = troot->leftChild;
        }
        // create pointer to current troot (node to be deleted)
        // assign troot to child node taking it's place
        // delete current node (target) and set deleted to true
        // for function return
        Node* current = troot;
        troot = child;
        delete current;
        size--;
        return true;
      }
    }
  }

  void removeMax(T &removed, Node *&troot) {
    // troot has no right child (it is the largest node in subtree),
    // and can be deleted, assigned removed to troot's data then delete,
    // and set troot pointer to nullptr
    if (troot->rightChild == nullptr) {
      removed = troot->data;
      delete troot;
      troot = nullptr;
    }
    // troot has a right child and must recursively travel down subtree
    // until reaching base case
    else {
      removeMax(removed, troot->rightChild);
    }
  }

  T *get(T target, Node *troot) {
    // target not in tree, or empty tree, return nullptr
    if (troot == nullptr) {
      return nullptr;
    }
    // target is equal to current troot, return memory location
    else if (troot->data == target) {
      return &troot->data;
    }
    // traverse down left side of tree if target is less
    else if (target < troot->data) {
      return get(target, troot->leftChild);
    }
    // traverse down right side of tree if target is more
    else if (target > troot->data) {
      return get(target, troot->rightChild);
    }
  }

  void printInOrder(Node *troot) {
    if (troot == nullptr)
        return;
    else {
        printInOrder(troot->leftChild);
        cout << troot->data << endl;;
        printInOrder(troot->rightChild);
    }
  }

  void printReverseOrder(Node *troot) {
    if (troot == nullptr)
        return;
    else {
        printReverseOrder(troot->rightChild);
        cout << troot->data << endl;;
        printReverseOrder(troot->leftChild);
    }
  }
};
