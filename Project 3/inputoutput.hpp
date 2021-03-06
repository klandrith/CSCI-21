/*  Programmer:     Kyle Landrith
    Date Completed: 10/31/19
    Resources: None
    Class declaration and implementation for an inputoutput function
    to take in a filename and handle the IO for a double linked
    list program.

    OPERATION codes + descriptions

    CODE [argument] : description

    # any text      : ignore as comment
    C               : create dynamic list instance
    X               : clear the current list instance of contents
    D               : delete the dynamic list instance and set to nullptr
    I number        : insert number into list (sorted)
    F number        : add number to front of list
    B number        : add number to back of list
    E number        : eliminate all occurrences of number from the list
    R number        : remove the first occurrence of number from the list
    G number        : get number from the list
    A               : return contents of head node
    Z               : return contents of tail node
    T               : pop the head node
    K               : pop the tail node
    N               : return the size of the list
    P               : print all items in the list

*/
#pragma once

#include <iostream>
#include "dlist.hpp"
#include <string>
#include <fstream>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;
using std::stoi;
using std::exception;
using std::remove;

class InputOutput {
public:
  // InputOutput handles parsing the input file and calling DList functions
  void IOFunction(string filename) {
    // create a list pointer and other variables
    DList<unsigned int> *list = nullptr;
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
          // in DList
          switch (command) {
            // create list instance
            case 'C':
              create(list);
              break;
            // clear current list instance of nodes
            case 'X':
              clear(list);
              break;
            // delete current list instance
            case 'D':
              deletelist(list);
              break;
            // insert number into list in a sorted manner
            case 'I':
              insertSorted(input, list);
              break;
            // insert number at front of list
            case 'F':
              insertFront(input, list);
              break;
            // insert number at back of list
            case 'B':
              insertBack(input, list);
              break;
            // remove all of instances of a number
            case 'E':
              eliminateAllOf(input, list);
              break;
            // remove first instance of a number
            case 'R':
              eliminateFirstOf(input, list);
              break;
            // find a value in list
            case 'G':
              get(input, list);
              break;
            // output head node value
            case 'A':
              getHead(list);
              break;
            // output tail node value
            case 'Z':
              getTail(list);
              break;
            // remove head node
            case 'T':
              popHead(list);
              break;
            // remove tail node
            case 'K':
              popTail(list);
              break;
            // print size of list
            case 'N':
              getSize(list);
              break;
            // print list contents
            case 'P':
              printList(list);
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
          cerr << e.what() << endl;
        }
      }
    }
    // close file
    inFile.close();
  }
