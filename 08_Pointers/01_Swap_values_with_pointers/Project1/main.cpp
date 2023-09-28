#include <iostream>
using std::cout, std::endl;

void swapPointers(int* ptr1, int* ptr2) {

    int temporary{ *ptr1 };
    *ptr1 = *ptr2;
    *ptr2 = temporary;
}

void main() {
    int value_1{ 10 };
    int value_2{ 20 };

    int* pointer_1 = &value_1;
    int* pointer_2 = &value_2;
    
    swapPointers(pointer_1, pointer_2);

    cout << value_1 << endl;
    cout << value_2 << endl;

}