#include"CheckingAccount.h"

bool CheckingAccount::withdraw(double amount) {
	double resulting_sum = this->balance - amount - this->withdrawal_fee;
	if (resulting_sum >= 0) {
		this->balance = resulting_sum;
		return true;
	};
	return false;
};