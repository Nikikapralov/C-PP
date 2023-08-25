#include <iostream>;
using namespace std;

int calculate_sum() {
    int sum { 0 };

    for (int i = 0; i < 16; ++i) {
        if (i % 2 == 1){
            sum += i;
        }
    }
    return sum;
}

void main() {
    int sum = calculate_sum();
    cout << sum;
}