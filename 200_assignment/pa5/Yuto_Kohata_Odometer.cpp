#include "Yuto_Kohata_Odometer.h"

// Constructor
Odometer::Odometer(int initialMileage, FuelGauge& fg) 
    : mileage(initialMileage), fuelGauge(fg) {
    if (mileage < 0) mileage = 0;
    if (mileage > 999999) mileage = 0;
}

// Get current mileage
int Odometer::getMileage() const {
    return mileage;
}

// Increment mileage by 1 mile
void Odometer::incrementMileage() {
    mileage++;
    if (mileage > 999999) {
        mileage = 0;
    }
    
    // Decrease fuel every 24 miles
    if (mileage % 24 == 0) {
        fuelGauge.decrementFuel();
    }
}