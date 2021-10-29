#ifndef DEALERCONTROLLER_H
#define DEALERCONTROLLER_H

#include "Player.h"
#include "UserUI.h"
#include "DuringPlayView.h"
#include "RoundEnd.h"
#include "Deck.h"
#include <utility>

class DealerController : public Player {
 public:
       /// \brief Constructor for DealerController.
        DealerController();
       /// \brief Destructor for DealerController.
        ~DealerController();
       /// \brief Deals two cards to the dealer and the player.
       /// \param[in] player The player object so hands can be controlled.
        void prepGame(Player* player);
       /// \brief Where gameplay is conducted.
       /// \param[in] p Allows for player moves and hand to be controlled.
        bool playGame(Player* p);
       /// \brief Determines the winner of the hand.
        bool checkWinner();
       /// \brief Updates the totals of the player and dealer.
       /// \param[in] value The way to update the player's total.
        void updateTotals(unsigned int value);
       /// \brief Changes the display to DuringPlay or RoundEnd.
       /// \param[in] newUI The UI to be changed to.
       /// \param[in] p Allows for the display function to be called.
        void changeUI(UserUI* newUI, Player p);
       /// \brief Displays the instructions for the game.
        void getHelp();

 private:
       /// \brief The dealer's turn to play
        void play(); //dealer playing the game

        Deck theDeck;
        UserUI* currentUI;
        std::pair<int, int> totals;
        std::pair<UserUI*, UserUI*> uiSwitcher;
};

#endif
