#ifndef ODOMETER_H
#define ODOMETER_H

#include "Yuto_Kohata_FuelGauge.h"

class Odometer {
private:
    int mileage;
    FuelGauge& fuelGauge; // Reference to FuelGauge object

public:
    // Constructor
    Odometer(int initialMileage, FuelGauge& fg);

    // Member functions
    int getMileage() const;
    void incrementMileage();
};

#endif // ODOMETER_H