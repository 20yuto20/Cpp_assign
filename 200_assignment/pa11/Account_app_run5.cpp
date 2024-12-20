#include <iostream>
#include <iomanip>
#include "Yuto_Kohata_Account.h"
#include "Yuto_Kohata_SavingsAccount.h"
#include "Yuto_Kohata_CheckingAccount.h"
using namespace std;

int main() {
    cout << "Sample Run 5\n" << endl;
    cout << fixed << setprecision(2);

    // Create initial objects with different values
    Account a1(2000.0), a2(1000.0);
    SavingsAccount s1(4000.0, 0.045), s2(3000.0, 0.045);
    CheckingAccount c1(6000.0, 3.5), c2(5000.0, 3.5);

    cout << "Initial balances using << operator:" << endl;
    cout << "Account 1: $" << a1 << endl;
    cout << "Savings 1: $" << s1 << endl;
    cout << "Checking 1: $" << c1 << endl << endl;

    // Testing += operator
    cout << "Testing += operator:" << endl;
    a1 += 500.0;
    s1 += 750.0;
    c1 += 1000.0;
    cout << "Account 1 after += 500.0: $" << a1 << endl;
    cout << "Savings 1 after += 750.0: $" << s1 << endl;
    cout << "Checking 1 after += 1000.0: $" << c1 << endl << endl;

    // Testing -= operator
    cout << "Testing -= operator:" << endl;
    a1 -= 300.0;
    s1 -= 550.0;
    c1 -= 800.0;
    cout << "Account 1 after -= 300.0: $" << a1 << endl;
    cout << "Savings 1 after -= 550.0: $" << s1 << endl;
    cout << "Checking 1 after -= 800.0: $" << c1 << endl << endl;

    // Testing + operator (both versions)
    cout << "Testing + operator (both versions):" << endl;
    Account a3 = a1 + 400.0;
    Account a4 = 450.0 + a1;
    SavingsAccount s3 = s1 + 600.0;
    SavingsAccount s4 = 650.0 + s1;
    CheckingAccount c3 = c1 + 800.0;
    CheckingAccount c4 = 850.0 + c1;
    
    cout << "Account: a1 + 400.0 = $" << a3 << endl;
    cout << "Account: 450.0 + a1 = $" << a4 << endl;
    cout << "Savings: s1 + 600.0 = $" << s3 << endl;
    cout << "Savings: 650.0 + s1 = $" << s4 << endl;
    cout << "Checking: c1 + 800.0 = $" << c3 << endl;
    cout << "Checking: 850.0 + c1 = $" << c4 << endl << endl;

    // Testing - operator
    cout << "Testing - operator:" << endl;
    Account a5 = a1 - 200.0;
    SavingsAccount s5 = s1 - 400.0;
    CheckingAccount c5 = c1 - 600.0;
    cout << "Account after - 200.0: $" << a5 << endl;
    cout << "Savings after - 400.0: $" << s5 << endl;
    cout << "Checking after - 600.0: $" << c5 << endl << endl;

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