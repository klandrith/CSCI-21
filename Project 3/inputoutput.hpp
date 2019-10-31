/*  Programmer:     Kyle Landrith
    Date Completed: 10/31/19
    Resources: None
    Class declaration and implementation for an inputoutput function
    to take in a filename and handle the IO for a double linked
    list program.
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
        // switch block for various command inputs to execute related functions
        // in DList
        switch (command) {
          // create list instance
          case 'C':
            if (list != nullptr) {
              delete list;
            }
            list = new DList<unsigned int>;
            cout << "LIST CREATED" << endl;
            break;
          // clear current list instance of nodes
          case 'X':
            if (list != nullptr) {
              list->clear();
              cout << "LIST CLEARED" << endl;
            }
            else {
              cout << "MUST CREATE LIST INSTANCE" << endl;
            }
            break;
          // delete current list instance
          case 'D':
            if (list != nullptr) {
              delete list;
              list = nullptr;
              cout << "LIST DELETED" << endl;
            }
            else {
              cout << "MUST CREATE LIST INSTANCE" << endl;
            }
            break;
          // insert number into list in a sorted manner
          case 'I':
            if (list != nullptr) {
              int pos = input.find(" ");
              string stringvalue = input.substr(pos + 1);
              stringvalue = rmCarriageReturn(stringvalue);
              int value;
              try {
                stringToInt(stringvalue, value);
                list->insertSorted(value);
                cout << "VALUE " << value << " INSERTED" << endl;
              } catch (const exception &e) {
                cerr << e.what() << endl;
              }
            }
            else {
              cout << "MUST CREATE LIST INSTANCE" << endl;
            }
            break;
          // insert number at front of list
          case 'F':
            if (list != nullptr) {
              int pos = input.find(" ");
              string stringvalue = input.substr(pos + 1);
              stringvalue = rmCarriageReturn(stringvalue);
              int value;
              try {
                stringToInt(stringvalue, value);
                list->insertFront(value);
                cout << "VALUE " << value << " ADDED TO HEAD" << endl;
              } catch (const exception &e) {
                cerr << e.what() << endl;
              }
            }
            else {
              cout << "MUST CREATE LIST INSTANCE" << endl;
            }
            break;
          // insert number at back of list
          case 'B':
            if (list != nullptr) {
              int pos = input.find(" ");
              string stringvalue = input.substr(pos + 1);
              stringvalue = rmCarriageReturn(stringvalue);
              int value;
              try {
                stringToInt(stringvalue, value);
                list->insertBack(value);
                cout << "VALUE " << value << " ADDED TO TAIL" << endl;
              } catch (const exception &e) {
                cerr << e.what() << endl;
              }
            }
            else {
              cout << "MUST CREATE LIST INSTANCE" << endl;
            }
            break;
          // remove all of instances of a number
          case 'E':
            if (list != nullptr) {
              int pos = input.find(" ");
              string stringvalue = input.substr(pos + 1);
              stringvalue = rmCarriageReturn(stringvalue);
              int value;
              try {
                stringToInt(stringvalue, value);
                bool eliminated = list->eliminateAllOf(value);
                if (eliminated) {
                  cout << "VALUE " << value << " ELIMINATED" << endl;
                }
                else {
                  cout << "VALUE " << value << " NOT FOUND" << endl;
                }
              } catch (const exception &e) {
                cerr << e.what() << endl;
              }
            }
            else {
              cout << "MUST CREATE LIST INSTANCE" << endl;
            }
            break;
          // remove first instance of a number
          case 'R':
            if (list != nullptr) {
              int pos = input.find(" ");
              string stringvalue = input.substr(pos + 1);
              stringvalue = rmCarriageReturn(stringvalue);
              int value;
              try {
                stringToInt(stringvalue, value);
                bool eliminated = list->eliminateFirstOf(value);
                if (eliminated) {
                  cout << "VALUE " << value << " REMOVED" << endl;
                }
                else {
                  cout << "VALUE " << value << " NOT FOUND" << endl;
                }
              } catch (const exception &e) {
                cerr << e.what() << endl;
              }
            }
            else {
              cout << "MUST CREATE LIST INSTANCE" << endl;
            }
            break;
          // find a value in list
          case 'G':
            if (list != nullptr) {
              int pos = input.find(" ");
              string stringvalue = input.substr(pos + 1);
              stringvalue = rmCarriageReturn(stringvalue);
              int value;
              try {
                stringToInt(stringvalue, value);
                if (list->get(value)) {
                  cout << "VALUE " << value << " FOUND" << endl;
                }
                else {
                  cout << "VALUE " << value << " NOT FOUND" << endl;
                }
              } catch (const exception &e) {
                cerr << e.what() << endl;
              }
            }
            else {
              cout << "MUST CREATE LIST INSTANCE" << endl;
            }
            break;
          // output head node value
          case 'A':
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
            break;
          // output tail node value
          case 'Z':
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
            break;
          // remove head node
          case 'T':
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
            break;
          // remove tail node
          case 'K':
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
            break;
          // print size of list
          case 'N':
            if (list != nullptr) {
              cout << "LIST SIZE IS " << list->getSize() << endl;
            }
            else {
              cout << "MUST CREATE LIST INSTANCE" << endl;
            }
            break;
          // print list contents
          case 'P':
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
            break;
          // commented line in input file
          case '#':
            break;
          // unknown command in file
          default:
            cerr << "Invalid input detected in input file." << endl;
            break;
        }
      }
    }
    // close file
    inFile.close();
  }
private:
  // rmCarriageReturn removes '\r' from any input for POSIX compaitibility
  string rmCarriageReturn(string input) {
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());
    return input;
  }

  // converts a string to an int and returns it
  void stringToInt(string input, int &value) {
    for (int i = 0; i < input.size(); i++) {
      if (ispunct(input.at(i)) || isspace(input.at(i)) || isalpha(input.at(i))) {
        throw std::invalid_argument("VALUE PASSED IS NOT A NUMBER");
      }
    }
    value = stoi(input);
  }
};
