#ifndef BLIK_H_
#define BLIK_H_
#include "payment.h"

class Blik: public Payment{
private:
    std::string blik;
public:
    Blik() = default;
    virtual void Pay() override;
    virtual void Pay(const int) override;
};


#endif