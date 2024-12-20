#ifndef YUTO_KOHATA_CARGOSHIP_H
#define YUTO_KOHATA_CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship {
private:
    int cargoCapacity;    // Cargo capacity in tons

public:
    // Constructor
    CargoShip(string name, string year, int capacity);

    // Accessor method
    int getCargoCapacity() const;

    // Mutator method
    void setCargoCapacity(int capacity);

    // Override the print function
    virtual void print() const override;
};

#endif