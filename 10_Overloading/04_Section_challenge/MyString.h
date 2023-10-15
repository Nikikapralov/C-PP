#include<string>

using std::string;

#ifndef _MyString_H_
#define _MyString_H_

class MyString {

	public:
		string my_string;
		MyString(string);
		MyString& operator-();
		MyString& operator+(const MyString& right_hand_side);
		bool operator==(const MyString& right_hand_side);
		bool operator!=(const MyString& right_hand_side);
		bool operator<(const MyString& right_hand_side);
		bool operator>(const MyString& right_hand_side);
		MyString& operator+=(const MyString& right_hand_side);
		MyString& operator*(const MyString& right_hand_side);
		MyString& operator*=(const MyString& right_hand_side);
};


#endif