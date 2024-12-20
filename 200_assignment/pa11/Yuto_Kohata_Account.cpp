#include "Yuto_Kohata_Account.h"

/* Constructor initializes balance with validation */
Account::Account(double initialBalance) {
    if (initialBalance >= 0.0) {
        balance = initialBalance;
    }
    else {
        balance = 0.0;
        std::cout << "Error: Initial balance cannot be negative. Balance set to 0.0" << std::endl;
    }
}

/* Credit (add) an amount to the account */
bool Account::credit(double amount) {
    balance += amount;
    return true;
}

/* Debit (subtract) an amount from the account */
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

/* Return the current balance */
double Account::getBalance() const {
    return balance;
}

/* Stream insertion operator */
std::ostream& operator<<(std::ostream& output, const Account& account) {
    output << account.getBalance();
    return output;
}

/* Addition assignment operator */
Account& Account::operator+=(double amount) {
    credit(amount);
    return *this;
}

/* Subtraction assignment operator */
Account& Account::operator-=(double amount) {
    debit(amount);
    return *this;
}

/* Addition operator (account + amount) */
Account Account::operator+(double amount) {
    Account temp = *this;
    temp.credit(amount);
    return temp;
}

/* Addition operator (amount + account) */
Account operator+(double amount, Account& account) {
    return account + amount;
}

/* Subtraction operator */
Account Account::operator-(double amount) {
    Account temp = *this;
    temp.debit(amount);
    return temp;
}

/* Assignment operator */
Account& Account::operator=(const Account& right) {
    if (this != &right) {
        balance = right.balance;
    }
    return *this;
}