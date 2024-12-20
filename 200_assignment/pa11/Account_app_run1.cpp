#include <iostream>
#include <iomanip>
#include "Yuto_Kohata_Account.h"
#include "Yuto_Kohata_SavingsAccount.h"
#include "Yuto_Kohata_CheckingAccount.h"
using namespace std;

int main() {
    cout << "Sample Run 1\n" << endl;
    cout << fixed << setprecision(2);

    // Create initial objects
    Account a1(100.0), a2(50.0);
    SavingsAccount s1(200.0, 0.05), s2(150.0, 0.05);
    CheckingAccount c1(300.0, 2.0), c2(250.0, 2.0);

    cout << "Initial balances using << operator:" << endl;
    cout << "Account 1: $" << a1 << endl;          // Testing << for Account
    cout << "Savings 1: $" << s1 << endl;          // Testing << for SavingsAccount
    cout << "Checking 1: $" << c1 << endl << endl; // Testing << for CheckingAccount

    // Testing += operator for all classes
    cout << "Testing += operator:" << endl;
    a1 += 75.0;
    s1 += 150.0;
    c1 += 100.0;
    cout << "Account 1 after += 75.0: $" << a1 << endl;
    cout << "Savings 1 after += 150.0: $" << s1 << endl;
    cout << "Checking 1 after += 100.0: $" << c1 << endl << endl;

    // Testing -= operator for all classes
    cout << "Testing -= operator:" << endl;
    a1 -= 25.0;
    s1 -= 50.0;
    c1 -= 75.0;
    cout << "Account 1 after -= 25.0: $" << a1 << endl;
    cout << "Savings 1 after -= 50.0: $" << s1 << endl;
    cout << "Checking 1 after -= 75.0: $" << c1 << endl << endl;

    // Testing + operator (both versions) for all classes
    cout << "Testing + operator (both versions):" << endl;
    Account a3 = a1 + 80.0;           // Testing a + b
    Account a4 = 90.0 + a1;           // Testing b + a
    SavingsAccount s3 = s1 + 100.0;   // Testing a + b for SavingsAccount
    SavingsAccount s4 = 110.0 + s1;   // Testing b + a for SavingsAccount
    CheckingAccount c3 = c1 + 120.0;  // Testing a + b for CheckingAccount
    CheckingAccount c4 = 130.0 + c1;  // Testing b + a for CheckingAccount
    
    cout << "Account: a1 + 80.0 = $" << a3 << endl;
    cout << "Account: 90.0 + a1 = $" << a4 << endl;
    cout << "Savings: s1 + 100.0 = $" << s3 << endl;
    cout << "Savings: 110.0 + s1 = $" << s4 << endl;
    cout << "Checking: c1 + 120.0 = $" << c3 << endl;
    cout << "Checking: 130.0 + c1 = $" << c4 << endl << endl;

    // Testing - operator for all classes
    cout << "Testing - operator:" << endl;
    Account a5 = a1 - 20.0;
    SavingsAccount s5 = s1 - 30.0;
    CheckingAccount c5 = c1 - 40.0;
    cout << "Account after - 20.0: $" << a5 << endl;
    cout << "Savings after - 30.0: $" << s5 << endl;
    cout << "Checking after - 40.0: $" << c5 << endl << endl;

    // Testing = operator for all classes
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