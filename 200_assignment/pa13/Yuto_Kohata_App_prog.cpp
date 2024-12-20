#include <iostream>
#include <string>
#include "Yuto_Kohata_Array.h"
using namespace std;

int main() {
    // Create array objects for integers and strings
    Array<int> integers(5);
    Array<string> strings(5);

    // Get integer inputs from user
    cout << "Enter 5 integer values:" << endl;
    for (size_t i = 0; i < 5; ++i) {
        cin >> integers[i];
    }

    // Display integer array contents
    cout << "\nThe values in the integer Array are:\n";
    cout << integers << endl;

    // Get string inputs from user
    cout << "\nEnter 5 string values:" << endl;
    for (size_t i = 0; i < 5; ++i) {
        cin >> strings[i];
    }

    // Display string array contents
    cout << "\nThe values in the string Array are:\n";
    cout << strings << endl;

    cout << "\nPress any key to continue . . ." << endl;
    
    return 0;
}