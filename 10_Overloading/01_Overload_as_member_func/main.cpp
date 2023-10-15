#include "Money.h"
#include<iostream>
using std::cout, std::endl;

void main() {
	Money first_entry = Money(10, 10);
	Money second_entry = Money(10, 10);
	Money third_entry = Money(12, 10);

	bool result_one = first_entry == second_entry;
	bool result_two = first_entry == third_entry;

	cout << result_one << " " << result_two << endl;
}