// Yuto_Kohata_SavingsAccount.cpp
// COMSC 200 Fall 2024
// Programming Assignment 10

#include "Yuto_Kohata_SavingsAccount.h"

// Constructor
SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance) {
    interestRate = (rate >= 0.0) ? rate : 0.0;
}

// Calculate interest
double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
}