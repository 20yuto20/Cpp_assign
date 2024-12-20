#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include <vector>
#include "Yuto_Kohata_Card.h"

class DeckOfCards {
private:
    std::vector<Card> deck;  // Vector to store 52 cards
    int currentCard;         // Current card to deal

public:
    // Constructor
    DeckOfCards();

    // Member functions
    void shuffle();
    Card dealCard();
    bool moreCards() const;
};

#endif