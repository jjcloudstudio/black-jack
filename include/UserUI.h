#ifndef USERUI_H
#define USERUI_H

#include "Player.h"
#include "DealerController.h"

class DealerController;

enum Move {hitCard, stand, help, exitGame, newRound};

class UserUI {
 public:
       /// \brief Virtual function to display content as needed.
        virtual void display(Player, DealerController*) = 0;
       /// \brief Virtual function to get available move.
        virtual Move getMove() = 0;
 protected:
        Move playerMove;
};

#endif
