// Lab 3 -- C++ (re)fresher, functions and testing
//
// Programmer name: Kyle Landrith
// Date completed:  9/5/19

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
using std::string;

// COMPLETE EACH OF THE FOLLOWING FUNCTIONS

// Return a greeting: "Nice to meet you, NAME."
// If name param is empty string, return "Nice to meet you."
string greet(string name) {
  if (name == "") {
    return "Nice to meet you.";
  }
  string greeting = "Nice to meet you, " + name + ".";
  return greeting;
}

// Return true if denominator is a factor of numerator.
// Return false otherwise.
bool isFactor(int numerator, int denominator) {
  int remain = 0;
  if (denominator == 0) {
    return false;
  }
  remain = numerator % denominator;
  if (remain == 0) {
    return true;
  }
  return false;
}

// Given an initial value, compute how many quarters, dimes, nickels, and
// pennies would be given as change.
void makeChange(unsigned int initialValue, unsigned int &quarters,
                unsigned int &dimes, unsigned int &nickels,
                unsigned int &pennies) {
  int temp = 0;
  quarters = initialValue / 25;
  temp = initialValue % 25;
  dimes = temp / 10;
  temp = temp % 10;
  nickels = temp / 5;
  temp = temp % 5;
  pennies = temp / 1;
}

// Convert a Celsius temperature to a Fahrenheit temperature.
float celsiusToFahrenheit(double celsiusTemp) {
  float fahrTemp = 0;
  fahrTemp = (celsiusTemp * 1.8000) +32.00;
  return fahrTemp;
}

// Convert a Fahrenheit temperature to a Celsius temperature.
float fahrenheitToCelsius(double fahrenheitTemp) {
  float celsTemp = 0;
  celsTemp = (fahrenheitTemp - 32.00) / 1.8000;
  return celsTemp;

}

/*
 * Unit test.
 */

TEST_CASE("Function implementations") {
  CHECK(greet("") == "Nice to meet you.");
  CHECK(greet("Bob") == "Nice to meet you, Bob.");
  CHECK(isFactor(25, 5) == true);
  CHECK(isFactor(8, 3) == false);
  CHECK(isFactor(5,0) == false);
  CHECK(celsiusToFahrenheit(32) == 89.6f);
  CHECK(fahrenheitToCelsius(32) == 0.0);
  float temp = (210 - 32) / 1.8000;
  CHECK(fahrenheitToCelsius(210) == temp);
  unsigned int initialValue = 0;
  unsigned int quarters = 0;
  unsigned int dimes = 0;
  unsigned int nickels = 0;
  unsigned int pennies = 0;
  makeChange(97,quarters, dimes, nickels, pennies);
  CHECK(quarters == 3);
  CHECK(dimes == 2);
  CHECK(nickels == 0);
  CHECK(pennies == 2);
  makeChange(41, quarters, dimes, nickels, pennies);
  CHECK(quarters == 1);
  CHECK(dimes == 1);
  CHECK(nickels == 1);
  CHECK(pennies == 1);
  makeChange(0, quarters, dimes, nickels, pennies);
  CHECK(quarters == 0);
  CHECK(dimes == 0);
  CHECK(nickels == 0);
  CHECK(pennies == 0);
}
