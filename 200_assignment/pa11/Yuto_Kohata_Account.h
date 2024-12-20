#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
    friend std::ostream& operator<<(std::ostream& output, const Account& account);
    friend Account operator+(double amount, Account& account);

private:
    double balance;

public:
    Account(double initialBalance);
    virtual bool credit(double amount);
    virtual bool debit(double amount);
    double getBalance() const;

    // Operator overloads
    Account& operator+=(double amount);
    Account& operator-=(double amount);
    Account operator+(double amount);
    Account operator-(double amount);
    Account& operator=(const Account& right);
};

#endif