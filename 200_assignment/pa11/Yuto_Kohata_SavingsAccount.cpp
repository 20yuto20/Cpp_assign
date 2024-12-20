#include "Yuto_Kohata_SavingsAccount.h"

/* Constructor initializes base Account and interest rate */
SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance) {
    interestRate = (rate >= 0.0) ? rate : 0.0;
}

/* Calculate interest based on current balance */
double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
}

/* Stream insertion operator */
std::ostream& operator<<(std::ostream& output, const SavingsAccount& account) {
    output << account.getBalance();
    return output;
}

/* Addition assignment operator */
SavingsAccount& SavingsAccount::operator+=(double amount) {
    credit(amount);
    return *this;
}

/* Subtraction assignment operator */
SavingsAccount& SavingsAccount::operator-=(double amount) {
    debit(amount);
    return *this;
}

/* Addition operator (account + amount) */
SavingsAccount SavingsAccount::operator+(double amount) {
    SavingsAccount temp = *this;
    temp.credit(amount);
    return temp;
}

/* Addition operator (amount + account) */
SavingsAccount operator+(double amount, SavingsAccount& account) {
    return account + amount;
}

/* Subtraction operator */
SavingsAccount SavingsAccount::operator-(double amount) {
    SavingsAccount temp = *this;
    temp.debit(amount);
    return temp;
}

/* Assignment operator */
SavingsAccount& SavingsAccount::operator=(const SavingsAccount& right) {
    if (this != &right) {
        Account::operator=(right);
        interestRate = right.interestRate;
    }
    return *this;
}