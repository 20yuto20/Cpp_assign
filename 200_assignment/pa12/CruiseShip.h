#ifndef YUTO_KOHATA_CRUISESHIP_H
#define YUTO_KOHATA_CRUISESHIP_H

#include "Ship.h"

class CruiseShip : public Ship {
private:
    int maxPassengers;    // Maximum passenger capacity

public:
    // Constructor
    CruiseShip(string name, string year, int passengers);

    // Accessor method
    int getMaxPassengers() const;

    // Mutator method
    void setMaxPassengers(int passengers);

    // Override the print function
    virtual void print() const override;
};

#endif