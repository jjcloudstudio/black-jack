#include <iostream>
#include <string>
#include <deque>
#include "CardSetModel.h"
#include "cardTemplate.h"

using std::cout;
using std::endl;
using std::string;
using std::deque;

void CardSetModel::addCard(Card hitCard) {
    set.push_back(hitCard);
}

unsigned int CardSetModel::getTotal() {
    unsigned int total = 0;
    bool aceHigh = true;
    bool haveAce = false;

    for (unsigned int i = 0; i < set.size(); i++) {
        if (set[i].getValue() == ace) {
            if (haveAce) {
                total += 1;
                continue;
            } else {
                haveAce = true;
                continue;
            }
        }

        if (set[i].getValue() == ten || set[i].getValue() == jack ||
        set[i].getValue() == queen || set[i].getValue() == king) {
            total +=10;
            continue;
        }

        total += (unsigned int)set[i].getValue();
    }
    if (total > 10)
        aceHigh = false;
    if (aceHigh && haveAce)
        total += 11;
    else if (haveAce && !aceHigh)
        total += 1;

    return total;
}

void CardSetModel::printCards(bool hideFirst) {
    //if we are hiding the first card it will always only be two cards to print
    if (hideFirst) {
        for (unsigned int i = 0; i < 8; i++)
            cout << cardTemplate[0][i]
                 << cardTemplate[set[1].getValue()][i]
                 << endl;
    } else {
        for (unsigned int i = 0; i < 8; i++) {
            for (unsigned int j = 0; j < set.size(); j++)
                cout << cardTemplate[set[j].getValue()][i];
            cout << endl;
        }
    }
    cout << endl << endl;
}
