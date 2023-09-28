#include<iostream>;
#include<string>;
using std::string, std::cout, std::endl;

string reverse_string(const string&);

void main() {
	string custom_string{ "Hello world" };
	cout << custom_string << endl;
	string result = reverse_string(custom_string);
	cout << result << endl;
}

string reverse_string(const string& custom_string) {
	string result;
	int size = custom_string.length();
	char temporary_value;
	for (int i{ size - 1 }; i > - 1; --i) {
		result += custom_string[i];
	}
	return result;
}

