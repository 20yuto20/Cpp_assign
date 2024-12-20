#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Yuto_Kohata_Account.h"

class CheckingAccount : public Account {
    friend std::ostream& operator<<(std::ostream& output, const CheckingAccount& account);
    friend CheckingAccount operator+(double amount, CheckingAccount& account);

private:
    double transactionFee;

public:
    CheckingAccount(double initialBalance, double fee);
    virtual bool credit(double amount) override;
    virtual bool debit(double amount) override;

    // Operator overloads
    CheckingAccount& operator+=(double amount);
    CheckingAccount& operator-=(double amount);
    CheckingAccount operator+(double amount);
    CheckingAccount operator-(double amount);
    CheckingAccount& operator=(const CheckingAccount& right);
};

#endif