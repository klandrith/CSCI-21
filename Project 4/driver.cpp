/*  Programmer:       Kyle Landrith
    Dated Completed:  11/1/19
    Resources:        Geeks for Geeks, Stack Overflow, Tutorialspoint
                      https://stackoverflow.com/questions/2528995/remove-r-from-a-string-in-c

    Program accepts a single command line argument for a text file
    and parses the commands in the file and creates an instance of a
    templated binary search tree utilizing a word class and performs
    various operations on that tree...

*/

#include <fstream>
#include "inputoutput.hpp"

using std::endl;
using std::ifstream;
using std::cerr;

// main that accepts a single command line argument for a filename
int main (int argc, char *argv[]) {
  ifstream inFile(argv[1]);
  // error checking for command line arguments and successful file opening
  if (argc == 1) {
    cerr << "Error: No file name entered. USAGE: driver [filename]" << endl;
    return 1;
  }
  if (argc >= 3) {
    cerr << "Too many arguments passed. USAGE: driver [filename]" << endl;
    return 1;
  }
  if (!inFile.good()) {
    cerr << "Error: Unable to read file passed as argument. Exiting..." << endl;
    return 1;
  }

  //close input file
  inFile.close();

  // create InputOutput class instance and call IO function
  // and pass in filename
  InputOutput io;
  io.IOFunction(argv[1]);

  return 0;
}
