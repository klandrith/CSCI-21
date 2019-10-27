/*
Name: Kyle Landrith

small program that creates a set of variables and assigns their values
based on user input. Performs a series of arithmetic operations on the integers
and floating point numbers, and formats the output of the floating point number
according to a user defined decimal point
*/


#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::string;


int main() {
  char char_input = 'a';
  bool bool_input = false;
  int int_input = 0;
  float float_input = 0.00;
  string string_input;
  int decimal_point = 0;

  cout << "Enter a single character... " << endl;
  cin >> char_input;
  cout << "Enter a 0 for false and a 1 for true..." << endl;
  cin >> bool_input;
  cout << "Enter an integer..." << endl;
  cin >> int_input;
  cout << "Enter a floating point number..." << endl;
  cin >> float_input;
  cout << "Enter a string of text..." << endl;
  cin.ignore(256, '\n');
  getline(cin, string_input);

  cout << "The variables you entered are... ";
  cout << char_input << " ";
  if (bool_input == 0) {
    cout << "false";
  }
  else {
    cout << "true";
  }
  cout << " "<< int_input << " " << float_input << " " << string_input << endl;

  cout << int_input << " times " << int_input << " is " << int_input * int_input << endl;
  cout << int_input << " divided by 2 with integer math is " << int_input / 2 << endl;
  cout << int_input << " minus 2 is " << int_input - 2 << endl;
  cout << int_input << " plus 2 is " << int_input + 2 << endl;
  cout << int_input << " mod 2 is " << (int_input % 2) << endl;
  cout << int_input << " incrememnted by 1 is " << endl;
  int_input++;
  cout << int_input << endl;
  cout << int_input << " decremented by 1 is " << endl;
  int_input--;
  cout << int_input << endl;

  cout << "Enter to what decimal point you want the floating point numbers outputted to: ";
  cin >> decimal_point;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(decimal_point);


  cout << float_input << " times " << float_input << " is " << float_input * float_input << endl;
  cout << float_input << " divided by 2 with floating point math is " << float_input * 2 << endl;
  cout << float_input << " minus 2 is " << float_input - 2 << endl;
  cout << float_input << " plus 2 is " << float_input + 2 << endl;

  return 0;
}
