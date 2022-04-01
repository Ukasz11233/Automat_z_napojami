#ifndef CARD_H_
#define CARD_H_
#include "payment.h"

class Card: public Payment{
public:
    Card() = default;
    virtual void Pay();
    virtual void Pay(const int) {Pay();}
};

#endif