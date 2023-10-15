#include "Money.h"

Money::Money(int dollars, int cents) : dollars{ dollars }, cents{ cents } {}

Money::Money(int total) : dollars{ total / 100 }, cents{ total % 100 } {}


//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----



//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----


Money operator+(const Money& left, const Money& right) {
	double total_cents = (left.dollars + right.dollars) * 100;
	total_cents += (left.cents + right.cents);
	return Money(total_cents);
};