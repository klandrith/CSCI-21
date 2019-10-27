// Lab 9 -- pointers
//
// Programmer name: Kyle Landrith
// Date completed:  9/12/19

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using std::invalid_argument;
using std::ios;
using std::string;
using std::stringstream;

// Allocate memory for a string containing given contents.
// Return a pointer to the allocated string.
string* makeDynamicString (string contents) {
	string* stringPointer = new string;
	*stringPointer = contents;
	return stringPointer;
}

// Free the memory associated with a string and null the pointer.
// Throws std::invalid_argument("NULL STRING POINTER") if theString is nullptr.
void clearDynamicString (string*& theString) {
	if (theString == nullptr) {
		throw std::invalid_argument("NULL STRING POINTER");
	}
	else {
		delete theString;
		theString = nullptr;
	}
}

// Return the length of theString. Populate "alpha" with the number
// of alphabetic characters in theString. Populate "num" with the number
// of numeric characters in theString.
// Throws std::invalid_argument("NULL STRING POINTER") if theString is nullptr.
unsigned int countChars (string* theString, unsigned int& alpha, unsigned int& num) noexcept(false) {
	if (theString == nullptr) {
		throw std::invalid_argument("NULL STRING POINTER");
	}
	else {
		alpha = 0;
		num = 0;
		string temp = *theString;
		for (int i = 0; i < temp.length(); i++) {
			if (isalpha(temp.at(i))) {
				alpha++;
			}
		}
		for (int i = 0; i < temp.length(); i++) {
			if (isdigit(temp.at(i))) {
				num++;
			}
		}
		unsigned int chars = temp.length();
	  return chars;
	}
}

// Return true if theWord is found in theString. Return false otherwise.
// Throws std::invalid_argument("NULL STRING POINTER") if theString is nullptr.
bool findWord (string* theString, string theWord) noexcept(false) {
	if (theString == nullptr) {
		throw std::invalid_argument("NULL STRING POINTER");
	}
	else {
		string temp = *theString;
		if (temp.find(theWord) == string::npos) {
			return false;
		}
		else if (temp.find(theWord)) {
			return true;
		}
	}
}

// Replace oldWord with newWord in theString. If oldWord is not present, theString
// remains unaltered. Return true if the string has been altered. Return false
// otherwise. Case-sensitive.
//
// EXAMPLES:
//
// given -> theString="I like grapes.", oldWord="grapes", newWord="apples"
// on return -> theString="I like apples."
//
// Throws std::invalid_argument("NULL STRING POINTER") if theString is nullptr.
bool replaceWord (string* theString, string oldWord, string newWord) noexcept(false) {
	if (theString == nullptr) {
		throw std::invalid_argument("NULL STRING POINTER");
	}
	else {
		string temp = *theString;
		if (temp.find(oldWord) == string::npos) {
			return false;
		}
		else if (temp.find(oldWord)) {
			int location = temp.find(oldWord);
			int oldlength = oldWord.length();
			int newlength = newWord.length();
			temp.replace(location, oldlength, newWord, 0, newlength);
			*theString = temp;
			return true;
		}
	}
}

////////////////////////////////////////////////

struct Item {
	string name;
	float price;
	unsigned int quantity;

	Item(string name, float price, unsigned int quantity) {
		this->name = name;
		this->price = price;
		this->quantity = quantity;
	}
};

// Allocate memory for a dynamic Item, populated with the given data.
// Return a pointer to the newly allocated Item.
Item* makeDynamicItem (string newName, float newPrice, unsigned int newQuantity) {
	struct Item* dynamicItem = new Item(newName, newPrice, newQuantity);
	//*dynamicItem = {newName, newPrice, newQuantity};
	return dynamicItem;
}

// Free the memory associated with a dynamic Item and null the pointer.
// Throws std::invalid_argument("NULL ITEM POINTER") if item is nullptr.
void clearDynamicItem (Item*& item) noexcept(false) {
	if (item == nullptr) {
		throw std::invalid_argument("NULL STRING POINTER");
	}
	else {
		delete item;
		item = nullptr;
	}
}

// Update an Item with a new name, price, and quantity.
// Throws std::invalid_argument("NULL ITEM POINTER") if item is nullptr.
void updateItem (Item* item, string newName, float newPrice, unsigned int newQuantity) noexcept(false) {
	if (item == nullptr) {
		throw std::invalid_argument("NULL STRING POINTER");
	}
	else {
		item->name = newName;
		item->price = newPrice;
		item->quantity = newQuantity;
	}
}

// Return the price to purchase an Item (Item quantity * Item price).
// Throws std::invalid_argument("NULL ITEM POINTER") if item is nullptr.
float calculatePurchasePrice (Item* item) noexcept(false) {
	if (item == nullptr) {
		throw std::invalid_argument("NULL STRING POINTER");
	}
	else {
		return item->quantity * item->price;
	}
}

// Return a string representation of an Item.
//
// EXAMPLE: "book, 3 @ $5.99"
//
// Throws std::invalid_argument("NULL ITEM POINTER") if item is nullptr.
string toString (Item* item) noexcept(false) {
	if (item == nullptr) {
		throw std::invalid_argument("NULL STRING POINTER");
	}
	else {
		std::stringstream stream;
		stream << item->name << ", " << item->quantity << " @ $"
					 << std::fixed << std::setprecision(2) << item->price;
		return stream.str();
	}
}

/*
 * Unit test. Do not alter.
 */

TEST_CASE("dynamic string") {

	string* myString = nullptr;
	unsigned int alpha, num;

	CHECK_THROWS_AS(countChars(myString, alpha, num), invalid_argument);
	CHECK_THROWS_AS(findWord(myString, "hello"), invalid_argument);
	CHECK_THROWS_AS(replaceWord(myString, "hello", "goodbye"), invalid_argument);

	myString = makeDynamicString("123, abc; 456: hello. 0!");
	CHECK(myString != nullptr);
	CHECK(countChars(myString, alpha, num) == 24);
	CHECK(alpha == 8);
	CHECK(num == 7);
	CHECK(findWord(myString, "HELLO") == false);
	CHECK(findWord(myString, "abc") == true);

	CHECK(replaceWord(myString, "hello", "goodbye") == true);
	CHECK(*myString == string("123, abc; 456: goodbye. 0!"));
	CHECK(replaceWord(myString, "GOODBYE", "HELLO") == false);

	clearDynamicString(myString);
	CHECK(myString == nullptr);
}

TEST_CASE("dynamic item") {
	Item *item = nullptr;

  CHECK_THROWS_AS(clearDynamicItem(item), invalid_argument);
  CHECK_THROWS_AS(updateItem(item, "", 0, 0.0f), invalid_argument);
  CHECK_THROWS_AS(calculatePurchasePrice(item), invalid_argument);
  CHECK_THROWS_AS(toString(item), invalid_argument);

  item = makeDynamicItem("no name", 0.0, 0);

	CHECK(toString(item) == string("no name, 0 @ $0.00"));

	updateItem(item, "apples", 0.25f, 5);
	CHECK(item->name == string("apples"));
	CHECK(item->price == Approx(0.25f));
	CHECK(item->quantity == 5);
	CHECK(toString(item) == string("apples, 5 @ $0.25"));
	CHECK(calculatePurchasePrice(item) == Approx(1.25f));

	clearDynamicItem(item);
	CHECK(item == nullptr);
}
