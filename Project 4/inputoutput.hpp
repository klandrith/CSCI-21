/*  Programmer:     Kyle Landrith
    Date Completed: 11/1/19
    Resources: None
    Class declaration and implementation for an inputoutput function
    to take in a filename and handle the IO for a binary search tree
    program.

    OPERATION codes + descriptions

    CODE [argument] : description

    # any text      : ignore as comment
    C               : create dynamic tree instance
    X               : clear the current tree instance of contents
    D               : delete the dynamic tree instance and set to nullptr
    I word          : insert word (string) into the tree
    F word          : find word (string) in the tree
    R word          : remove word (string) from the tree
    G word          : get word (string) from the tree
    N               : return the size (number of nodes) of the tree
    O               : in order print
    E               : reverse order print

*/

#pragma once

#include <iostream>
#include "bstree.hpp"
#include "word.h"
#include <string>
#include <fstream>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;
using std::exception;
using std::remove;

class InputOutput {
public:
  // InputOutput handles parsing the input file and calling DList functions
  void IOFunction(string filename) {
    // create a list pointer and other variables
    BSTree<Word> *tree = nullptr;
    string input;
    char command;
    ifstream inFile(filename);

    // while loop for parsing commands and calling respective functions in DList
    while (!inFile.eof()) {
      getline(inFile, input);
      // only execute block if current line in file is not empty string
      if (input.length() > 0) {
        command = input.at(0);
        try {
          // switch block for various command inputs to execute related functions
          // in BSTree
          switch (command) {
            // create tree instance
            case 'C':
              create(tree);
              break;
            // clear current tree instance of nodes
            case 'X':
              clear(tree);
              break;
            // delete current tree instance
            case 'D':
              deletetree(tree);
              break;
            // insert input into the tree
            case 'I':
              insert(input, tree);
              break;
            // insert number at front of list
            case 'F':
              find(input, tree);
              break;
            // remove first instance of a number
            case 'R':
              removeNode(input, tree);
              break;
            // find a value in list
            case 'G':
              get(input, tree);
              break;
            // print size of tree
            case 'N':
              getSize(tree);
              break;
            // print list contents
            case 'O':
              printInOrder(tree);
              break;
            case 'E':
              printReverseOrder(tree);
              break;
            // commented line in input file
            case '#':
              break;
            // unknown command in file
            default:
              cerr << "Invalid command detected in input file." << endl;
              break;
          }
        } catch (const exception &e) {
          cout << e.what() << endl;
        }
      }
    }
    // close file
    inFile.close();
  }
private:
  // create function to create a new tree instance
  void create(BSTree<Word> *&tree) {
    if (tree != nullptr) {
      delete tree;
    }
    tree = new BSTree<Word>;
    cout << "TREE CREATED" << endl;
  }

  // clear clears the current tree instance of nodes
  void clear(BSTree<Word> *&tree) {
    if (tree != nullptr) {
      tree->clear();
      cout << "TREE CLEARED" << endl;
    }
    else {
      throw std::logic_error("MUST CREATE TREE INSTANCE");
    }
  }

  // deletetree deletes the current tree instance and sets
  // tree to nullptr
  void deletetree(BSTree<Word> *&tree) {
    if (tree != nullptr) {
      delete tree;
      tree = nullptr;
      cout << "TREE DELETED" << endl;
    }
    else {
      throw std::logic_error("MUST CREATE TREE INSTANCE");
    }
  }

  // insert inserts a new node into the tree with the value
  // in via input
  void insert(string input, BSTree<Word> *&tree) {
    if (tree != nullptr) {
      int pos = input.find(" ");
      if (pos != string::npos) {
        string stringinput = input.substr(pos + 1);
        stringinput = rmCarriageReturn(stringinput);
        if (tree->insert(stringinput)) {
          cout << "WORD " << stringinput << " INSERTED" << endl;
        }
        else {
          Word* w = tree->get(stringinput);
          w->incrementCount();
          cout << "WORD " << stringinput << " INCREMENTED" << endl;
        }
      }
      else {
        throw std::logic_error("NO VALUE PASSED AFTER COMMAND");
      }
    }
    else {
      throw std::logic_error("MUST CREATE TREE INSTANCE");
    }
  }

