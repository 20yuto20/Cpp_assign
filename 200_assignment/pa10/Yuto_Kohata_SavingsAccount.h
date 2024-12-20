// Yuto_Kohata_SavingsAccount.h
// COMSC 200 Fall 2024
// Programming Assignment 10

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Yuto_Kohata_Account.h"

class SavingsAccount : public Account {
private:
    double interestRate; // Interest rate (percentage)

public:
    // Constructor
    SavingsAccount(double initialBalance, double rate);
    
    // Calculate interest
    double calculateInterest() const;
};

#endif