#include <cstring>
#include "headers/drink.h"

Drink::Drink(const int _id, const int _zl, const int _gr, const char * _name) : ID(_id)
{
    price.zl = _zl;
    price.gr = _gr;
    strncpy(name, _name, _NAME_LEN);
}


void Drink::Show()
{
    std::cout << "ID: " << ID << "; Cena: " << price.zl << "." << price.gr <<  "zl ; Nazwa: " << name;
}


bool Drink::ID_compare(const int _id)
{
    return ID == _id ? true : false;
}


Price Drink::drink_price()
{
    return price;
}