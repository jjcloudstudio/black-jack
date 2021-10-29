#include "DuringPlayView.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void DuringPlayView::display(Player p, DealerController* d) {
    char ch;
    bool moveComplete = false;
    while (!moveComplete) {
        cout << "Dealers Cards : " << endl;
        d->printHand(true);
        cout << "Player's Cards : " << p.getCardTotal() << endl;
        p.printHand(false);
        cout << "Hit (1)\n"
             << "Stand (2)\n"
             << "Help (3)\n"
             << "Exit (4)\n"
             << "Please respond with the digit\n"
             << "corresponding to your desired action : ";

        cin >> ch;
        switch (ch) {
            case '1' : {
                playerMove = hitCard;
                moveComplete = true;
                break;
            }
            case '2' : {
                playerMove = stand;
                moveComplete = true;
                break;
            }
            case '3' : {
                playerMove = help;
                moveComplete = true;
                break;
            }
            case '4' : {
                playerMove = exitGame;
                moveComplete = true;
                break;
            }
            default : {
                cout << "invalid response\n Try again" << endl;
                continue;
            }
        }
        cout << endl << endl;
    }
}

Move DuringPlayView::getMove() {
    return playerMove;
}
