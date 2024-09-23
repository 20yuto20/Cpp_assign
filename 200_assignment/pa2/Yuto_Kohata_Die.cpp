#include "Yuto_Kohata_Die.h"
#include <cstdlib>
#include <ctime>

// The constructor initializes the die with the given number of sides and performs an initial roll.
Die::Die(int numSides) {
    setSides(numSides);
}

// setSides updates the number of sides and re-rolls the die.
void Die::setSides(int numSides) {
    sides = numSides;
    roll();
}

// roll generates a random value between 1 and the number of sides.
void Die::roll() {
    value = rand() % sides + 1;
}

int Die::getSides() const {
    return sides;
}

int Die::getValue() const {
    return value;
}