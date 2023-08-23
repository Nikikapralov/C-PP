#include <iostream>
using namespace std;

int main(int number) {
    int original_number{ number };
    number = ((((number * 2) + 9 - 3) / 2) - original_number) % 3;

    return number;
}

int sum = main(10);