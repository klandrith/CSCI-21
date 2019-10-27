// Lab 6 -- argc and argv, file input
//
// Programmer name: Kyle Landrith
// Date completed:  9/8/19

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::cerr;

struct Item {
  string name;
  unsigned int quantity;
};

void printItem(const Item &item) {
  cout << item.name << ", quantity: " << item.quantity << endl;
}

// Add functions as wanted/needed to help with file processing

int main(int argc, char *argv[]) {

  // If a filename argument has been passed via argv,
  // attempt to open the file and read its contents.
  //
  // Absence of a filename via argv should produce an error message.
  // A non-existent file should produce an error message.
  //
  // If the file can be opened, assume that it has an unknown
  // number of lines, with each line containing a NAME:QUANTITY
  // pair. (ex., "apples:10")
  //
  // Parse each line and populate the data fields in item,
  // then pass item to the printItem function. The output
  // of the function serves as confirmation that file and data
  // processing are functioning properly.

  ifstream inFile(argv[1]);

  if (argc == 1) {
    cerr << "Error: No file name entered. Exiting..." << endl;
    return 1;
  }
  if (!inFile.good()) {
    cerr << "Error: No file with that name. Exiting..." << endl;
    return 1;
  }

  string fruit;
  string temp;
  string quantityString;
  unsigned int quantity = 0;

  while (!inFile.eof()) {
    inFile >> temp;
    for (int i = 0; i < temp.size(); i++) {
        if (ispunct(temp.at(i))) {
          quantityString = temp.substr(i + 1, (temp.size() - 1));
          temp = temp.substr(0, i);
          quantity = std::stoi(quantityString);
          fruit = temp;
          Item nextItem = {fruit, quantity};
          printItem(nextItem);
        }
    }
  }
inFile.close();
return 0;
}
