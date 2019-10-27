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
#include "inputoutput.hpp"
#include <cctype>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;

// function declaration
bool containsNumbers(string input);
string onlyNumbers(string input);

// main that accepts a single command line argument for a filename
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


  // create instance of SList and variables for input
  SList<unsigned int> *list;
  list = nullptr;
  string input;
  char command;

  // while loop for parsing commands and calling respective functions
  while (!inFile.eof()) {
    getline(inFile, input);
    // only execute block if current line in file is not empty string
    if (input.length() > 0) {
      command = input.at(0);
      // switch block for various command inputs to execute related functions
      // in SList
      switch (command) {
        case 'C':
          if (list != nullptr) {
            delete list;
          }
          list = new SList<unsigned int>;
          cout << "LIST CREATED" << endl;
          break;
        case 'X':
          if (list != nullptr) {
            list->clear();
            cout << "LIST CLEARED" << endl;
          }
          else {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          }
          break;
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
        case 'I':
          if (list != nullptr) {
            int pos = input.find(" ");
            if (pos != string::npos) {
              string stringvalue = input.substr(pos + 1);
              if (stringvalue != "" && containsNumbers(stringvalue)) {
                string numbers = onlyNumbers(stringvalue);
                int value = std::stoi(numbers);
                list->insertSorted(value);
                cout << "VALUE " << value << " INSERTED" << endl;
              }
            }
          }
          else {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          }
          break;
        case 'F':
          if (list != nullptr) {
            int pos = input.find(" ");
            if (pos != string::npos) {
              string stringvalue = input.substr(pos + 1);
              if (stringvalue != "" && containsNumbers(stringvalue)) {
                string numbers = onlyNumbers(stringvalue);
                int value = std::stoi(numbers);
                list->insertFront(value);
                cout << "VALUE " << value << " ADDED TO HEAD" << endl;
              }
            }
          }
          else {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          }
        case 'B':
          if (list != nullptr) {
            int pos = input.find(" ");
            if (pos != string::npos) {
              string stringvalue = input.substr(pos + 1);
              if (stringvalue != "" && containsNumbers(stringvalue)) {
                string numbers = onlyNumbers(stringvalue);
                int value = std::stoi(numbers);
                list->insertBack(value);
                cout << "VALUE " << value << " ADDED TO TAIL" << endl;
              }
            }
          }
          else {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          }
          break;
        case 'E':
          if (list != nullptr) {
            int pos = input.find(" ");
            if (pos != string::npos) {
              string stringvalue = input.substr(pos + 1);
              if (stringvalue != "" && containsNumbers(stringvalue)) {
                string numbers = onlyNumbers(stringvalue);
                int value = std::stoi(numbers);
                bool eliminated = list->eliminateAllOf(value);
                if (eliminated) {
                  cout << "VALUE " << value << " ELIMINATED" << endl;
                }
                else {
                  cout << "VALUE " << value << " NOT FOUND" << endl;
                }
              }
            }
          }
          else {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          }
          break;
        case 'R':
          if (list != nullptr) {
            int pos = input.find(" ");
            if (pos != string::npos) {
              string stringvalue = input.substr(pos + 1);
              if (stringvalue != "" && containsNumbers(stringvalue)) {
                string numbers = onlyNumbers(stringvalue);
                int value = std::stoi(numbers);
                bool eliminated = list->eliminateFirstOf(value);
                if (eliminated) {
                  cout << "VALUE " << value << " REMOVED" << endl;
                }
                else {
                  cout << "VALUE " << value << " NOT FOUND" << endl;
                }
              }
            }
          }
          else {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          }
          break;
        case 'G':
          if (list != nullptr) {
            int pos = input.find(" ");
            if (pos != string::npos) {
              string stringvalue = input.substr(pos + 1);
              if (stringvalue != "" && containsNumbers(stringvalue)) {
                string numbers = onlyNumbers(stringvalue);
                int value = std::stoi(numbers);
                if (list->get(value)) {
                  cout << "VALUE " << value << " FOUND" << endl;
                }
                else {
                  cout << "VALUE " << value << " NOT FOUND" << endl;
                }
              }
            }
          }
          else {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          }
          break;
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
        case 'N':
          if (list != nullptr) {
            cout << "LIST SIZE IS " << list->getSize() << endl;
          }
          else {
            cout << "MUST CREATE LIST INSTANCE" << endl;
          }
          break;
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
          break;
      }
    }
  }
  //close file
  inFile.close();
  return 0;
}

bool containsNumbers(string input) {
  int size = input.size();
  bool numbers = false;
  for (int i = 0; i < size; i++) {
    if (isdigit(input.at(i))) {
      numbers = true;
    }
  }
  return numbers;
}

string onlyNumbers(string input) {
  string temp;
  int size = input.size();
  for (int i = 0; i < size; i++) {
    if (isdigit(input.at(i))) {
      temp += input.at(i);
    }
  }
  return temp;
}