private:
  // create function creates a new list instance
  void create(DList<unsigned int> *&list) {
    if (list != nullptr) {
      delete list;
    }
    list = new DList<unsigned int>;
    cout << "LIST CREATED" << endl;
  }

  // clear clears the list instance of all contents
  void clear(DList<unsigned int> *&list) {
    if (list != nullptr) {
      list->clear();
      cout << "LIST CLEARED" << endl;
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  //deletelist deletes the list instance
  void deletelist(DList<unsigned int> *&list) {
    if (list != nullptr) {
      delete list;
      list = nullptr;
      cout << "LIST DELETED" << endl;
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // insertSorted inserts an item into the list sorted
  void insertSorted(string input, DList<unsigned int> *&list) {
    if (list != nullptr) {
      int pos = input.find(" ");
      string stringvalue = input.substr(pos + 1);
      stringvalue = rmCarriageReturn(stringvalue);
      int value = stringToInt(stringvalue);
      list->insertSorted(value);
      cout << "VALUE " << value << " INSERTED" << endl;
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // insertFront inserts an item into the list at the front of list
  void insertFront(string input, DList<unsigned int> *&list) {
    if (list != nullptr) {
      int pos = input.find(" ");
      string stringvalue = input.substr(pos + 1);
      stringvalue = rmCarriageReturn(stringvalue);
      int value = stringToInt(stringvalue);
      list->insertFront(value);
      cout << "VALUE " << value << " ADDED TO HEAD" << endl;
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // insertBack inserts an item into the list at the back of the list
  void insertBack(string input, DList<unsigned int> *&list) {
    if (list != nullptr) {
      int pos = input.find(" ");
      string stringvalue = input.substr(pos + 1);
      stringvalue = rmCarriageReturn(stringvalue);
      int value = stringToInt(stringvalue);
      list->insertBack(value);
      cout << "VALUE " << value << " ADDED TO TAIL" << endl;
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // eliminateAllOf eliminates all occurences of an item from the list
  void eliminateAllOf(string input, DList<unsigned int> *&list) {
    if (list != nullptr) {
      int pos = input.find(" ");
      string stringvalue = input.substr(pos + 1);
      stringvalue = rmCarriageReturn(stringvalue);
      int value = stringToInt(stringvalue);
      bool eliminated = list->eliminateAllOf(value);
      if (eliminated) {
        cout << "VALUE " << value << " ELIMINATED" << endl;
      }
      else {
        cout << "VALUE " << value << " NOT FOUND" << endl;
      }
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // eliminateFirstOf eliminates the first occurrence of an item from the list
  void eliminateFirstOf(string input, DList<unsigned int> *&list) {
    if (list != nullptr) {
      int pos = input.find(" ");
      string stringvalue = input.substr(pos + 1);
      stringvalue = rmCarriageReturn(stringvalue);
      int value = stringToInt(stringvalue);
      bool eliminated = list->eliminateFirstOf(value);
      if (eliminated) {
        cout << "VALUE " << value << " REMOVED" << endl;
      }
      else {
        cout << "VALUE " << value << " NOT FOUND" << endl;
      }
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // get searches the list for an item
  void get(string input, DList<unsigned int> *&list) {
    if (list != nullptr) {
      int pos = input.find(" ");
      string stringvalue = input.substr(pos + 1);
      stringvalue = rmCarriageReturn(stringvalue);
      int value = stringToInt(stringvalue);
      if (list->get(value)) {
        cout << "VALUE " << value << " FOUND" << endl;
      }
      else {
        cout << "VALUE " << value << " NOT FOUND" << endl;
      }
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // getHead outputs the value of the head node from the list
  void getHead(DList<unsigned int> *&list) {
    if (list != nullptr) {
      if (list->getSize() != 0) {
        cout << "VALUE " << list->getHead() << " AT HEAD" << endl;
      }
      else {
        cout << "LIST EMPTY" << endl;
      }
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // getTail outputs the value of the tail node from the list
  void getTail(DList<unsigned int> *&list) {
    if (list != nullptr) {
      if (list->getSize() != 0) {
        cout << "VALUE " << list->getTail() << " AT TAIL" << endl;
      }
      else {
        cout << "LIST EMPTY" << endl;
      }
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // popHead removes the head node from the list
  void popHead(DList<unsigned int> *&list) {
    if (list != nullptr) {
      if (list->getSize() != 0) {
        list->popHead();
        cout << "REMOVED HEAD" << endl;
      }
      else {
        cout << "LIST EMPTY" << endl;
      }
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // popTail removes the tail node from the list
  void popTail(DList<unsigned int> *&list) {
    if (list != nullptr) {
      if (list->getSize() != 0) {
        list->popTail();
        cout << "REMOVED TAIL" << endl;
      }
      else {
        cout << "LIST EMPTY" << endl;
      }
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // getSize outputs the size of the list
  void getSize(DList<unsigned int> *&list) {
    if (list != nullptr) {
      cout << "LIST SIZE IS " << list->getSize() << endl;
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // printList prints the contents of the list
  void printList(DList<unsigned int> *&list) {
    if (list != nullptr) {
      if (list->getSize() != 0) {
        list->printList();
      }
      else {
        cout << "LIST EMPTY" << endl;
      }
    }
    else {
      cout << "MUST CREATE LIST INSTANCE" << endl;
    }
  }

  // rmCarriageReturn removes '\r' from any input for POSIX compaitibility
  string rmCarriageReturn(string input) {
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());
    return input;
  }

  // converts a string to an int and returns it
  int stringToInt(string input) {
    for (int i = 0; i < input.size(); i++) {
      if (ispunct(input.at(i)) || isspace(input.at(i)) || isalpha(input.at(i))) {
        throw std::invalid_argument("VALUE PASSED IS NOT A NUMBER");
      }
    }
    return stoi(input);
  }
};
