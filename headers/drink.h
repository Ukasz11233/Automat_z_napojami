#ifndef DRINK_H_
#define DRINK_H_
#include "payment.h"


class Drink{
private:
    const static int _NAME_LEN = 50;
    int ID;
    Price price;
    char name[_NAME_LEN];
public:
    Drink() = default;
    Drink(const int _id, const int _zl, const int _gr, const char  *_name);
    void Show();
    bool ID_compare(const int _id);
    Price drink_price();
};

#endif