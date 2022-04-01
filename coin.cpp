#include <limits>
#include "headers/coin.h"


void Coin::Pay()
{
    int coin, tmp;
    std::cout << "Podaj jedna z monet: 10, 20, 50 gr lub 1, 2, 5 zl\n";
    while(!(std::cin >> coin))
    {
        std::cout << "nie ma takiej monety oszuscie!\nWrzuc prawdziwa monete: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if(coin == 10 || coin == 20 || coin == 50)
        to_pay.gr -= coin;
    else if(coin == 1 || coin == 2 || coin == 5)
        to_pay.zl -= coin;
    else
        std::cout << "Nie ma takiej monety oszuscie!\n";
    if(to_pay.gr < 0)
    {
        tmp = to_pay.gr;
        to_pay.gr = 100 + tmp;
        to_pay.zl--;
    }
}

void Coin::Pay(const int coin)
{
    int tmp;
    std::cout << "Podaj jedna z monet: 10, 20, 50 gr lub 1, 2, 5 zl\n";

    if(coin == 10 || coin == 20 || coin == 50)
        to_pay.gr -= coin;
    else if(coin == 1 || coin == 2 || coin == 5)
        to_pay.zl -= coin;
    else
        throw std::invalid_argument("Nie ma takiej monety! --Exception\n");
    if(to_pay.gr < 0)
    {
        tmp = to_pay.gr;
        to_pay.gr = 100 + tmp;
        to_pay.zl--;
    }
}


