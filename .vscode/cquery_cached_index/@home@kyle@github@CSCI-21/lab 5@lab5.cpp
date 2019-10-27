// Lab 5 -- C++ (re)fresher, pt 5
//
// Programmer name: Kyle Landrith
// Date completed:  9/7/19

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bank_account.h"

TEST_CASE("BankAccount class") {
  BankAccount tomsAccount;
  BankAccount bobsAccount(12345678);
  BankAccount jillsAccount(30000, 3456789);
  BankAccount negativeInit(-1.50, 12345678);
  tomsAccount.deposit(500);
  CHECK(tomsAccount.withdraw(250) == true);
  CHECK(tomsAccount.withdraw(1000) == false);
  CHECK(tomsAccount.getBalance() == 250);
  CHECK(tomsAccount.getAccountNumber() == 0);
  CHECK(tomsAccount.toString() == "Account #0, Current balance $250.00");
  bobsAccount.deposit(1000);
  CHECK(bobsAccount.withdraw(500) == true);
  CHECK(bobsAccount.withdraw(1000) == false);
  CHECK(bobsAccount.getBalance() == 500);
  CHECK(bobsAccount.getAccountNumber() == 12345678);
  CHECK(bobsAccount.toString() == "Account #12345678, Current balance $500.00");
  CHECK(jillsAccount.withdraw(26000) == true);
  CHECK(jillsAccount.withdraw(100000) == false);
  jillsAccount.deposit(352.67);
  CHECK(jillsAccount.getBalance() == 4352.67);
  CHECK(jillsAccount.getAccountNumber() == 3456789);
  CHECK(jillsAccount.toString() == "Account #3456789, Current balance $4352.67");
  CHECK(negativeInit.getBalance() == 0);
  CHECK(negativeInit.withdraw(1000) == false);
}
