#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
  int x(0), y(0);

  cout << "Enter a number: ";
  cin >> x;

  cout <<"Enter another number: ";
  cin >> y;

  cout << x << " + " << y << " = "
       << x + y << endl;


  return 0;
}
