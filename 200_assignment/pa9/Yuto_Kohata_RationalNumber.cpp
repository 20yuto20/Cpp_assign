#include <iostream>
#include <cstdlib>
#include "Yuto_Kohata_RationalNumber.h"
using namespace std;

// Constructor initializes the rational number with numerator and denominator
// Prevents zero denominator, reduces fraction, and handles negative denominators
RationalNumber::RationalNumber(int num, int den) {
    if (den == 0) {
        den = 1;
    }
    
    numerator = num;
    denominator = den;
    
    handleNegativeDenominator();
    reduce();
}

// Handles cases where denominator is negative by moving the negative sign to numerator
void RationalNumber::handleNegativeDenominator() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Displays the rational number in the format "numerator/denominator"
// If denominator is 1, only displays the numerator
void RationalNumber::printRational() const {
    if (denominator == 1) {
        cout << numerator;
    } else {
        cout << numerator << '/' << denominator;
    }
}

// Implements Euclidean algorithm to find the greatest common divisor
int RationalNumber::gcd(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Reduces the fraction by dividing both numerator and denominator by their GCD
void RationalNumber::reduce() {
    int gcdValue = gcd(numerator, denominator);
    numerator = numerator / gcdValue;
    denominator = denominator / gcdValue;
}

// Implements addition of rational numbers using the formula:
// a/b + c/d = (ad + bc)/(bd)
RationalNumber RationalNumber::operator+(const RationalNumber& r) const {
    int newNum = numerator * r.denominator + r.numerator * denominator;
    int newDen = denominator * r.denominator;
    return RationalNumber(newNum, newDen);
}

// Implements subtraction of rational numbers using the formula:
// a/b - c/d = (ad - bc)/(bd)
RationalNumber RationalNumber::operator-(const RationalNumber& r) const {
    int newNum = numerator * r.denominator - r.numerator * denominator;
    int newDen = denominator * r.denominator;
    return RationalNumber(newNum, newDen);
}

// Implements multiplication of rational numbers using the formula:
// (a/b) * (c/d) = (ac)/(bd)
RationalNumber RationalNumber::operator*(const RationalNumber& r) const {
    int newNum = numerator * r.numerator;
    int newDen = denominator * r.denominator;
    return RationalNumber(newNum, newDen);
}

// Implements division of rational numbers using the formula:
// (a/b) / (c/d) = (ad)/(bc)
RationalNumber RationalNumber::operator/(const RationalNumber& r) const {
    if (r.numerator == 0) {
        return RationalNumber(); // Returns 0/1 if dividing by zero
    }
    int newNum = numerator * r.denominator;
    int newDen = denominator * r.numerator;
    return RationalNumber(newNum, newDen);
}

// Implements comparison operators by cross multiplication
bool RationalNumber::operator>(const RationalNumber& r) const {
    return (numerator * r.denominator) > (r.numerator * denominator);
}

bool RationalNumber::operator<(const RationalNumber& r) const {
    return (numerator * r.denominator) < (r.numerator * denominator);
}

bool RationalNumber::operator>=(const RationalNumber& r) const {
    return !(*this < r);
}

bool RationalNumber::operator<=(const RationalNumber& r) const {
    return !(*this > r);
}

bool RationalNumber::operator==(const RationalNumber& r) const {
    return numerator == r.numerator && denominator == r.denominator;
}

bool RationalNumber::operator!=(const RationalNumber& r) const {
    return !(*this == r);
}