#include<iostream>;
using std::cout, std::endl;

void print_array(int*, int);
int* apply_all(int*, int, int*, int);


void main() {
	int arr[5]{ 1, 2, 3, 4, 5 };
	print_array(arr, 5);
	int arr_2[2]{ 10, 20 };
	print_array(arr_2, 2);
	int* result_array = apply_all(arr, 5, arr_2, 2);
	print_array(result_array, 10);
	delete[] result_array;
}


void print_array(int* arr, int size) {
	cout << "[ ";
	for (int i{ 0 }; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}

int* apply_all(int* arr_1, const int size_1, int* arr_2, const int size_2) {
	const int new_size = size_1 * size_2;
	int *new_array = new int[new_size];
	int array_index{ 0 };
	for (int i{ 0 }; i < size_1; ++i) {
		for (int index{ 0 }; index < size_2; ++index) {
			new_array[array_index] = arr_1[i] * arr_2[index];
			++array_index;
		}
	}
	return new_array;
}