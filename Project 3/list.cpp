/*  Programmer: Kyle Landrith
    Dated Completed: 10/1/19
    Resources: Geeks for Geeks, Stack Overflow, Tutorialspoint
    Program accepts a single command line argument for a text file
    and parses the commands in the file and creates an instance of a
    doubly linked list and performs various functions on that list.
*/
#include <iostream>
#include <fstream>
#include "inputoutput.hpp"

using std::endl;
using std::ifstream;
using std::cerr;

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

  // create InputOutput class instance and call IO function
  // and pass in filename
  InputOutput io;
  io.IOFunction(argv[1]);

  return 0;
}
