#include"MyString.h"
#include<iostream>
void main() {
	MyString string_1{ "helLLO" };
	std::cout << string_1.my_string << std::endl;
	string_1 = -string_1;
	std::cout << string_1.my_string << std::endl;

	MyString one{ "one" };
	MyString two{ "two" };
	MyString result = one + two;
	std::cout << result.my_string << std::endl;

	MyString three_but_one{ "one" };
	MyString three_but_one_2{ "one" };
	bool equality_result_true = three_but_one == three_but_one_2;
	std::cout << equality_result_true << std::endl;
	bool equality_result_false = one == two;
	std::cout << equality_result_false << std::endl;
}
