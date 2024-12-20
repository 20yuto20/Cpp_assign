#ifndef COIN_H
#define COIN_H

#include <string>

class Coin {
private:
    std::string sideUp; // Stores either "heads" or "tails"

public:
    Coin(); // Default constructor
    void toss(); // Simulates tossing the coin
    std::string getSideUp() const; // Returns the value of sideUp
};

#endif // COIN_H