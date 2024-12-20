#include "Yuto_Kohata_Coin.h"
#include <iostream>
#include <iomanip>

// Function prototypes
void playRound(Coin& quarter, Coin& dime, Coin& nickel, double& playerBalance, double& computerBalance);
void displayBalance(const std::string& player, double balance);
void displayResult(double playerBalance, double computerBalance);

int main() {
    // Create coin objects
    Coin quarter, dime, nickel;
    
    // Initialize balances
    double playerBalance = 0.0;
    double computerBalance = 0.0;
    
    // Display initial balances
    std::cout << "Game Start!\n";
    displayBalance("Player", playerBalance);
    displayBalance("Computer", computerBalance);
    std::cout << std::endl;
    
    // Game loop
    int round = 1;
    while (playerBalance < 1.0 && computerBalance < 1.0) {
        std::cout << "Round " << round << ":\n";
        playRound(quarter, dime, nickel, playerBalance, computerBalance);
        displayBalance("Player", playerBalance);
        displayBalance("Computer", computerBalance);
        std::cout << std::endl;
        round++;
    }
    
    // Display final results
    std::cout << "Game Over!\n";
    displayResult(playerBalance, computerBalance);
    
    return 0;
}

void playRound(Coin& quarter, Coin& dime, Coin& nickel, double& playerBalance, double& computerBalance) {
    // Player's turn
    quarter.toss();
    dime.toss();
    nickel.toss();
    
    if (quarter.getSideUp() == "heads") playerBalance += 0.25;
    if (dime.getSideUp() == "heads") playerBalance += 0.10;
    if (nickel.getSideUp() == "heads") playerBalance += 0.05;
    
    // Computer's turn
    quarter.toss();
    dime.toss();
    nickel.toss();
    
    if (quarter.getSideUp() == "heads") computerBalance += 0.25;
    if (dime.getSideUp() == "heads") computerBalance += 0.10;
    if (nickel.getSideUp() == "heads") computerBalance += 0.05;
}

void displayBalance(const std::string& player, double balance) {
    std::cout << player << " balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

void displayResult(double playerBalance, double computerBalance) {
    displayBalance("Player", playerBalance);
    displayBalance("Computer", computerBalance);
    
    if (playerBalance == computerBalance && playerBalance >= 1.0) {
        std::cout << "It's a tie!\n";
    } else if (playerBalance >= 1.0 && computerBalance < 1.0) {
        std::cout << "Player wins!\n";
    } else if (computerBalance >= 1.0 && playerBalance < 1.0) {
        std::cout << "Computer wins!\n";
    } else if (playerBalance < computerBalance) {
        std::cout << "Player wins with the lower score!\n";
    } else {
        std::cout << "Computer wins with the lower score!\n";
    }
}