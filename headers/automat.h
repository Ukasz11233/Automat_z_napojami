#ifndef AUTOMAT_H_
#define AUTOMAT_H_
#include "payment.h"
#include "drink.h"

class Automat: public Payment{
private:
    static const int _DRINK_NUM = 4;
    Drink drinks[_DRINK_NUM];
    int available[_DRINK_NUM];
    Payment * payment_method[3];
public:
    Automat() = default;
    ~Automat();
    Automat(Drink arr[]);
    void Show();
    void decrease_num_of_drinks(const int idx);
    virtual void Left_to_pay(const int i);
    virtual bool paid(const int i) const;

    int Choose_drink(const int _id);
    void Choose_payment(const int i);
    void Choose_payment(const int i, const int k);
};

#endif