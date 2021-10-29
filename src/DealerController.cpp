#include "DealerController.h"
#include "UserUI.h"
#include "DuringPlayView.h"
#include "RoundEnd.h"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;

class UserUI;

DealerController::DealerController() {
    currentUI = 0;
    UserUI* one = new DuringPlayView;
    UserUI* two = new RoundEnd;
    uiSwitcher = std::make_pair(one, two);
}

DealerController::~DealerController() {
    delete uiSwitcher.first;
    delete uiSwitcher.second;
}

bool DealerController::playGame(Player* p) {
    bool standFlag = false;
    this->prepGame(p);
    this->changeUI(uiSwitcher.first, *p);
    while (!standFlag) {
        switch (currentUI->getMove()) {
            case hitCard : {
                p->hit(theDeck.dealCard());
                break;
            }
            case stand : {
                standFlag = true;
                this->play();
                this->updateTotals(p->getCardTotal());
                this->changeUI(uiSwitcher.second, *p);
                return true;
            }
            case help : {
                getHelp();
                break;
            }
            case exitGame : {
                return false;
            }
        }
        if (p->getBust()) {
            this->updateTotals(p->getCardTotal());
            this->changeUI(uiSwitcher.second, *p);
            return true;
        }
        currentUI->display(*p, this);
    }
    return true;
}

void DealerController::changeUI(UserUI* newUI, Player p) {
    if (newUI && currentUI != newUI)
        currentUI = newUI;
    if (currentUI)
        currentUI->display(p, this);
    else
        std::cout << "error no ui found" << std::endl;
}

void DealerController::play() {
    while (true) {
        if (hand.getTotal() < 17) {
            this->hit(theDeck.dealCard());
            cout << "Dealer hits" << endl;
            cout << "Dealer's Cards : " << endl;
            hand.printCards(false);
        } else {
            break;
        }
    }
}

void DealerController::prepGame(Player* player) {
    theDeck.shuffle();
    for (unsigned int i = 0; i < 2; i++) {
        player->hit(theDeck.dealCard());
        hand.addCard(theDeck.dealCard());
    }
}

bool DealerController::checkWinner() {
    //win
    if (totals.first > totals.second && totals.first <= 21)
        return true;
    //lose
    else if (totals.first > 21 ||
        totals.first < totals.second ||
        totals.second == 21)
        return false;
    //tie
    else if (totals.first == totals.second)
        return false;
    else
        cout << "we didnt think this could happen T.T" << endl;
}

void DealerController::updateTotals(unsigned int value) {
    totals.first = value;
    totals.second = this->getCardTotal();
}

void DealerController::getHelp() {
  cout << "Help : " << endl << endl
       << "You are currently playing the game Blackjack." << endl
       << "The goal is to get 21 from the cards that are" << endl
       << "given to you from the deck. You will start with two cards" << endl
       << "and will have the option to add an additional card or keep" << endl
       << "your existing cards. Once you've made the decision to take" << endl
       << "an additional card you must take it." << endl << endl

       << "Once you have decided to keep your existing cards the" << endl
       << "dealer will play and are prohibited from taking an" << endl
       << "additional card if their total is greater than or equal" << endl
       << "to 17. In the event of a tie, the dealer wins." << endl << endl

       << "The values of cards follow their number except for" << endl
       << "face cards, that being jack, queen and king, and" << endl
       << "aces. Face cards are all worth 10 and aces are worth" << endl
       << "1 or 11 depending on if the value of 11 puts you over 21." << endl
       << endl << endl
       << "During game play you have 3 options:" << endl
       << "Hit: request an extra card as long as you are below 21."
       << endl << endl
       << "Stand: which will hold you total and end your" << endl
       << "turn for the current round." << endl << endl
       << "Exit: You will exit the game" << endl << endl;
}
