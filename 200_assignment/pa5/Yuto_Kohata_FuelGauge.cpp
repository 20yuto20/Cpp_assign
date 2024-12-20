#include "Yuto_Kohata_FuelGauge.h"

// Constructor
FuelGauge::FuelGauge(int initialFuel) : fuelAmount(initialFuel) {
    if (fuelAmount > 15) fuelAmount = 15; // Maximum 15 gallons
    if (fuelAmount < 0) fuelAmount = 0;   // Minimum 0 gallons
}

// Get current fuel amount
int FuelGauge::getFuelAmount() const {
    return fuelAmount;
}

// Increment fuel by 1 gallon
void FuelGauge::incrementFuel() {
    if (fuelAmount < 15) {
        fuelAmount++;
    }
}

// Decrement fuel by 1 gallon
void FuelGauge::decrementFuel() {
    if (fuelAmount > 0) {
        fuelAmount--;
    }
}