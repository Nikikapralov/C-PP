#include <iostream>;
using std::cout, std::endl;

void multiply_with_pointer(int*, int);


void main() {
	int value{ 10 };
	int* value_pointer = &value;
	int multiplier{100};
	multiply_with_pointer(value_pointer, multiplier);
	cout << value << endl;
}

void multiply_with_pointer(int* ptr, int multiplier) {
	*ptr = *ptr * multiplier;
}