#include "Player.h"
#include <iostream>

void Player::hit(Card hitCard) {
    hand.addCard(hitCard);
    if (hand.getTotal() > 21)
        busted = true;
}

unsigned int Player::getCardTotal() {
    if (busted)
        return 0;
    else
        return hand.getTotal();
}

bool Player::getBust() {
    return busted;
}

void Player::printHand(bool b) {
    hand.printCards(b);
}
