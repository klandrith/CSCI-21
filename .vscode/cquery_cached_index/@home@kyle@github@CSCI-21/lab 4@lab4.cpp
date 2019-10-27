// Lab 4 -- C++ (re)fresher, pt 4
//
// Programmer name: Kyle Landrith
// Date completed:  9/7/19

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>
#include <string>
using std::ios;
using std::cout;
using std::string;
using std::stringstream;

struct Item {
  string name;
  double price;
  unsigned int quantity;
};

// Initialize an Item with values for its fields.
void initItem(Item &i, string name, double price, unsigned int quantity) {
  i = {name, price, quantity};
}

// Compute the total value of an item (price * quantity)
double totalValue(const Item &i) {
  return i.price * i.quantity;
}

// Reduce the quantity of an Item.
// If amount > Item.quantity, set Item.quantity to 0.
void reduceQuantity(Item &i, unsigned int amount) {
  if (i.quantity < amount) {
    i.quantity = 0;
  }
  else {
    i.quantity -= amount;
  }
}

// Increase the quantity of an Item.
void increaseQuantity(Item &i, unsigned int amount) {
  i.quantity += amount;
}

// Example: "Apples (price: $0.99, quantity: 3)"
// Use the "magic formula" to format the price.
string toString(const Item &i) {
  std::ostringstream oss;
  oss.setf(std::ios::fixed|std::ios::showpoint);
  oss.precision(2);
  oss << i.name << " (price $" << i.price << ", quantity: " << i.quantity << ")";
  return oss.str();
}

/*
 * Unit test.
 */

TEST_CASE("struct and helper functions") {
  //initItem()
  Item i;
  initItem(i, "Apples", 1.99, 10);
  CHECK(totalValue(i) == 19.90);
  reduceQuantity(i, 5);
  CHECK(toString(i) == "Apples (price $1.99, quantity: 5)");
  reduceQuantity(i, 15);
  CHECK(toString(i) == "Apples (price $1.99, quantity: 0)");
  increaseQuantity(i, 15);
  CHECK(toString(i) == "Apples (price $1.99, quantity: 15)");
}
