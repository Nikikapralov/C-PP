#include<iostream>
#include<memory>
#include"Challenge/Account.h"
#include"CheckingAccount.h"
#include"Trust.h"



void main() {
	std::unique_ptr<Account> my_simple_account = std::make_unique<Account>("Nikola", 100);
	std::cout << (*my_simple_account).get_balance() << std::endl;
	(*my_simple_account).withdraw(30);
	std::cout << (*my_simple_account).get_balance() << std::endl;
	std::unique_ptr<Account> my_checking_account = std::make_unique<CheckingAccount>("Nikola", 200);
	std::cout << (*my_checking_account).get_balance() << std::endl;
	(*my_checking_account).withdraw(30);
	std::cout << (*my_checking_account).get_balance() << std::endl;
	std::unique_ptr<Account> my_trust_account = std::make_unique<TrustAccount>("Nikola", 300, 0);
	std::cout << (*my_trust_account).get_balance() << std::endl;
	(*my_trust_account).withdraw(40);
	(*my_trust_account).withdraw(40);
	(*my_trust_account).withdraw(20);
	(*my_trust_account).withdraw(150);
	(*my_trust_account).deposit(10000);
	std::cout << (*my_trust_account).get_balance() << std::endl;

};
