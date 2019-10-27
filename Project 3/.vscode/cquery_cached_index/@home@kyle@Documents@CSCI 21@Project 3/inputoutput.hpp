/*  Programmer: Kyle Landrith
    Dated Completed: 10/25/19
    I/O file for dynamic list program
*/

#pragma once

#include <iostream>
#include "dlist.hpp"
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;

class InputOutput {
  public:
    // Operations function
    void Operations(string filename) {
      string input;
      char command;
      ifstream inFile(filename);

      // while loop for parsing commands and calling respective functions
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
                int value = std::stoi(stringvalue);
                list->insertSorted(value);
                cout << "VALUE " << value << " INSERTED" << endl;
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
                int value = std::stoi(stringvalue);
                list->insertFront(value);
                cout << "VALUE " << value << " ADDED TO HEAD" << endl;
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
                int value = std::stoi(stringvalue);
                list->insertBack(value);
                cout << "VALUE " << value << " ADDED TO TAIL" << endl;
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
                int value = std::stoi(stringvalue);
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
              break;
            // remove first instance of a number
            case 'R':
              if (list != nullptr) {
                int pos = input.find(" ");
                string stringvalue = input.substr(pos + 1);
                int value = std::stoi(stringvalue);
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
              break;
            // find a value in list
            case 'G':
              if (list != nullptr) {
                int pos = input.find(" ");
                string stringvalue = input.substr(pos + 1);
                int value = std::stoi(stringvalue);
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
            case '#':
              // commented line in input file
              break;
            default:
              cerr << "Invalid input detected in input file." << endl;
              break;
          }
        }
      }
    }

  private:
    // create a list pointer
    DList<unsigned int> *list = nullptr;
};
