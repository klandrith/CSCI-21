/*
  Name:         Kyle Landrith
  Description:  Main program file for a simulated vending machine that
                presents user with a menu displaying options, takes in
                money, returns change, and decrements inventory.
                Dated Completed: 9/24/19
*/

#include <iostream>
#include "CinReader.h"
#include <iomanip>

using std::cout;
using std::endl;

//function declaration
void ClearScreen();

//Drink struct definition
struct Drink {
  string name;
  double price;
  int number;
};

int main() {

  //create struct instances of various beverages
  Drink pepsi = {"Pepsi Cola", 1.75, 10};
  Drink mountaindew = {"Mountain Dew", 1.75, 10};
  Drink dietPepsi = {"Diet Pepsi", 1.75, 10};
  Drink dietDew = {"Diet Mountain Dew", 1.75, 10};
  Drink water = {"Bottled Water", 1.00, 10};

  //create and initialize various variables needed for program
  bool outofstock = false;
  bool exitMenu = false;
  char anotherSelection = 'y';
  int choice = 0;
  int itemsPurchased = 0;
  double priceTotal = 0.00;
  double moneyInserted = 0.00;
  double totalAmountSpent = 0.00;

  //create instance of cinreader
  CinReader reader;

  //Menu loop for vending machine
  do {
    outofstock = false;
    ClearScreen();
    //format cout to output to 2nd decimal place
    cout.setf(std::ios::fixed|std::ios::showpoint);
    cout.precision(2);

    //Menu for beverages and options
    cout << "Welcome to Campus Specialties Vending Machine." << endl;
    cout << "Below are your choices for tasty beverages." << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "1. " << pepsi.name;
    cout.width(10);
    cout << " $" << pepsi.price;
    cout.width(10);
    cout << " " << pepsi.number
         << " available." << endl;

    cout << "2. " << mountaindew.name;
    cout.width(8);
    cout << " $" << mountaindew.price;
    cout.width(10);
    cout << " " << mountaindew.number
         << " available." << endl;

    cout << "3. " << dietPepsi.name;
    cout.width(10);
    cout << " $" << dietPepsi.price;
    cout.width(10);
    cout << " " << dietPepsi.number
         << " available." << endl;

    cout << "4. " << dietDew.name;
    cout.width(3);
    cout << " $" << dietDew.price;
    cout.width(10);
    cout << " " << dietDew.number
         << " available." << endl;

    cout << "5. " << water.name;
    cout.width(7);
    cout << " $" << water.price;
    cout.width(10);
    cout << " " << water.number
              << " available." << endl;

    cout << "-----------------------------------------------" << endl;

    cout << "Please make your selection with the appropriate numbner." << endl;
    cout << "In order to exit the menu, press 6." << endl;
    choice = reader.readInt(1,6);


    //switch block for beverage selection, with catch for out of stock
    //so not to decrement to negatives
    switch (choice) {
      case 1:
        if (pepsi.number == 0) {
          cout << "That item is out of stock. Please make another selection." << endl;
          outofstock = true;
        }
        else {
          pepsi.number--;
          priceTotal = pepsi.price;
          itemsPurchased++;
        }
        break;
      case 2:
        if (mountaindew.number == 0) {
          cout << "That item is out of stock. Please make another selection." << endl;
          outofstock = true;
        }
        else {
          mountaindew.number--;
          priceTotal = mountaindew.price;
          itemsPurchased++;
        }
        break;
      case 3:
        if (dietPepsi.number == 0) {
          cout << "That item is out of stock. Please make another selection." << endl;
          outofstock = true;
        }
        else {
          dietPepsi.number--;
          priceTotal = dietPepsi.price;
          itemsPurchased++;
        }
        break;
      case 4:
        if (dietDew.number == 0) {
          cout << "That item is out of stock. Please make another selection." << endl;
          outofstock = true;
        }
        else {
          dietDew.number--;
          priceTotal = dietDew.price;
          itemsPurchased++;
        }
        break;
      case 5:
        if (water.number == 0) {
          cout << "That item is out of stock. Please make another selection." << endl;
          outofstock = true;
        }
        else {
          water.number--;
          priceTotal = water.price;
          itemsPurchased++;
        }
        break;
      case 6:
        exitMenu = true;
        break;
      default:
        cerr << "Invalid input!";
    }
    //prompt user to insert money with conditions to make sure they bought something
    //and that the item is not out of stock
    if (priceTotal > 0.00 && exitMenu != true && outofstock != true) {
      totalAmountSpent = totalAmountSpent + priceTotal;
      cout << "Please insert $" << priceTotal << endl;
      cout << "Input the dollar amount that you have inserted : ";
      moneyInserted = reader.readDouble();
    }
    //do while loop for inserting money and giving back change, if needed
    if (exitMenu != true && outofstock != true) {
      do {
        if (moneyInserted < priceTotal) {
          cout << "Please insert " << (priceTotal - moneyInserted) << " $ more: ";
          double moreMoney = reader.readDouble();
          moneyInserted = moreMoney + moneyInserted;
        }
        if (moneyInserted == priceTotal) {
          cout << "Thank you. No change is due." << endl;
        }
        if (moneyInserted > priceTotal){
          cout << "Thank you. You are due $" << (moneyInserted - priceTotal)
               << " back. Please take your change." << endl;
        }
      } while(moneyInserted < priceTotal);
    }
    //option to continue purchasing drinks
    if (exitMenu != true) {
      cout << "Would you like to make another selection? (Y/N)" << endl;
      anotherSelection = toupper(reader.readChar("YNyn"));
    }
  } while(exitMenu == false && anotherSelection == 'Y');

  //clearscreen at exitand display how much they've purchased
  ClearScreen();
  cout << "You have purchased " << itemsPurchased << " total items,"
       << " for a total of $" << totalAmountSpent << endl;

  return 0;
}

//clearscreen function
void ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}
