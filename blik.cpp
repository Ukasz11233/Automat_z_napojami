#include "blik.h"

void Blik::Pay()
{
    std::cout << "Podaj 6 cyfrowy kod blik: ______\b\b\b\b\b\b";
    std::getline(std::cin, blik);
    std::cout << "Oto poprawny kod blik: " << blik;
    to_pay.zl = 0;
    to_pay.gr = 0;
    std::cout << "\nPlatnosc zakonczona.\n";
}
