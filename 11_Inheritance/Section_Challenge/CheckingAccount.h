#ifndef _CHECKINGACCOUNT_H_
#define _CHECKINGACCOUNT_H_
#include "Challenge/Account.h"

class CheckingAccount : public Account {
	private:
		static constexpr double withdrawal_fee{ 1.50 };
	public:
		CheckingAccount(std::string name, double balance) : Account{ name, balance } {};
		virtual ~CheckingAccount() = default;
		virtual bool withdraw(double) override;
};

#endif
