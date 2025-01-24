#include <iostream>
#include <vector>
#include "01_Two_sum/two_sum.h"


int main() {
    std::vector<int> nums{ 2,7,11,15 };
    std::pair<int, int> result = two_sum(nums, 9);
    std::cout << result.first << " " << result.second;
}