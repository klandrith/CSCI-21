/*  Programmer: Kyle Landrith
    Dated Completed: 10/1/19
    Resources: Geeks for Geeks, Stack Overflow, Tutorialspoint
    Program accepts a single command line argument for a text file
    and parses the commands in the file and creates an instance of a
    doubly linked list and performs various functions on that list.
*/
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

// function declarations
void InputOutput(string filename);
string rmCarriageReturn(string input);

// main that accepts a single command line argument for a filename and calls
// InputOutput function for parsing and operations on list
int main (int argc, char *argv[]) {
  ifstream inFile(argv[1]);

  // error checking for command line arguments and successful file opening
  if (argc == 1) {
    cerr << "Error: No file name entered. USAGE: list [filename]" << endl;
    return 1;
  }
  if (argc >= 3) {
    cerr << "Too many arguments passed. USAGE: list [filename]" << endl;
    return 1;
  }
  if (!inFile.good()) {
    cerr << "Error: Unable to read file passed as argument. Exiting..." << endl;
    return 1;
  }

  // close file
  inFile.close();

  // call operations function and pass in filename
  InputOutput(argv[1]);

  return 0;
}

// InputOutput handles parsing the input file and calling DList functions
void InputOutput(string filename) {
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
            int value = stoi(stringvalue);
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
            stringvalue = rmCarriageReturn(stringvalue);
            int value = stoi(stringvalue);
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
            stringvalue = rmCarriageReturn(stringvalue);
            int value = stoi(stringvalue);
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
            stringvalue = rmCarriageReturn(stringvalue);
            int value = stoi(stringvalue);
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
            stringvalue = rmCarriageReturn(stringvalue);
            int value = stoi(stringvalue);
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
            stringvalue = rmCarriageReturn(stringvalue);
            int value = stoi(stringvalue);
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

// rmCarriageReturn removes '\r' from any input for POSIX compaitibility
string rmCarriageReturn(string input) {
  input.erase(remove(input.begin(), input.end(), '\r'), input.end());
  return input;
}
