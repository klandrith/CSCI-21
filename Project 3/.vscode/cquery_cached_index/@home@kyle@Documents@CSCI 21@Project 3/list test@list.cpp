/*  Programmer: Kyle Landrith
    Dated Completed: 10/1/19
    Resources: Geeks for Geeks, Stack Overflow, Tutorialspoint
    Program accepts a single command line argument for a text file
    and parses the commands in the file and creates an instance of a
    doubly linked list and performs various functions on that list.
*/
#include <string>
#include <fstream>
#include "slist.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;

// function declarations
SList* createList(SList *list);
void clearList(SList *list);
SList* deleteList(SList *list);
void insertSorted(SList *list, string stringvalue);
void insertFront(SList *list, string stringvalue);
void insertBack(SList *list, string stringvalue);
void eliminateAllOf(SList *list, string stringvalue);
void eliminateFirstOf(SList *list, string stringvalue);
void getNumber(SList *list, string stringvalue);
void getNumberHead(SList *list);
void getNumberTail(SList *list);
void popHead(SList *list);
void popTail(SList *list);
void getSize(SList *list);
void printList(SList *list);

// main that accepts a single command line argument for a filename
int main (int argc, char *argv[]) {
  ifstream inFile(argv[1]);
  //error checking for command line arguments
  if (argc == 1) {
    cerr << "Error: No file name entered. Exiting..." << endl;
    return 1;
  }
  if (!inFile.good()) {
    cerr << "Error: No file with that name. Exiting..." << endl;
    return 1;
  }
  if (argc >= 3) {
    cerr << "Too many arguments passed. Exiting..." << endl;
    return 1;
  }

  //create instance of SList
  SList *list;
  list = nullptr;
  string input;

  //while loop for parsing commands and calling respective functions
  while (!inFile.eof()) {
    getline(inFile, input);
    //only execute block if current line is not empty string
    if (input.length() > 0) {
      char command = input.at(0);
      string stringvalue;
      int length = input.length();
      switch (command) {
        case 'C':
          list = createList(list);
          break;
        case 'X':
          clearList(list);
          break;
        case 'D':
          deleteList(list);
          break;
        case 'I':
          stringvalue = input.substr(2, (length - 2));
          insertSorted(list, stringvalue);
          break;
        case 'F':
          stringvalue = input.substr(2, (length - 2));
          insertFront(list, stringvalue);
          break;
        case 'B':
          stringvalue = input.substr(2, (length - 2));
          insertBack(list, stringvalue);
          break;
        case 'E':
          stringvalue = input.substr(2, (length - 2));
          eliminateAllOf(list, stringvalue);
          break;
        case 'R':
          stringvalue = input.substr(2, (length - 2));
          eliminateFirstOf(list, stringvalue);
          break;
        case 'G':
          stringvalue = input.substr(2, (length - 2));
          getNumber(list, stringvalue);
          break;
        case 'A':
          getNumberHead(list);
          break;
        case 'Z':
          getNumberTail(list);
          break;
        case 'T':
          popHead(list);
          break;
        case 'K':
          popTail(list);
          break;
        case 'N':
          getSize(list);
          break;
        case 'P':
          printList(list);
          break;
        case '#':
          break;
        default:
          cerr << "Invalid input detected. Exiting..." << endl;
          return 1;
          break;
      }
    }
  }
  //close file
  inFile.close();
  return 0;
}

SList* createList(SList *list) {
  if (list != nullptr) {
    delete list;
  }
  list = new SList;
  cout << "LIST CREATED" << endl;
  return list;
}

void clearList(SList *list) {
  if (list != nullptr) {
    list->clear();
    cout << "LIST CLEARED" << endl;
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

SList* deleteList(SList *list) {
  if (list != nullptr) {
    delete list;
    list = nullptr;
    cout << "LIST DELETED" << endl;
    return list;
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

void insertSorted(SList *list, string stringvalue) {
  if (list != nullptr) {
    int value = std::stoi(stringvalue);
    list->insertSorted(value);
    cout << "VALUE " << value << " INSERTED" << endl;
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

void insertFront(SList *list, string stringvalue) {
  if (list != nullptr) {
    int value = std::stoi(stringvalue);
    list->insertFront(value);
    cout << "VALUE " << value << " ADDED TO HEAD" << endl;
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

void insertBack(SList *list, string stringvalue) {
  if (list != nullptr) {
    int value = std::stoi(stringvalue);
    list->insertBack(value);
    cout << "VALUE " << value << " ADDED TO TAIL" << endl;
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

void eliminateAllOf(SList *list, string stringvalue) {
  if (list != nullptr) {
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
}

void eliminateFirstOf(SList *list, string stringvalue) {
  if (list != nullptr) {
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
}

void getNumber(SList *list, string stringvalue) {
  if (list != nullptr) {
    int value = std::stoi(stringvalue);
    bool found = list->getNumber(value);
    if (found) {
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

void getNumberHead(SList *list) {
  if (list != nullptr) {
    if (list->getSize() != 0) {
      cout << "VALUE " << list->getNumberHead() << " AT HEAD" << endl;
    }
    else {
      cout << "LIST EMPTY" << endl;
    }
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

void getNumberTail(SList *list) {
  if (list != nullptr) {
    if (list->getSize() != 0) {
      cout << "VALUE " << list->getNumberTail() << " AT TAIL" << endl;
    }
    else {
      cout << "LIST EMPTY" << endl;
    }
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

void popHead(SList *list) {
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

void popTail(SList *list) {
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

void getSize(SList *list) {
  if (list != nullptr) {
    cout << "LIST SIZE IS " << list->getSize() << endl;
  }
  else {
    cout << "MUST CREATE LIST INSTANCE" << endl;
  }
}

void printList(SList *list) {
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
