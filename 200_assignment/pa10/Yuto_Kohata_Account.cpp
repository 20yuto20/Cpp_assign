// Yuto_Kohata_Account.cpp
// COMSC 200 Fall 2024
// Programming Assignment 10

#include <iostream>
#include "Yuto_Kohata_Account.h"

// Constructor
Account::Account(double initialBalance) {
    // Validate initialBalance
    if (initialBalance >= 0.0) {
        balance = initialBalance;
    }
    else {
        balance = 0.0;
        std::cout << "Error: Initial balance cannot be negative. Balance set to 0.0" << std::endl;
    }
}

// Credit function
bool Account::credit(double amount) {
    balance += amount;
    return true;
}

// Debit function
bool Account::debit(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    else {
        std::cout << "Debit amount exceeded account balance." << std::endl;
        return false;
    }
}

// Get balance
double Account::getBalance() const {
    return balance;
}