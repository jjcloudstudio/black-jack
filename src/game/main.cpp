#include "DealerController.h"
#include "UserUI.h"
#include "RoundEnd.h"
#include "DuringPlayView.h"
#include <utility>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

int main() {
    char ch;
    bool endGame = false;

    do {
        cout << "Welcome to Group A's Black Jack Game" << endl << endl
             << "Main Menu : " << endl
             << "Play game (1)" << endl
             << "Instructions (2)" << endl
             << "Exit (3)" << endl
             << "Please respond with the number\ncorresponding to your desired"
             << " option : ";

        cin >> ch;
        cout << endl << endl;
        switch (ch) {
            case '1' : {
                DealerController d;
                Player p;
                if (d.playGame(&p))
                    break;
                else
                    return 0;
            }
            case '2' : {
                DealerController d;
                //instructions should be a dealer function
                d.getHelp();
                //cout << "To do - instructions" << endl;
                break;
            }
            case '3' : {
                endGame = true;
                break;
            }
            default : {
                cout << "Invalid response; try again" << endl << endl;
                continue;
            }
        }
    } while (!endGame);
    return 0;
}
