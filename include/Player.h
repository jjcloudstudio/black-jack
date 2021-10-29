#ifndef PLAYER_H
#define PLAYER_H

#include "CardSetModel.h"

class Player {
 public:
       /// \brief Adds a card to the hand.
       /// \param[in] hitCard The card to be added.
        void hit(Card hitCard);
       /// \brief Returns the value of all cards in the hand.
        unsigned int getCardTotal();
       /// \brief Checks to see if the player is busted or not.
        bool getBust();
       /// \brief Outputs all of the cards in the hand to the console.
       /// \param[in] b If true, hides the first card, otherwise shows both.
        void printHand(bool b);
 protected:
        CardSetModel hand;
        bool busted = false;
};

#endif
