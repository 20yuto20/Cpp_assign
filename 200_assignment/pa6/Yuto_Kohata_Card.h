#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    int face;  // Index for the face of the card
    int suit;  // Index for the suit of the card

public:
    // Constructor
    Card(int cardFace = 0, int cardSuit = 0);

    // Static arrays for faces and suits
    static const std::string faces[13];
    static const std::string suits[4];

    // toString function to return card as string
    std::string toString() const;
};

#endif