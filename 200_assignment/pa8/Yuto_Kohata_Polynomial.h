#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <string>

class Polynomial {
private:
    // Structure to represent a term in the polynomial
    struct Term {
        int coefficient;
        int exponent;
        
        // Constructor for Term
        Term(int coef = 0, int exp = 0) 
            : coefficient(coef), exponent(exp) {}
    };
    
    std::vector<Term> terms; // Vector to store terms
    
    // Utility function to sort terms by exponent
    void sortTerms();
    
    // Utility function to combine like terms
    void combineTerms();

public:
    // Constructor
    Polynomial();
    
    // Member functions
    void enterTerms();
    void printPolynomial() const;
    
    // Operator overloads
    Polynomial operator+(const Polynomial& rhs) const;
    Polynomial operator-(const Polynomial& rhs) const;
    Polynomial& operator=(const Polynomial& rhs);
    Polynomial& operator+=(const Polynomial& rhs);
    Polynomial& operator-=(const Polynomial& rhs);
};

#endif