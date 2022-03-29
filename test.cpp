#include <iostream>
#include <limits>
#include "automat.h"
#include "blik.h"
#include "card.h"
#include "coin.h"
#include "drink.h"
#include "payment.h"
using std::cout;
using std::endl;
using std::cin;
void Menu();


int main()
{
    Drink drink0(0, 2, 0,"kolka"), drink1(1, 3, 70, "sprajt"), drink2(2, 6, 10, "nesti"), drink3(3, 10, 0, "fanta");
    Drink arr[4] = {drink0, drink1, drink2, drink3};
    int n, idx;
    Automat automat(arr);

    automat.Show();
    cout <<"Podaj id napoju ktory chcesz kupic: ";
    while(cin >> n g)
    {
        idx = automat.Choose_drink(n);
        if(idx == -1) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        cout << "Podaj metode platnosci: 1.Bilon, 2.Blik, 3.Karta: ";
        while(!(cin >> n))
        {
            cout << "Nie ma takiej opcji. Podaj poprawna opcje: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.clear();
        }
        n--;
        cin.get();
        while(!automat.paid(n))
        {
            automat.Left_to_pay(n);
            automat.Choose_payment(n);
        }
        automat.decrease_num_of_drinks(idx);
        std::cout << "Zaplacono! Oto twoj napoj!\n";
        automat.Show();
        cout <<"Podaj id napoju ktory chcesz kupic: ";
    }


    return 0;
}


