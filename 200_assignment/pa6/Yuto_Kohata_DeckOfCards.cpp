#include "Yuto_Kohata_DeckOfCards.h"
#include <cstdlib>
#include <ctime>

// Constructor - initialize the deck
DeckOfCards::DeckOfCards() : currentCard(0) {
    // Create 52 cards in order
    for (int suit = 0; suit < 4; ++suit) {
        for (int face = 0; face < 13; ++face) {
            deck.push_back(Card(face, suit));
        }
    }
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
}

// Shuffle the deck
void DeckOfCards::shuffle() {
    // Iterate through each card
    for (size_t i = 0; i < deck.size(); ++i) {
        // Select a random position
        int j = rand() % 52;
        // Swap cards
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    currentCard = 0;  // Reset current card after shuffle
}

// Deal one card
Card DeckOfCards::dealCard() {
    return deck[currentCard++];
}

// Check if there are more cards to deal
bool DeckOfCards::moreCards() const {
    return currentCard < 52;
}