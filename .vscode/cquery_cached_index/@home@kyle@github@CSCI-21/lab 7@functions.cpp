/*
  Name: Kyle Landrith
  Date Completed:9/8/19
*/
#include "functions.h"

// Read each line of a file into a vector.
vector<string> readFile(string filename) {
  vector<string> myVector;
  ifstream inFile;
  inFile.open(filename);
  string line;

  if (inFile.is_open()) {
    while (getline(inFile, line)) {
      myVector.push_back(line);
    }
    inFile.close();
  }
  return myVector;
}

// STRING PROCESSING -- ALL CASE-INSENSITIVE

// Return input with all characters in uppercase.
string toupper(string input) {
  for (int i = 0; i < input.length(); i++) {
    char tempChar = toupper(input.at(i));
    input.at(i) = tempChar;
  }
  return input;
}

// Return input with all characters in lowercase.
string tolower(string input) {
  for (int i = 0; i < input.length(); i++) {
    char tempChar = tolower(input.at(i));
    input.at(i) = tempChar;
  }
  return input;
}

// Return a count of all digits in the input.
unsigned int digits(string input) {
  unsigned int digits = 0;
  for (int i = 0; i < input.length(); i++) {
    if (isdigit(input.at(i))) {
      digits++;
    }
  }
  return digits;
}

// Return a count of all punctuation characters in the input.
unsigned int punctuation(string input) {
  unsigned int punct = 0;
  for (int i = 0; i < input.length(); i++) {
    if (ispunct(input.at(i))) {
      punct++;
    }
  }
  return punct;
}

// Return a count of all vowels (AEIOU) in the input.
unsigned int vowels(string input) {
  unsigned int vowels = 0;
  for (int i = 0; i < input.length(); i++) {
    if (input.at(i) == 'A' || input.at(i) == 'a') {
      vowels++;
    }
    if (input.at(i) == 'E' || input.at(i) == 'e') {
      vowels++;
    }
    if (input.at(i) == 'I' || input.at(i) == 'i') {
      vowels++;
    }
    if (input.at(i) == 'O' || input.at(i) == 'o') {
      vowels++;
    }
    if (input.at(i) == 'U' || input.at(i) == 'u') {
      vowels++;
    }
  }
  return vowels;
}

// VECTOR PROCESSING FUNCTIONS

// Compute total number of characters of all strings in a vector.
unsigned int allCharacters(const vector<string>& v) {
  unsigned int chars = 0;
  for (auto it = v.begin(); it != v.end(); it++) {
    string temp = *it;
    chars = chars + temp.length();
  }
  return chars;
}

// Compute total number of digits in all strings in a vector.
unsigned int allDigits(const vector<string>& v) {
  unsigned int digits = 0;
  for (auto it = v.begin(); it != v.end(); it++) {
    string temp = *it;
    for (int i = 0; i < temp.length(); i++) {
      if (isdigit(temp.at(i))) {
        digits++;
      }
    }
  }
  return digits;
}

// Compute total number of punctuation characters in all strings
// in a vector.
unsigned int allPunctuation(const vector<string>& v) {
  unsigned int punct = 0;
  for (auto it = v.begin(); it != v.end(); it++) {
    string temp = *it;
    for (int i = 0; i < temp.length(); i++) {
      if (ispunct(temp.at(i))) {
        punct++;
      }
    }
  }
  return punct;
}

unsigned int allVowels(const vector<string>& v) {
  unsigned int vCount(0);

  for (string s : v) {
    vCount += vowels(s);
  }
}

/*
// Compute tounsigned int allVowels(const vector<string>& v)tal number of vowels in all strings in a vector.
unsigned int allVowels(const vector<string>& v) {
  unsigned int vowels = 0;
  for (auto it = v.begin(); it != v.end(); it++) {
    string temp = *it;
    for (int i = 0; i < temp.length(); i++) {
      if (temp.at(i) == 'A' || temp.at(i) == 'a') {
        vowels++;
      }
      if (temp.at(i) == 'E' || temp.at(i) == 'e') {
        vowels++;
      }
      if (temp.at(i) == 'I' || temp.at(i) == 'i') {
        vowels++;
      }
      if (temp.at(i) == 'O' || temp.at(i) == 'o') {
        vowels++;
      }
      if (temp.at(i) == 'U' || temp.at(i) == 'u') {
        vowels++;
      }
    }
  }
  return vowels;
}
*/
