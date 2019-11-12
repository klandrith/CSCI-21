#include "slist.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
  string expression = "12+3*4/"; // RPN notation (reverse polish notation)
  SList<int> list;

  int x, y, result;

  for (char e : expression) {
    if (isdigit(e)) {
      list.pushFront(e - 48);
    } else { // looking for +, - , *, /
      y = list.front();
      list.popFront();
      x = list.front();
      list.popFront();

      if (e == '+')
        result = x + y;
      if (e == '-')
        result = x - y;
      if (e == '*')
        result = x*y;
      if (e == '/')
        result = x / y;

      list.pushFront(result);
    }
  }

  cout << expression << " evaluated = " << list.front() << endl;

  return 0;
}
