#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Yuto_Kohata_Die.h"

using namespace std;

// Function prototypes
void playGame();
int rollDice(Die& die1, Die& die2);
void displayResult(int playerTotal, int computerTotal);

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (toupper(playAgain) == 'Y');

    return 0;
}

// The playGame function implements the main game logic.
void playGame() {
    Die die1(6), die2(6);
    int playerTotal = 0, computerTotal = 0;
    char rollAgain;

    // Computer's turn (hidden)
    computerTotal = rollDice(die1, die2);

    // Player's turn
    do {
        cout << "Do you want to roll the dice? (Y/N): ";
        cin >> rollAgain;

        if (toupper(rollAgain) == 'Y') {
            int roll = rollDice(die1, die2);
            playerTotal += roll;
            cout << "You rolled: " << roll << endl;
            cout << "Your total: " << playerTotal << endl;
        }
    } while (toupper(rollAgain) == 'Y' && playerTotal <= 21);

    displayResult(playerTotal, computerTotal);
}

// rollDice function simulates rolling two dice and returns the sum.
int rollDice(Die& die1, Die& die2) {
    die1.roll();
    die2.roll();
    return die1.getValue() + die2.getValue();
}

// displayResult function shows the final scores and determines the winner.
void displayResult(int playerTotal, int computerTotal) {
    cout << "Your total: " << playerTotal << endl;
    cout << "Computer's total: " << computerTotal << endl;

    if (playerTotal > 21 && computerTotal > 21) {
        cout << "Both went over 21. No one wins." << endl;
    } else if (playerTotal > 21) {
        cout << "You went over 21. Computer wins." << endl;
    } else if (computerTotal > 21) {
        cout << "Computer went over 21. You win!" << endl;
    } else if (playerTotal > computerTotal) {
        cout << "You win!" << endl;
    } else if (computerTotal > playerTotal) {
        cout << "Computer wins." << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}