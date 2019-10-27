// Programmer name: Kyle Landrith
// Date completed:  10/22/19
// implementation file for word class

#include "word.h"

// Default constructor.
// Initialize the Word with empty string and 0 count.
Word::Word() {
  this->word = "";
  this->count = 1;
}

// Overloaded constructor.
// Initialize the Word with the string param and 0 count. Converts
// the string param to all upper-case.
Word::Word(string word) {
  this->word = upper(word);
  this->count = 1;
}

// Return this Word's integer attribute.
unsigned int Word::getCount() const {
  return this->count;
}

// Add 1 to this Word's integer attribute.
void Word::incrementCount() {
  this->count++;
}

// returns the string value of the current word
string Word::outputWord() {
  return word;
}

// Returns true if the string attributes of the two Word objects are equivalent.
// Case-insensitive.
bool Word::operator==(const Word &target) {
  string wordupper = this->word;
  string targetupper = target.word;
  if (wordupper.size() == targetupper.size()) {
    wordupper = upper(wordupper);
    targetupper = upper(targetupper);
    if (wordupper.compare(targetupper) == 0) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

// Returns true if this Word object's string attribute comes (lexicographically)
// after the target Word's string attribute. Case-insensitive.
bool Word::operator>(const Word &target) {
  string wordupper = this->word;
  string targetupper = target.word;
  wordupper = upper(wordupper);
  targetupper = upper(targetupper);
  if (std::lexicographical_compare(targetupper.begin(), targetupper.end(), wordupper.begin(), wordupper.end()) == true) {
      return true;
  }
  return false;
}

// Returns true if this Word object's string attribute comes (lexicographically)
// before the target Word's string attribute. Case-insensitive.
bool Word::operator<(const Word &target) {
  string wordupper = this->word;
  string targetupper = target.word;
  wordupper = upper(wordupper);
  targetupper = upper(targetupper);
  if (std::lexicographical_compare(wordupper.begin(), wordupper.end(), targetupper.begin(), targetupper.end()) == true) {
      return true;
  }
  return false;
}

// Example: APPLE 3
// Places a string representation of the Word on an output stream.
ostream &operator<<(ostream &outs, const Word &src) {
  return outs << src.word << " " << src.count;
}

// Helper function. Return the string param in all upper-case.
string Word::upper(string s) {
  for (int i = 0; i < s.length(); i++) {
    s.at(i) = std::toupper(s.at(i));
  }
  return s;
}