  // find searchs the tree for the value passed in via input
  void find(string input, BSTree<Word> *&tree) {
    if (tree != nullptr) {
      int pos = input.find(" ");
      if (pos != string::npos) {
        string stringinput = input.substr(pos + 1);
        stringinput = rmCarriageReturn(stringinput);
        if (tree->getSize() == 0) {
          throw std::logic_error("TREE EMPTY");
        }
        else if (tree->find(stringinput)) {
          cout << "FOUND " << stringinput << endl;
        }
        else {
          cout << stringinput << " NOT FOUND" << endl;
        }
      }
      else {
        throw std::logic_error("NO VALUE PASSED AFTER COMMAND");
      }
    }
    else {
      throw std::logic_error("MUST CREATE TREE INSTANCE");
    }
  }

  // remove removes a node from the tree if there is a node
  // that matches the value passed in via input
  void removeNode(string input, BSTree<Word> *&tree) {
    if (tree != nullptr) {
      int pos = input.find(" ");
      if (pos != string::npos) {
        string stringinput = input.substr(pos + 1);
        stringinput = rmCarriageReturn(stringinput);
        if (tree->getSize() == 0) {
          throw std::logic_error("TREE EMPTY");
        }
        else if (tree->remove(stringinput)) {
          cout << "REMOVED " << stringinput << endl;
        }
        else {
          cout << stringinput << " NOT FOUND" << endl;
        }
      }
      else {
        throw std::logic_error("NO VALUE PASSED AFTER COMMAND");
      }
    }
    else {
      throw std::logic_error("MUST CREATE TREE INSTANCE");
    }
  }

  // getNode searchs the tree for the value passed in via input and
  // outputs the node value
  void get(string input, BSTree<Word> *&tree) {
    if (tree != nullptr) {
      int pos = input.find(" ");
      if (pos != string::npos) {
        string stringinput = input.substr(pos + 1);
        stringinput = rmCarriageReturn(stringinput);
        if (tree->getSize() == 0) {
          throw std::logic_error("TREE EMPTY");
        }
        else if (tree->find(stringinput)) {
          Word* w = tree->get(stringinput);
          int count = w->getCount();
          cout << "GOT " << w->outputWord()<< " " << w->getCount() << endl;
        }
        else {
          cout << stringinput << " NOT FOUND" << endl;
        }
      }
      else {
        throw std::logic_error("NO VALUE PASSED AFTER COMMAND");
      }
    }
    else {
      throw std::logic_error("MUST CREATE TREE INSTANCE");
    }
  }

  // getSize outputs the current size of the tree (number of nodes)
  void getSize(BSTree<Word> *&tree) {
    if (tree != nullptr) {
      cout << "TREE SIZE IS " << tree->getSize() << endl;
    }
    else {
      throw std::logic_error("MUST CREATE TREE INSTANCE");
    }
  }

  // printInOrder prints the contents of the tree in ascending order
  void printInOrder(BSTree<Word> *&tree) {
    if (tree != nullptr) {
      if (tree->getSize() != 0) {
        tree->printInOrder();
      }
      else {
        throw std::logic_error("TREE EMPTY");
      }
    }
    else {
      throw std::logic_error("MUST CREATE TREE INSTANCE");
    }
  }

  // printReverseOrder prints the contents of the tree in descending order
  void printReverseOrder(BSTree<Word> *&tree) {
    if (tree != nullptr) {
      if (tree->getSize() != 0) {
        tree->printReverseOrder();
      }
      else {
        throw std::logic_error("TREE EMPTY");
      }
    }
    else {
      throw std::logic_error("MUST CREATE TREE INSTANCE");
    }
  }

  // rmCarriageReturn removes '\r' from any input for POSIX compaitibility
  string rmCarriageReturn(string input) {
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());
    return input;
  }
};
