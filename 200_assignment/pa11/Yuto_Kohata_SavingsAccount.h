#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Yuto_Kohata_Account.h"

class SavingsAccount : public Account {
    friend std::ostream& operator<<(std::ostream& output, const SavingsAccount& account);
    friend SavingsAccount operator+(double amount, SavingsAccount& account);

private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate);
    double calculateInterest() const;

    // Operator overloads
    SavingsAccount& operator+=(double amount);
    SavingsAccount& operator-=(double amount);
    SavingsAccount operator+(double amount);
    SavingsAccount operator-(double amount);
    SavingsAccount& operator=(const SavingsAccount& right);
};

#endif