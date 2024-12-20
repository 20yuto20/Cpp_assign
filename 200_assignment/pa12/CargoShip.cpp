#include "CargoShip.h"
#include <iostream>
using namespace std;

// Initialize cargo ship with name, year, and cargo capacity
CargoShip::CargoShip(string name, string year, int capacity)
    : Ship(name, year) {
    cargoCapacity = capacity;
}

// Return cargo capacity
int CargoShip::getCargoCapacity() const {
    return cargoCapacity;
}

// Set cargo capacity
void CargoShip::setCargoCapacity(int capacity) {
    cargoCapacity = capacity;
}

// Display cargo ship information
void CargoShip::print() const {
    cout << "Name: " << getName() << endl;
    cout << "Cargo capacity: " << cargoCapacity << " tons" << endl;
}