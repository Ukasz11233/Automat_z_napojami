#ifndef PAYMENT_H_
#define PAYMENT_H_

#include <iostream>
struct Price{
    int zl;
    int gr;
};


class Payment{
protected:
    Price to_pay;
public:
    Payment() = default;
    Payment(Price price): to_pay(price) {}
    virtual ~Payment() = default;
    virtual bool paid() const;
    virtual void set_to_pay(Price price);
    virtual void Left_to_pay() const;
    virtual void Pay() {};


};

#endif