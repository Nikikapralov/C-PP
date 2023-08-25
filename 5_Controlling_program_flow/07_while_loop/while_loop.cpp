#include <iostream>
#include <vector>
using namespace std;

int count_numbers(const vector<int>& vec) {
    int index{ 0 };
    int count{ 0 };
    if (vec.size() == 0) {
        return count;
    }
    while (vec[index] != -99) {
        count += 1;
        ++index;
        if (index >= vec.size()) {
            break;
        }
    }
    return count;
}

void main() {
    vector<int> vector_1{ 10, 20, 30, -99, 40, 50};
    vector<int> vector_2{ 10, 20, 30 };
    int result = count_numbers(vector_1);
    int result_2 = count_numbers(vector_2);
    cout << result << "\n" << result_2;
}