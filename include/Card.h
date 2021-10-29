#ifndef CARD_H
#define CARD_H

enum value {ace = 1, two, three, four, five, six, seven, eight, nine, ten,
    jack, queen, king};

class Card {
 public:
       /// \brief Constructor for Card class.
       /// \param[in] v Value of card to be made
      Card(value v);
       /// \brief Returns cardValue
        value getValue();
 private:
        value cardValue;
};

#endif
