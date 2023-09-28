#include <iostream>;
using std::cout, std::endl;

int find_max_element(int*, int);
void swap_pointers(int*, int*);


void main() {
	int arr[] { 3, 1, 5, 7, 8, 9 };
	int size{ 6 };
	int result = find_max_element(arr, size);
	cout << result << endl;
}


int find_max_element(int *arr, int size) {
	int *current_max_element{ arr };
	for (int i{ 0 }; i < size; ++i) {
		if (*current_max_element < arr[i]) {
			current_max_element = &arr[i];
		}
	}
	return *current_max_element;
}