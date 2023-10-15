#include<iostream>
#include"Money.h"

using std::cout;

void main() {
	Money money_1 = Money(100);
	Money money_2 = Money(200);
	Money result = money_1 + money_2;
	cout << result.get_cents() << " " << result.get_dollars();
};