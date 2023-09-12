#include <iostream>
#include <string>

using std::cout;

int sum_of_digits(int n) {
    int result{ 0 };
    // Write your code below this line
    if (n >= 10)
        result = sum_of_digits(n / 10);

    int digit = n % 10;

    return digit + result;

    // Write your code above this line
}

void main() {
    int result{};
    result = sum_of_digits(12);
    cout << result;
}