#ifndef ROUNDEND_H
#define ROUNDEND_H

#include "Player.h"
#include "DealerController.h"

class DealerController;
class UserUI;

class RoundEnd : public UserUI {
 public:
        /// \brief Displays outcome of round.
        /// \param[in] p Player object to control hand
        /// \param[in] d Game controller.
        void display(Player p, DealerController* d);
        /// \brief Sets up next round.
        Move getMove();
};

#endif
