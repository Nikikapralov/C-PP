#include"MyString.h"
#include<string>

using std::string;


MyString::MyString(string my_string) : my_string(my_string) {};

MyString &MyString::operator-() {
	for (auto &x : my_string) {
		x = tolower(x);
	};
	return *this;
};

MyString &MyString::operator+(const MyString& right_hand_side){
	string result = this->my_string + right_hand_side.my_string;
	this->my_string = result;
	return *this;
}

bool MyString::operator==(const MyString& right_hand_side) {
	if (this->my_string.compare(right_hand_side.my_string) == 0) {
		return true;
	};

	return false;
};

bool MyString::operator!=(const MyString& right_hand_side) {
	if (this->my_string.compare(right_hand_side.my_string) != 0) {
		return true;
	};

	return false;
};



