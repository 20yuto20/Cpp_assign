#include "Yuto_Kohata_CheckingAccount.h"

/* Constructor initializes base Account and transaction fee */
CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance) {
    transactionFee = (fee >= 0.0) ? fee : 0.0;
}

/* Credit amount and charge transaction fee */
bool CheckingAccount::credit(double amount) {
    if (Account::credit(amount)) {
        return Account::debit(transactionFee);
    }
    return false;
}

/* Debit amount and charge transaction fee */
bool CheckingAccount::debit(double amount) {
    if (Account::debit(amount)) {
        return Account::debit(transactionFee);
    }
    return false;
}

/* Stream insertion operator */
std::ostream& operator<<(std::ostream& output, const CheckingAccount& account) {
    output << account.getBalance();
    return output;
}

/* Addition assignment operator */
CheckingAccount& CheckingAccount::operator+=(double amount) {
    credit(amount);
    return *this;
}

/* Subtraction assignment operator */
CheckingAccount& CheckingAccount::operator-=(double amount) {
    debit(amount);
    return *this;
}

/* Addition operator (account + amount) */
CheckingAccount CheckingAccount::operator+(double amount) {
    CheckingAccount temp = *this;
    temp.credit(amount);
    return temp;
}

/* Addition operator (amount + account) */
CheckingAccount operator+(double amount, CheckingAccount& account) {
    return account + amount;
}

/* Subtraction operator */
CheckingAccount CheckingAccount::operator-(double amount) {
    CheckingAccount temp = *this;
    temp.debit(amount);
    return temp;
}

/* Assignment operator */
CheckingAccount& CheckingAccount::operator=(const CheckingAccount& right) {
    if (this != &right) {
        Account::operator=(right);
        transactionFee = right.transactionFee;
    }
    return *this;
}