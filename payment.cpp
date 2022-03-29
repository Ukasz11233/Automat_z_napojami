#include "payment.h"


bool Payment::paid() const
{
    if(to_pay.zl < 0)
        return true;
    else if(to_pay.zl == 0 && to_pay.gr == 0)
        return true;
    return false;
}


void Payment::Left_to_pay() const
{
    std::cout << "Zostalo do zaplacenia: " << to_pay.zl << "." << to_pay.gr << std::endl;
}


void Payment::set_to_pay(Price price)
{
    to_pay = price;
}

