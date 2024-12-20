#include <iostream>
#include "Yuto_Kohata_FuelGauge.h"
#include "Yuto_Kohata_Odometer.h"

int main() {
    // Create a FuelGauge object with 15 gallons (full tank)
    FuelGauge fuelGauge(15);
    
    // Create an Odometer object with initial mileage 0
    Odometer odometer(0, fuelGauge);
    
    // Simulate driving until the car runs out of fuel
    while (fuelGauge.getFuelAmount() > 0) {
        std::cout << "Mileage: " << odometer.getMileage() 
                  << " miles, Fuel remaining: " << fuelGauge.getFuelAmount() 
                  << " gallons" << std::endl;
        
        odometer.incrementMileage();
    }
    
    // Final output when the car runs out of fuel
    std::cout << "The car has run out of fuel at " 
              << odometer.getMileage() << " miles." << std::endl;
    
    return 0;
}