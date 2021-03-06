#ifndef COIN_H_
#define COIN_H_

#include "payment.h"

class Coin: public Payment{
public:
    Coin() {};
    virtual void Pay() override;
    virtual void Pay(const int) override;
};

#endif