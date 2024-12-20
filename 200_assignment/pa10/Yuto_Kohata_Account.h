// Yuto_Kohata_Account.h
// COMSC 200 Fall 2024
// Programming Assignment 10

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
private:
    double balance; // Account balance

public:
    // Constructor
    Account(double initialBalance);
    
    // Member functions
    virtual bool credit(double amount);
    virtual bool debit(double amount);
    double getBalance() const;
};

#endif