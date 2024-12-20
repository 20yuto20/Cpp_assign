// Yuto_Kohata_CheckingAccount.h
// COMSC 200 Fall 2024
// Programming Assignment 10

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Yuto_Kohata_Account.h"

class CheckingAccount : public Account {
private:
    double transactionFee; // Fee charged per transaction

public:
    // Constructor
    CheckingAccount(double initialBalance, double fee);
    
    // Override credit and debit functions
    virtual bool credit(double amount) override;
    virtual bool debit(double amount) override;
};

#endif