#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

class RationalNumber {
private:
    int numerator;   
    int denominator; 
    
    // Utility functions
    void reduce();                    // Reduces the fraction to its simplest form
    int gcd(int a, int b) const;     // Calculates greatest common divisor
    void handleNegativeDenominator(); // Handles cases with negative denominators

public:
    // Constructor
    RationalNumber(int = 0, int = 1); // Default constructor with default arguments
    
    // Member functions
    void printRational() const;
    
    // Arithmetic operator overloads
    RationalNumber operator+(const RationalNumber&) const;
    RationalNumber operator-(const RationalNumber&) const;
    RationalNumber operator*(const RationalNumber&) const;
    RationalNumber operator/(const RationalNumber&) const;
    
    // Relational operator overloads
    bool operator>(const RationalNumber&) const;
    bool operator<(const RationalNumber&) const;
    bool operator>=(const RationalNumber&) const;
    bool operator<=(const RationalNumber&) const;
    bool operator==(const RationalNumber&) const;
    bool operator!=(const RationalNumber&) const;
};

#endif