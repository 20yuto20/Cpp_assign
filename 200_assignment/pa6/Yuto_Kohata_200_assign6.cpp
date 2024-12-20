// Yuto_Kohata_200_assign6.cpp
// COMSC 200 Fall 2024
// Programming Assignment 6

#include <iostream>
#include <iomanip>
#include "Yuto_Kohata_DeckOfCards.h"

int main() {
    // Create a deck of cards
    DeckOfCards deck;
    
    // Shuffle the deck
    deck.shuffle();
    
    // Deal all 52 cards
    int cardCount = 0;
    std::cout << "The cards in the deck are:\n\n";
    
    while (deck.moreCards()) {
        // Get next card
        Card card = deck.dealCard();
        
        // Print card with proper spacing
        std::cout << std::left << std::setw(20) << card.toString();
        
        // Print 4 cards per line
        if (++cardCount % 4 == 0) {
            std::cout << std::endl;
        }
    }
    
    return 0;
}