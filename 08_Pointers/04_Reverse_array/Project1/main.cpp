#include<iostream>;
using std::cout, std::endl;


void reverse_array(int*, int);


void main() {
	int arr[6]{ 1, 2, 3, 4, 5, 6 };
	int size{ 6 };
	cout << *arr << endl;
	reverse_array(arr, size);
	cout << *arr << endl;
}

void reverse_array(int* arr, int size) {
	int temporary_value { 0 };
	for (int i{ 0 }; i < size / 2; ++i) {
		temporary_value = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temporary_value;
	}
}