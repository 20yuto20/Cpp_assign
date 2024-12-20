// Yuto_Kohata_CheckingAccount.cpp
// COMSC 200 Fall 2024
// Programming Assignment 10

#include "Yuto_Kohata_CheckingAccount.h"
#include <iostream>

// Constructor
CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance) {
    transactionFee = (fee >= 0.0) ? fee : 0.0;
}

// Override credit function
bool CheckingAccount::credit(double amount) {
    if (Account::credit(amount)) {
        // If credit was successful, charge transaction fee
        return Account::debit(transactionFee);
    }
    return false;
}

// Override debit function
bool CheckingAccount::debit(double amount) {
    if (Account::debit(amount)) {
        // If debit was successful, charge transaction fee
        return Account::debit(transactionFee);
    }
    return false;
}