#include "Ship.h"
#include <iostream>
using namespace std;

// Initialize ship with name and year
Ship::Ship(string name, string year) {
    shipName = name;
    yearBuilt = year;
}

// Return the ship's name
string Ship::getName() const {
    return shipName;
}

// Return the year the ship was built
string Ship::getYear() const {
    return yearBuilt;
}

// Set the ship's name
void Ship::setName(string name) {
    shipName = name;
}

// Set the year the ship was built
void Ship::setYear(string year) {
    yearBuilt = year;
}

// Display ship information
void Ship::print() const {
    cout << "Name: " << shipName << endl;
    cout << "Year built: " << yearBuilt << endl;
}