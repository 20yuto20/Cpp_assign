#include <iostream>
#include <iomanip>
#include "Yuto_Kohata_Account.h"
#include "Yuto_Kohata_SavingsAccount.h"
#include "Yuto_Kohata_CheckingAccount.h"
using namespace std;

int main() {
    cout << "Sample Run 2\n" << endl;
    cout << fixed << setprecision(2);

    // Create initial objects with different values
    Account a1(500.0), a2(250.0);
    SavingsAccount s1(1000.0, 0.06), s2(750.0, 0.06);
    CheckingAccount c1(1500.0, 3.0), c2(1250.0, 3.0);

    cout << "Initial balances using << operator:" << endl;
    cout << "Account 1: $" << a1 << endl;
    cout << "Savings 1: $" << s1 << endl;
    cout << "Checking 1: $" << c1 << endl << endl;

    // Testing += operator
    cout << "Testing += operator:" << endl;
    a1 += 200.0;
    s1 += 300.0;
    c1 += 400.0;
    cout << "Account 1 after += 200.0: $" << a1 << endl;
    cout << "Savings 1 after += 300.0: $" << s1 << endl;
    cout << "Checking 1 after += 400.0: $" << c1 << endl << endl;

    // Testing -= operator
    cout << "Testing -= operator:" << endl;
    a1 -= 150.0;
    s1 -= 250.0;
    c1 -= 350.0;
    cout << "Account 1 after -= 150.0: $" << a1 << endl;
    cout << "Savings 1 after -= 250.0: $" << s1 << endl;
    cout << "Checking 1 after -= 350.0: $" << c1 << endl << endl;

    // Testing + operator (both versions)
    cout << "Testing + operator (both versions):" << endl;
    Account a3 = a1 + 175.0;
    Account a4 = 180.0 + a1;
    SavingsAccount s3 = s1 + 225.0;
    SavingsAccount s4 = 230.0 + s1;
    CheckingAccount c3 = c1 + 275.0;
    CheckingAccount c4 = 280.0 + c1;
    
    cout << "Account: a1 + 175.0 = $" << a3 << endl;
    cout << "Account: 180.0 + a1 = $" << a4 << endl;
    cout << "Savings: s1 + 225.0 = $" << s3 << endl;
    cout << "Savings: 230.0 + s1 = $" << s4 << endl;
    cout << "Checking: c1 + 275.0 = $" << c3 << endl;
    cout << "Checking: 280.0 + c1 = $" << c4 << endl << endl;

    // Testing - operator
    cout << "Testing - operator:" << endl;
    Account a5 = a1 - 125.0;
    SavingsAccount s5 = s1 - 175.0;
    CheckingAccount c5 = c1 - 225.0;
    cout << "Account after - 125.0: $" << a5 << endl;
    cout << "Savings after - 175.0: $" << s5 << endl;
    cout << "Checking after - 225.0: $" << c5 << endl << endl;

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