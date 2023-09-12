#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string, std::toupper, std::cin, std::cout, std::vector,
std::find, std::size_t, std::reverse, std::transform;


string get_user_input() {
	string user_input{};
	cin >> user_input;
	return user_input;
}

string to_upper(string entry_string) {
	string to_upper{};
	for (auto letter : entry_string) {
		to_upper += toupper(letter);
	}
	return to_upper;
}

string cypher(string entry, string normal_table, string reversed_table) {
	string cyphered_string{};
	for (auto letter : entry) {
		size_t index_normal_table = normal_table.find(letter);
		cyphered_string += reversed_table[index_normal_table];
	};
	return cyphered_string;
}

void main() {
	string normal_table{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string reversed_table{ normal_table };
	reverse(reversed_table.begin(), reversed_table.end());
	string user_input = get_user_input();
	string user_input_upper = to_upper(user_input);
	string cyphered_user_input = cypher(user_input_upper, normal_table, reversed_table);
	string deciphered_user_input = cypher(cyphered_user_input, normal_table, reversed_table);
	cout << cyphered_user_input << '\n';
	cout << deciphered_user_input << '\n';
}


