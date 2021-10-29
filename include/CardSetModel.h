#ifndef CARDSETMODEL_H
#define CARDSETMODEL_H

#include <deque>
#include "Card.h"

using std::deque;

class CardSetModel {
 public:
       /// \brief Draws card from deck
       /// \param[in] hitCard The card that is drawn.
        void addCard(Card hitCard);
       /// \brief Calculates a hand's total.
        unsigned int getTotal();
       /// \brief Displays a hand's cards
       /// \param[in] hideFirst If true, hides the first card,
       /// otherwise shows both.
        void printCards(bool hideFirst);

 protected:
        deque<Card> set;
};

#endif
