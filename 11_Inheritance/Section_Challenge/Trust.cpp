#include"Trust.h"
#include<iostream>
bool TrustAccount::withdraw(double amount) {
	double twenty_percent_of_balance = this->balance * 0.2;
	if ((amount <= twenty_percent_of_balance) && (this->allowed_withdrawals < 3)) {
		++this->allowed_withdrawals;
		return Savings_Account::withdraw(amount);
	};
	return false;
}

bool TrustAccount::deposit(double amount) {
	if (amount >= 5000.0) {
		amount += 50.0;
	};
	return Savings_Account::deposit(amount);
};
