// Yuto_Kohata_IntegerSet.cpp
// COMSC 200 Fall 2024
// Programming Assignment 7

#include "Yuto_Kohata_IntegerSet.h"
#include <iostream>

// Default constructor - creates empty set
IntegerSet::IntegerSet() : set(101, false) {}

// Constructor with array
IntegerSet::IntegerSet(const int array[], int size) : set(101, false) {
    for (int i = 0; i < size; i++) {
        if (isValidNumber(array[i])) {
            set[array[i]] = true;
        }
    }
}

// Validate numbers (0-100)
bool IntegerSet::isValidNumber(int num) const {
    return num >= 0 && num <= 100;
}

// Union of two sets
IntegerSet IntegerSet::unionOfSets(const IntegerSet& other) const {
    IntegerSet result;
    for (int i = 0; i <= 100; i++) {
        result.set[i] = set[i] || other.set[i];
    }
    return result;
}

// Intersection of two sets
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& other) const {
    IntegerSet result;
    for (int i = 0; i <= 100; i++) {
        result.set[i] = set[i] && other.set[i];
    }
    return result;
}

// Insert element into set
void IntegerSet::insertElement(int k) {
    if (isValidNumber(k)) {
        set[k] = true;
    }
}

// Delete element from set
void IntegerSet::deleteElement(int m) {
    if (isValidNumber(m)) {
        set[m] = false;
    }
}

// Input set from user
void IntegerSet::inputSet() {
    int num;
    std::cout << "Enter a number (0-100, -1 to end): ";
    
    while (std::cin >> num && num != -1) {
        if (isValidNumber(num)) {
            set[num] = true;
        } else {
            std::cout << "Invalid number!\n";
        }
        std::cout << "Enter a number (0-100, -1 to end): ";
    }
}

// Print the set
void IntegerSet::printSet() const {
    bool empty = true;
    
    for (int i = 0; i <= 100; i++) {
        if (set[i]) {
            if (!empty) {
                std::cout << " ";
            }
            std::cout << i;
            empty = false;
        }
    }
    
    if (empty) {
        std::cout << "--";
    }
    std::cout << std::endl;
}

// Check if two sets are equal
bool IntegerSet::isEqualTo(const IntegerSet& other) const {
    for (int i = 0; i <= 100; i++) {
        if (set[i] != other.set[i]) {
            return false;
        }
    }
    return true;
}