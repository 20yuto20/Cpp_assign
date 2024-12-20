#include <iostream>
#include <iomanip>
#include "Yuto_Kohata_Account.h"
#include "Yuto_Kohata_SavingsAccount.h"
#include "Yuto_Kohata_CheckingAccount.h"
using namespace std;

int main() {
    cout << "Sample Run 4\n" << endl;
    cout << fixed << setprecision(2);

    // Create initial objects with different values
    Account a1(1250.0), a2(625.0);
    SavingsAccount s1(2500.0, 0.055), s2(1875.0, 0.055);
    CheckingAccount c1(3750.0, 2.5), c2(3125.0, 2.5);

    cout << "Initial balances using << operator:" << endl;
    cout << "Account 1: $" << a1 << endl;
    cout << "Savings 1: $" << s1 << endl;
    cout << "Checking 1: $" << c1 << endl << endl;

    // Testing += operator
    cout << "Testing += operator:" << endl;
    a1 += 375.0;
    s1 += 625.0;
    c1 += 875.0;
    cout << "Account 1 after += 375.0: $" << a1 << endl;
    cout << "Savings 1 after += 625.0: $" << s1 << endl;
    cout << "Checking 1 after += 875.0: $" << c1 << endl << endl;

    // Testing -= operator
    cout << "Testing -= operator:" << endl;
    a1 -= 225.0;
    s1 -= 475.0;
    c1 -= 725.0;
    cout << "Account 1 after -= 225.0: $" << a1 << endl;
    cout << "Savings 1 after -= 475.0: $" << s1 << endl;
    cout << "Checking 1 after -= 725.0: $" << c1 << endl << endl;

    // Testing + operator (both versions)
    cout << "Testing + operator (both versions):" << endl;
    Account a3 = a1 + 325.0;
    Account a4 = 330.0 + a1;
    SavingsAccount s3 = s1 + 425.0;
    SavingsAccount s4 = 430.0 + s1;
    CheckingAccount c3 = c1 + 525.0;
    CheckingAccount c4 = 530.0 + c1;
    
    cout << "Account: a1 + 325.0 = $" << a3 << endl;
    cout << "Account: 330.0 + a1 = $" << a4 << endl;
    cout << "Savings: s1 + 425.0 = $" << s3 << endl;
    cout << "Savings: 430.0 + s1 = $" << s4 << endl;
    cout << "Checking: c1 + 525.0 = $" << c3 << endl;
    cout << "Checking: 530.0 + c1 = $" << c4 << endl << endl;

    // Testing - operator
    cout << "Testing - operator:" << endl;
    Account a5 = a1 - 175.0;
    SavingsAccount s5 = s1 - 275.0;
    CheckingAccount c5 = c1 - 375.0;
    cout << "Account after - 175.0: $" << a5 << endl;
    cout << "Savings after - 275.0: $" << s5 << endl;
    cout << "Checking after - 375.0: $" << c5 << endl << endl;

    // Testing = operator
    cout << "Testing = operator:" << endl;
    Account a6 = a1;
    SavingsAccount s6 = s1;
    CheckingAccount c6 = c1;
    cout << "Account copy: $" << a6 << endl;
    cout << "Savings copy: $" << s6 << endl;
    cout << "Checking copy: $" << c6 << endl << endl;

    // Additional test for SavingsAccount
    double interest = s1.calculateInterest();
    cout << "Interest earned on Savings 1: $" << interest << endl;
    s1 += interest;
    cout << "Savings 1 after adding interest: $" << s1 << endl;

    system("pause");
    return 0;
}