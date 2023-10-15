#pragma once
#ifndef _MONEY_MONEY_H
#define _MONEY_MONEY_H


#include <iostream>
using std::ostream, std::cout;

class Money {
public:
    int dollars;
    int cents;
    Money(int dollars, int cents);
    Money(int total);


    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR METHOD DECLARATIONS BELOW THIS LINE----
    friend ostream& operator<< (ostream& out, const Money& money);

    //----WRITE YOUR METHOD DECLARATIONS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
};


#endif //_MONEY_MONEY_H