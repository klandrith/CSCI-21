#include "wordlist.h"

// Add a word to the words vector.
void WordList::addWord(string word) {
  words.push_back(word);
}

// Remove a word from the words vector.
// Return true on success.
bool WordList::removeWord(string word) {
  bool wordRemoved = false;
  for (auto it = words.begin(); it != words.end(); it++) {
    if (*it == word) {
      words.erase(it--);
      wordRemoved = true;
    }
  }
  return wordRemoved;
}

// Return true if the words vector contains the word.
bool WordList::hasWord(string word) {
  for (auto it = words.begin(); it != words.end(); it++) {
    if (*it == word) {
      return true;
    }
  }
  return false;
}

// Return the number of words, i.e., size of the vector.
unsigned int WordList::getWordCount() {
  return words.size();
}

// Clear all of the contents of the list.
void WordList::clear() {
  words.clear();
}

// Return a string representation of the word list.
// String will contain a numbered list, one word per line.
/*
 * EXAMPLE:
 *
 * [1] apple
 * [2] grapefruit
 * [3] orange
 *
 */
string WordList::toString() {
  string wordlist = "";
  unsigned int counter = 0;
  for (auto it = words.begin(); it != words.end(); it++) {
    string number = std::to_string(counter + 1);
    wordlist = wordlist + "[" + number + "] " + words.at(counter) + "\n";
    counter++;
  }
  if (words.size() == 0) {
    return "";
  }
  return wordlist;
}
