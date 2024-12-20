#include "Yuto_Kohata_Coin.h"
#include <cstdlib>
#include <ctime>

// Default constructor
Coin::Coin() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Randomly determine the initial side
    toss();
}

// Toss the coin
void Coin::toss() {
    // Generate a random number (0 or 1)
    int randomNum = std::rand() % 2;
    
    // Set sideUp based on the random number
    sideUp = (randomNum == 0) ? "heads" : "tails";
}

// Get the current side facing up
std::string Coin::getSideUp() const {
    return sideUp;
}