#include "RoundEnd.h"
#include "UserUI.h"
#include <iostream>

using std::cout;
using std::endl;

//may need more in round end; should be using DealerController::CheckWinner()
void RoundEnd::display(Player p, DealerController* d) {
    bool winner = d->checkWinner();
    cout << "The round has ended. Round results are " << endl;

    cout << "Dealer total : ";
    if (d->getCardTotal() == 0)
        cout << "busted" << endl;
    else
        cout << d->getCardTotal() << endl;
    d->printHand(false);
    cout << "Player total : ";
    if (p.getCardTotal() == 0)
        cout << "busted" << endl;
    else
        cout << p.getCardTotal() << endl;
    p.printHand(false);

    if (winner)
        cout << "Congratulations you're the weener" << endl;
    else
        cout << "Congratulations you're the looooosssseeeerrrr" << endl;
    cout << endl << endl;
}

Move RoundEnd::getMove() {
    return newRound;
}
