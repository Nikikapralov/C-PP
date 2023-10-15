#include "Money.h"
#include<iostream>

using std::ostream, std::cout;

Money::Money(int dollars, int cents) : dollars{ dollars }, cents{ cents } {}

Money::Money(int total) : dollars{ total / 100 }, cents{ total % 100 } {}


//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----

 ostream& operator << (ostream& out, const Money& m) {
	out << "dollars: " << m.dollars << " cents: " << m.cents;
	return out;
};

//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----


