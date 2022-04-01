#include "headers/automat.h"
#include "headers/coin.h"
#include "headers/blik.h"
#include "headers/card.h"

Automat::~Automat()
{
    for(int i = 0; i < 3; i++)
        delete payment_method[i];
}


Automat::Automat(Drink arr[]) :  Payment({0, 0})
{
    payment_method[0] = new Coin;
    payment_method[1] = new Blik;
    payment_method[2] = new Card;
    for(int i = 0; i < _DRINK_NUM; i++)
    {
        drinks[i] = arr[i];
        available[i] = 3;
    }

}


void Automat::Show()
{
    for(int i = 0; i < _DRINK_NUM; i++)
    {
        drinks[i].Show();
        std::cout << "; Dostepnych: " << available[i] << std::endl;
    }
}


void Automat::decrease_num_of_drinks(const int idx)
{
    available[idx] -= 1;
}

void Automat::Left_to_pay(const int i)
{
    payment_method[i]->Left_to_pay();
}


bool Automat::paid(const int i) const
{
    return payment_method[i]->paid();
}


int Automat::Choose_drink(const int _id) {
    int idx = -1;
    for (int i = 0; i < _DRINK_NUM; i++) {
        if (drinks[i].ID_compare(_id)) {
            idx = i;
            if (available[i] <= 0) {
                std::cout << "Napoj niedostepny, wybierz inny" << std::endl;
                return -1;
            }
            for(int i = 0; i < 3; i++)
                payment_method[i]->set_to_pay(drinks[idx].drink_price());
            return idx;
        }
    }
    if (idx == -1) {
        std::cout << "nie ma takiego napoju!" << std::endl;
    }
    return -1;
}


void Automat::Choose_payment(const int i)
{
    payment_method[i] -> Pay();
}

void Automat::Choose_payment(const int i, const int k)
{
    payment_method[i] -> Pay(k);
}

