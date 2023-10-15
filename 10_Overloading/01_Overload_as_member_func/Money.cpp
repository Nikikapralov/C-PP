#include "Money.h"

Money::Money(int dollars, int cents) : dollars{ dollars }, cents{ cents } {}

Money::Money(int total) : dollars{ total / 100 }, cents{ total % 100 } {}


//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----

bool Money::operator==(const Money& right_hand_side) const {
	if (this->dollars == right_hand_side.dollars
		&&
		this->cents == right_hand_side.cents) {
		return true;
	}
	return false;
};

bool Money::operator!=(const Money& right_hand_side) const {
	if (this->dollars != right_hand_side.dollars
		||
		this->cents != right_hand_side.cents) {
		return true;
	}
	return false;
}


//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----


