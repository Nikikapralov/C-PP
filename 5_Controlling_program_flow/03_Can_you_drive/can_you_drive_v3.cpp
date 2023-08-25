#include <iostream>
using namespace std;

void can_you_drive(int age, bool has_car) {

	if (age < 16) {
		cout << "Sorry, come back in " << 16 - age << " years and be sure you own a car when you come back.";
	}

	else if (age >= 16 && has_car) {
		cout << "Yes - you can drive!";
	}

	else {
		cout << "Sorry, you need to buy a car before you can drive!";
	}

}

void main() {
	can_you_drive(18, true);
	can_you_drive(12, true);
	can_you_drive(19, false);
}