// Lab 13 -- recursion
//
// Programmer name: Kyle Landrith
// Date completed:  9/19/19

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>
#include <string>
#include <vector>
using std::string;
using std::stringstream;
using std::vector;

// Compute and return the factorial of value. 0 and 1 return 1.
// Recursive.
unsigned int factorial (unsigned int value) {
	if (value <= 1) {
		return 1;
	}
	else {
		return value * factorial(value - 1);
	}
}

// Return the nth value of the Fibonacci sequence.
// Recursive.
unsigned int fibonacci (unsigned int nth) {
	if (nth == 0) {
		return 0;
	}
	else if(nth == 1) {
		return 1;
	}
	else {
		return (fibonacci(nth - 1) + fibonacci(nth - 2));
	}
}

// Returns true if word is a palindrome. Returns false otherwise.
// Recursive.
bool wordIsPalindrome (string word) {
	unsigned int length = word.length();
	if (length <= 1) {
		return true;
	}
	if (word.at(0) == word.at(length - 1)) {
		return wordIsPalindrome(word.substr(1, length - 2));
	}
	else {
		return false;
	}

}

// Produces a string containing the contents of a vector, separated by single spaces,
// starting at a given index and going forward to the end of the vector.
// Recursive.
string vectorForwardsAsString (const vector<int>& v, unsigned int index) {
	stringstream stream;
	if (index == v.size() || index < 0) {
		return "";
	}
	else if (index == (v.size() - 1)) {
		stream << v.at(index) << " ";
		return stream.str();
	}
	else {
		stream << v.at(index) << " ";
		return stream.str() + vectorForwardsAsString(v, index + 1);
	}
}

// Produces a string containing the contents of a vector, separated by single spaces,
// starting at a given index and going backward to the end of the vector.
// Recursive.
string vectorBackwardsAsString (const vector<int>& v, int startIndex) {
	stringstream stream;
	if (startIndex == v.size() || startIndex < 0) {
		return "";
	}
	else if (startIndex == 0) {
		stream << v.at(startIndex) << " ";
		return stream.str();
	}
	else {
		stream << v.at(startIndex) << " ";
		return stream.str() + vectorBackwardsAsString(v, startIndex - 1);
	}

}

TEST_CASE("recursive functions") {

	SECTION("recursive factorial function") {
		CHECK(factorial(0) == 1);
		CHECK(factorial(1) == 1);
		CHECK(factorial(2) == 2);
		CHECK(factorial(5) == 120);
	}

	SECTION("recursive fibonacci function") {
		CHECK(fibonacci(1) == 1);
		CHECK(fibonacci(2) == 1);
		CHECK(fibonacci(3) == 2);
		CHECK(fibonacci(15) == 610);
	}

	SECTION("recursive wordIsPalindrome function") {
		CHECK(wordIsPalindrome("") == true);
		CHECK(wordIsPalindrome("a") == true);
		CHECK(wordIsPalindrome("sitonapotatopanotis") == true);
		CHECK(wordIsPalindrome("baseball") == false);
	}
}

TEST_CASE("recursive vector to string functions") {
	vector<int> numbers = {5, 10, 15, 20, 25};

	SECTION("recursive vector forwards as string function") {
		CHECK(vectorForwardsAsString(numbers, 0) == string("5 10 15 20 25 "));
		CHECK(vectorForwardsAsString(numbers, 3) == string("20 25 "));
		CHECK(vectorForwardsAsString(numbers, 5) == string(""));
	}

	SECTION("recursive vector backwards as string function") {
		CHECK(vectorBackwardsAsString(numbers, 4) == string("25 20 15 10 5 "));
		CHECK(vectorBackwardsAsString(numbers, 1) == string("10 5 "));
		CHECK(vectorBackwardsAsString(numbers, -1) == string(""));
	}
}
