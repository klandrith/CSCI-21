#include "slist.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
  string expression = "(x + y)";
  SList<char> list;
  int result = 0;

  for (char e : expression) {
    if (e == '(') {
      list.pushFront(e);
    }
    else if (e == ')') {
      if (list.empty()) {
        result = 1;
        break;
      }
      else {
        list.popFront();
      }
    }
  }

if (!list.empty()) {
  result = -1;
}

if (result == -1) {
  cout << expression << " is left heavy" << endl;

}
else if (result == 0) {
  cout << expression << " is balanced" << endl;
}
else if (result == 1) {
  cout << expression << " is right heavy" << endl;
}

}
