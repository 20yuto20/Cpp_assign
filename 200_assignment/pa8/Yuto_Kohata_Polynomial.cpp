#include <iostream>
#include <algorithm>
#include "Yuto_Kohata_Polynomial.h"

// Constructor
Polynomial::Polynomial() {}

// Sort terms by exponent (descending order)
void Polynomial::sortTerms() {
    std::sort(terms.begin(), terms.end(), 
        [](const Term& a, const Term& b) { return a.exponent > b.exponent; });
}

// Combine like terms
void Polynomial::combineTerms() {
    if (terms.empty()) return;
    
    sortTerms();
    std::vector<Term> combined;
    
    for (size_t i = 0; i < terms.size(); ++i) {
        if (terms[i].coefficient == 0) continue;
        
        if (!combined.empty() && combined.back().exponent == terms[i].exponent) {
            combined.back().coefficient += terms[i].coefficient;
        } else {
            combined.push_back(terms[i]);
        }
    }
    
    terms = combined;
}

// Enter terms of the polynomial
void Polynomial::enterTerms() {
    int coefficient, exponent;
    char response;
    
    terms.clear();
    do {
        std::cout << "Enter coefficient: ";
        std::cin >> coefficient;
        std::cout << "Enter exponent: ";
        std::cin >> exponent;
        
        terms.push_back(Term(coefficient, exponent));
        
        std::cout << "Do you want to add another term (y or n)? ";
        std::cin >> response;
    } while (response == 'y' || response == 'Y');
    
    combineTerms();
}

// Print the polynomial
void Polynomial::printPolynomial() const {
    if (terms.empty()) {
        std::cout << "0";
        return;
    }
    
    bool firstTerm = true;
    for (const Term& term : terms) {
        if (term.coefficient == 0) continue;
        
        if (!firstTerm && term.coefficient > 0)
            std::cout << " + ";
        else if (!firstTerm && term.coefficient < 0)
            std::cout << " - ";
        else if (term.coefficient < 0)
            std::cout << "-";
            
        int absCoef = std::abs(term.coefficient);
        if (absCoef != 1 || term.exponent == 0)
            std::cout << absCoef;
            
        if (term.exponent > 0) {
            std::cout << "x";
            if (term.exponent > 1)
                std::cout << "^" << term.exponent;
        }
        
        firstTerm = false;
    }
}

// Operator overloads
Polynomial Polynomial::operator+(const Polynomial& rhs) const {
    Polynomial result = *this;
    return result += rhs;
}

Polynomial Polynomial::operator-(const Polynomial& rhs) const {
    Polynomial result = *this;
    return result -= rhs;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    if (this != &rhs) {
        terms = rhs.terms;
    }
    return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
    for (const Term& term : rhs.terms) {
        terms.push_back(term);
    }
    combineTerms();
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& rhs) {
    for (const Term& term : rhs.terms) {
        terms.push_back(Term(-term.coefficient, term.exponent));
    }
    combineTerms();
    return *this;
}