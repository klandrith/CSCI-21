// Programmer name: Kyle Landrith
// Date completed:  10/22/19
// Resources: https://stackoverflow.com/questions/23943728/case-insensitive-standard-string-comparison-in-c

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>

using std::ostream;
using std::string;

class Word {
public:
  // Default constructor.
  // Initialize the Word with empty string and 0 count.
  Word();

  // Overloaded constructor.
  // Initialize the Word with the string param and 0 count. Converts
  // the string param to all upper-case.
  Word(string word);

  // Return this Word's integer attribute.
  unsigned int getCount() const;

  // Add 1 to this Word's integer attribute.
  void incrementCount();

  // returns the string value of the current word
  string outputWord();

  // Returns true if the string attributes of the two Word objects are equivalent.
  // Case-insensitive.
  bool operator==(const Word &target);

  // Returns true if this Word object's string attribute comes (lexicographically)
  // after the target Word's string attribute. Case-insensitive.
  bool operator>(const Word &target);

  // Returns true if this Word object's string attribute comes (lexicographically)
  // before the target Word's string attribute. Case-insensitive.
  bool operator<(const Word &target);

  // Example: APPLE 3
  // Places a string representation of the Word on an output stream.
  friend ostream &operator<<(ostream &outs, const Word &src);

private:
  string word;
  unsigned int count;

  // Helper function. Return the string param in all upper-case.
  string upper(string s);
};