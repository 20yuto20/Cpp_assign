#ifndef YUTO_KOHATA_SHIP_H
#define YUTO_KOHATA_SHIP_H

#include <string>
using namespace std;

class Ship {
private:
    string shipName;    // Stores the name of the ship
    string yearBuilt;   // Stores the year when the ship was built

public:
    // Constructor with two parameters
    Ship(string name, string year);

    // Accessor methods
    string getName() const;
    string getYear() const;

    // Mutator methods
    void setName(string name);
    void setYear(string year);

    // Virtual print function for polymorphism
    virtual void print() const;

    // Virtual destructor for proper cleanup
    virtual ~Ship() {}
};

#endif