#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "CardSetModel.h"
#include <deque>

using std::deque;

class UserUI;

class Deck : public CardSetModel {
 public:
       /// \brief Deck constructor
        Deck();
       /// \brief Randomly shuffles the deck.
        void shuffle();
       /// \brief Draws a card from the top of the deck.
        Card dealCard();

 private:
        deque<Card> deckSet;
};

#endif
