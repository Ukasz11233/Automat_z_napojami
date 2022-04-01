#include <iostream>
#include <limits>
#include <fstream>
#include <queue>
#include <sstream>
#include "headers/automat.h"
#include "headers/blik.h"
#include "headers/card.h"
#include "headers/coin.h"
#include "headers/drink.h"
#include "headers/payment.h"
using std::cout;
using std::endl;
using std::cin;
void Menu();


int main(int argc, char * argv[])
{
    Drink drink0(0, 2, 0,"kolka"), drink1(1, 3, 70, "sprajt"), drink2(2, 6, 10, "nesti"), drink3(3, 10, 0, "fanta");
    Drink arr[4] = {drink0, drink1, drink2, drink3};
    int n, idx;
    Automat automat(arr);


    if(argc > 1)
    {
     std::ifstream mfile;

     mfile.open(argv[1], std::ios::in);
     std::string str;
     std::queue<int> arguments;
     if(!mfile.is_open())
         std::cerr << "Couldn't open\n";

     mfile >> str;
     while(!mfile.eof())
     {
         if(std::stringstream(str) >> n)
             arguments.push(n);
         mfile >> str;
     }

     while(!arguments.empty())
     {
         n = arguments.front();
         std::cout << n  << "\n";
         arguments.pop();
         idx = automat.Choose_drink(n);
         cout << "Podaj metode platnosci: 1.Bilon, 2.Blik, 3.Karta: ";
         n = arguments.front();
         arguments.pop();
         n--;
         while(!automat.paid(n))
         {
             automat.Left_to_pay(n);
             automat.Choose_payment(n, arguments.front());
             arguments.pop();
         }
         automat.decrease_num_of_drinks(idx);
         std::cout << "Zaplacono! Oto twoj napoj!\n";
         automat.Show();
         cout <<"Podaj id napoju ktory chcesz kupic: ";
     }

     return 0;
    }

    automat.Show();
    cout <<"Podaj id napoju ktory chcesz kupic: ";
    while(cin >> n )
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


