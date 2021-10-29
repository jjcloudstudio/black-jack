#ifndef DURINGPLAYVIEW_H
#define DURINGPLAYVIEW_H

#include "Player.h"
#include "DealerController.h"

class DealerController;
class UserUI;

class DuringPlayView : public UserUI {
 public:
        /// \brief Shows cards and asks for player move
        /// \param[in] p Allows access to player hand and moves
        /// \param[in] d Game control
        void display(Player p, DealerController* d);
        /// \brief Takes in player's move
        Move getMove();
};

#endif
