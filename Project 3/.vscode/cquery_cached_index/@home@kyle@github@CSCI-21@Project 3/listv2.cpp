/*  Programmer: Kyle Landrith
    Dated Completed: 10/29/19
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
#include <stdexcept>

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
void createList(DList<unsigned int> *&list);
void clearList(DList<unsigned int> *&list);
void deleteList(DList<unsigned int> *&list);
void insertSorted(string stringvalue, DList<unsigned int> *&list);
void insertFront(string stringvalue, DList<unsigned int> *&list);
void insertBack(string stringvalue, DList<unsigned int> *&list);
void eliminateAllOf(string stringvalue, DList<unsigned int> *&list);
void eliminateFirstOf(string stringvalue, DList<unsigned int> *&list);
void get(string stringvalue, DList<unsigned int> *&list);
void getHead(DList<unsigned int> *&list);
void getTail(DList<unsigned int> *&list);
void popHead(DList<unsigned int> *&list);
void popTail(DList<unsigned int> *&list);
void getSize(DList<unsigned int> *&list);
void printList(DList<unsigned int> *&list);
string rmCarriageReturn(string input);
void stringToInt(string input, int &value);

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
      int pos = input.find(" ");
      string stringvalue = input.substr(pos + 1);
      stringvalue = rmCarriageReturn(stringvalue);
      // switch block for various command inputs to execute related functions
      // in DList
      switch (command) {
        // create list instance
        case 'C':
          createList(list);
          break;
        // clear current list instance of nodes
        case 'X':
          clearList(list);
          break;
        // delete current list instance
        case 'D':
          deleteList(list);
          break;
        // insert number into list in a sorted manner
        case 'I':
          insertSorted(stringvalue, list);
          break;
        // insert number at front of list
        case 'F':
          insertFront(stringvalue, list);
          break;
        // insert number at back of list
        case 'B':
          insertBack(stringvalue, list);
          break;
        // remove all of instances of a number
        case 'E':
          eliminateAllOf(stringvalue, list);
          break;
        // remove first instance of a number
        case 'R':
          eliminateFirstOf(stringvalue, list);
          break;
        // find a value in list
        case 'G':
          get(stringvalue, list);
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
    }
  }
  // close file
  inFile.close();
}

// createList creates a new instance of DList
void createList(DList<unsigned int> *&list) {
  if (list != nullptr) {
    delete list;
  }
  list = new DList<unsigned int>;
  cout << "LIST CREATED" << endl;
}

//clearList clears the current DList instance of contents
void clearList(DList<unsigned int> *&list) {
  if (list != nullptr) {
    list->clear();
    cout << "LIST CLEARED" << endl;
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

// deleteList deletes the current DList instance
void deleteList(DList<unsigned int> *&list) {
  if (list != nullptr) {
    delete list;
    list = nullptr;
    cout << "LIST DELETED" << endl;
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

// insertSorted inserts a value into the list (sorted)
void insertSorted(string stringvalue, DList<unsigned int> *&list) {
  if (list != nullptr) {
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
}

// insertFront inserts a value into the front of the list
void insertFront(string stringvalue, DList<unsigned int> *&list) {
  if (list != nullptr) {
    int value;
    try {
      stringToInt(stringvalue, value);
      list->insertFront(value);
      cout << "VALUE " << value << " ADDED TO TAIL" << endl;
    } catch (const exception &e) {
      cerr << e.what() << endl;
    }
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

// insertBack inserts a value into the back of the list
void insertBack(string stringvalue, DList<unsigned int> *&list) {
  if (list != nullptr) {
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
}

// eliminateAllOf eliminates all instances of a value in the list
void eliminateAllOf(string stringvalue, DList<unsigned int> *&list) {
  if (list != nullptr) {
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
}

// eliminateFirstOf eliminates the first instance of a value in the list
void eliminateFirstOf(string stringvalue, DList<unsigned int> *&list) {
  if (list != nullptr) {
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
}

// get attempts to find a value in the list
void get(string stringvalue, DList<unsigned int> *&list) {
  if (list != nullptr) {
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
}

// getHead gets the value of the head node of the list
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

// getTail gets the value of the tail node of the list
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

// converts a string to an int
void stringToInt(string input, int &value) {
  for (int i = 0; i < input.size(); i++) {
    if (ispunct(input.at(i)) || isspace(input.at(i)) || isalpha(input.at(i))) {
      throw std::invalid_argument("VALUE PASSED IS NOT A NUMBER");
    }
  }
  value = stoi(input);
}
