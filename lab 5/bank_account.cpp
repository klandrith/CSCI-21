/*
 * Name: Kyle Landrith
 * Date Completed: 9/7/19
 *
 */

#include "bank_account.h"

// function implementations for class BankAccount
BankAccount::BankAccount() {
  balance_ = 0.00;
  accountNumber_ = 0;
}

// Initialize a BankAccount with balance=0.0 and accountNumber=accountNumber
BankAccount::BankAccount(unsigned int accountNumber) {
  balance_ = 0.00;
  accountNumber_ = accountNumber;
}

// Initialize a BankAccount with balance=balance and accountNumber=accountNumber
BankAccount::BankAccount(double balance, unsigned int accountNumber) {
  if (balance < 0) {
    balance_ = 0;
  }
  else {
    balance_ = balance;
  }
  accountNumber_ = accountNumber;
}

// Deposit funds. Balance will increase by amount.
void BankAccount::deposit(double amount) {
  balance_ += amount;
}

// If amount <= balance, reduce balance by amount and return true.
// Otherwise return false.
bool BankAccount::withdraw(double amount) {
  if (amount <= balance_) {
    balance_ -= amount;
    return true;
  }
  else {
    return false;
  }
}

// Return the balance.
double BankAccount::getBalance() {
  return balance_;
}

// Return the accountNumber.
unsigned int BankAccount::getAccountNumber() {
  return accountNumber_;
}

// Example: "Account #12345, Current balance $99.35"
// Use the "magic formula" to format the balance.
string BankAccount::toString() {
  std::ostringstream oss;
  oss.setf(std::ios::fixed|std::ios::showpoint);
  oss.precision(2);
  oss << "Account #" << accountNumber_ << ", Current balance $" << balance_;
  return oss.str();
}
