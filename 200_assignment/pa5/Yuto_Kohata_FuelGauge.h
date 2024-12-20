#ifndef FUEL_GAUGE_H
#define FUEL_GAUGE_H

class FuelGauge {
private:
    int fuelAmount; // Current amount of fuel in gallons

public:
    // Constructor
    FuelGauge(int initialFuel = 0);

    // Member functions
    int getFuelAmount() const;
    void incrementFuel();
    void decrementFuel();
};

#endif // FUEL_GAUGE_H