#include "CruiseShip.h"
#include <iostream>
using namespace std;

// Initialize cruise ship with name, year, and passenger capacity
CruiseShip::CruiseShip(string name, string year, int passengers)
    : Ship(name, year) {
    maxPassengers = passengers;
}

// Return maximum passenger capacity
int CruiseShip::getMaxPassengers() const {
    return maxPassengers;
}

// Set maximum passenger capacity
void CruiseShip::setMaxPassengers(int passengers) {
    maxPassengers = passengers;
}

// Display cruise ship information
void CruiseShip::print() const {
    cout << "Name: " << getName() << endl;
    cout << "Maximum passengers: " << maxPassengers << endl;
}