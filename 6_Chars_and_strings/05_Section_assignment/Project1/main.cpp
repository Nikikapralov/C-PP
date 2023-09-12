#include <string>
#include <iostream>
#include <algorithm>
using std::string, std::cin, std::cout, std::size_t, std::reverse;

string get_user_input() {
	string input{};
	cin >> input;
	return input;

}

size_t calculate_final_size_of_string(size_t string_length) {
	size_t final_size_of_string = (string_length - 1) * 2 + 1;
	return final_size_of_string;
}

size_t calculate_amount_of_tabs(size_t total_amount_of_tabs, size_t iteration_number) {
	size_t amount_of_tabs = total_amount_of_tabs - iteration_number;
	return amount_of_tabs;
}

string build_result(string input, string reverse_input, size_t tabs_amount, size_t iteration_number) {
	string result_left{};
	string result_right{};
	string final_result{};
	for (int i{ 0 }; i < tabs_amount + 1; ++i) {
		final_result += " ";
	};
	for (int i{ 0 }; i < iteration_number + 1; ++i) {
		result_left += input[i];
	};
	for (int i{ 0 }; i < result_left.length() - 1; ++i) {
		result_right += result_left[i];
	};
	reverse(result_right.begin(), result_right.end());
	final_result += result_left;
	final_result += result_right;
	return final_result;
}

void main(){
	string input = get_user_input();
	string input_reversed = input;
	reverse(input_reversed.begin(), input_reversed.end());
	size_t total_amount_of_tabs = input.length();
	size_t amount_of_iterations = total_amount_of_tabs;
	string result{};
	size_t iteration_number{ 0 };
	for (auto letter : input) {
		size_t tabs_amount = calculate_amount_of_tabs(total_amount_of_tabs, iteration_number);
		result = build_result(input, input_reversed, tabs_amount, iteration_number);
		++iteration_number;
		cout << result << '\n';
	};

}


