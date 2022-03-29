#include "card.h"


void Card::Pay()
{
    std::cout << "Przyluz karte.\n\a";
    std::cout <<"Platnosc zakonczona.\n";
    to_pay.zl = 0;
    to_pay.gr = 0;
}