#include "Deck.h"
#include <deque>
#include <algorithm>
#include <random>

using std::deque;

Deck::Deck() {
    for (unsigned int j = 0; j < 4; j++)
        for (unsigned int i = 1; i <= 13; i++) {
            Card push(static_cast<value>(i));
            deckSet.push_back(push);
        }
}

void Deck::shuffle() {
    std::random_device r;
    std::shuffle(deckSet.begin(), deckSet.end(), r);
}

Card Deck::dealCard() {
    Card deal = deckSet.front();
    deckSet.pop_front();
    return deal;
}
