#include <vector>
#include <iostream>
using namespace std;

int calculate_pairs(vector<int> vec) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    int result{ 0 };
    if (vec.size() <= 1) {
        return result;
    }

    int index{ 0 };
    while (index < vec.size() - 1) {
        for (int i = index + 1; i < vec.size(); ++i) {
            result += vec[index] * vec[i];
            }
        ++index;
        }
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
}

void main() {
    vector<int> vec{ 2, 4, 6, 8 };
    int result = calculate_pairs(vec=vec);
    cout << result;
}