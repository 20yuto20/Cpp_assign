// Yuto_Kohata_IntegerSet.h
// COMSC 200 Fall 2024
// Programming Assignment 7

#ifndef INTEGER_SET_H
#define INTEGER_SET_H

#include <vector>

class IntegerSet {
private:
    std::vector<bool> set; // Vector to represent the set (index 0-100)

public:
    // Default constructor - creates empty set
    IntegerSet();

    // Constructor that receives an array of integers
    IntegerSet(const int array[], int size);

    // Set operations
    IntegerSet unionOfSets(const IntegerSet& other) const;
    IntegerSet intersectionOfSets(const IntegerSet& other) const;
    
    // Element operations
    void insertElement(int k);
    void deleteElement(int m);
    
    // Input/Output operations
    void inputSet();
    void printSet() const;
    
    // Comparison operation
    bool isEqualTo(const IntegerSet& other) const;

private:
    // Utility function to validate numbers
    bool isValidNumber(int num) const;
};

#endif