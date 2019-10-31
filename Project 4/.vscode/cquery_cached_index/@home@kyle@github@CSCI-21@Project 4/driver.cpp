/*  Programmer:       Kyle Landrith
    Dated Completed:  10/22/19
    Resources:        Geeks for Geeks, Stack Overflow, Tutorialspoint
                      https://stackoverflow.com/questions/2528995/remove-r-from-a-string-in-c

    Program accepts a single command line argument for a text file
    and parses the commands in the file and creates an instance of a
    templated binary search tree utilizing a word class and performs
    various operations on that tree...

*/

#include <string>
#include <fstream>
#include "bstree.hpp"
#include "word.h"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;
using std::remove;

// function declarations
void InputOutput(string filename);
string rmCarriageReturn(string input);

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

  //close input file
  inFile.close();

  // call operations function and pass in filename
  InputOutput(argv[1]);

  return 0;
}

// InputOutput handles parsing the input file and calling BSTree/Word functions
void InputOutput(string filename) {
  // create instance of BSTree and variables for input
  BSTree<Word> *tree;
  tree = nullptr;
  string input;
  char command;
  ifstream inFile(filename);

  // while loop for parsing commands and performing respective functions
  while (!inFile.eof()) {
    getline(inFile, input);
    // only execute block if current line in file is not empty string
    if (input.size() > 0) {
      command = input.at(0);
      // switch block for various command inputs to execute related functions
      // in tree
      switch (command) {
        // create tree
        case 'C':
          if (tree != nullptr) {
            delete tree;
          }
          tree = new BSTree<Word>;
          cout << "TREE CREATED" << endl;
          break;
        // clear tree
        case 'X':
          if (tree != nullptr) {
            tree->clear();
            cout << "TREE CLEARED" << endl;
          }
          else {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          }
          break;
        // delete tree
        case 'D':
          if (tree != nullptr) {
            delete tree;
            tree = nullptr;
            cout << "TREE DELETED" << endl;
          }
          else {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          }
          break;
        // insert node into tree
        case 'I':
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
          }
          else {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          }
          break;
        // find node in tree
        case 'F':
          if (tree != nullptr) {
            int pos = input.find(" ");
            if (pos != string::npos) {
              string stringinput = input.substr(pos + 1);
              stringinput = rmCarriageReturn(stringinput);
              if (tree->getSize() == 0) {
                cout << "TREE EMPTY" << endl;
              }
              else if (tree->find(stringinput)) {
                cout << "FOUND " << stringinput << endl;
              }
              else {
                cout << stringinput << " NOT FOUND" << endl;
              }
            }
          }
          else {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          }
          break;
        // remove node in tree
        case 'R':
          if (tree != nullptr) {
            int pos = input.find(" ");
            if (pos != string::npos) {
              string stringinput = input.substr(pos + 1);
              stringinput = rmCarriageReturn(stringinput);
              if (tree->getSize() == 0) {
                cout << "TREE EMPTY" << endl;
              }
              else if (tree->remove(stringinput)) {
                cout << "REMOVED " << stringinput << endl;
              }
              else {
                cout << stringinput << " NOT FOUND" << endl;
              }
            }
          }
          else {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          }
          break;
        // get node from tree (memory address)
        case 'G':
          if (tree != nullptr) {
            int pos = input.find(" ");
            if (pos != string::npos) {
              string stringinput = input.substr(pos + 1);
              stringinput = rmCarriageReturn(stringinput);
              if (tree->getSize() == 0) {
                cout << "TREE EMPTY" << endl;
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
          }
          else {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          }
          break;
        // output size of tree
        case 'N':
          if (tree != nullptr) {
            cout << "TREE SIZE IS " << tree->getSize() << endl;
          }
          else {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          }
          break;
        // print tree in ascending order
        case 'O':
          if (tree != nullptr) {
            if (tree->getSize() != 0) {
              tree->printInOrder();
            }
            else {
              cout << "TREE EMPTY" << endl;
            }
          }
          else {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          }
          break;
        // print tree in descending order
        case 'E':
          if (tree != nullptr) {
            if (tree->getSize() != 0) {
              tree->printReverseOrder();
            }
            else {
              cout << "TREE EMPTY" << endl;
            }
          }
          else {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          }
          break;
        // ignore as comment (not needed, only for clarification)
        case '#':
          break;
        // invalid command passed
        default:
        cerr << "Invalid input detected in input file." << endl;
        break;
      }
    }
  }
}

// rmCarriageReturn removes '\r' from any input for POSIX compaitibility
string rmCarriageReturn(string input) {
  input.erase(remove(input.begin(), input.end(), '\r'), input.end());
  return input;
}
