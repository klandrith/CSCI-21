#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::stoi;
using std::exception;

int main() {
  try {
    int i = stoi("butt");

  } catch  (const exception &e) {
    cerr << e.what() << " called with invalid string" << endl;
  }

  return 0;
}
