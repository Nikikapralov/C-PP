#ifndef _TRUSTACCOUNT_H
#define _TRUSTACCOUNT_H
#include"Challenge/Savings_Account.h"

class TrustAccount : public Savings_Account {
	private:
		static constexpr int allowed_withdrawals{ 0 };
	public:
		TrustAccount(std::string name, double balance, double interest_rate) : Savings_Account{ name, balance, interest_rate } {};
		virtual ~TrustAccount() {};
		virtual bool withdraw(double);
		virtual bool deposit(double) override;
};

#endif 