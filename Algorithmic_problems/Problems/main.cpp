#include <iostream>
#include <vector>
#include "01_Two_sum/two_sum.h"
#include "11_Container_to_hold_max_water/container_to_hold_max_water.h"


int main() {
    std::vector<int> nums{1,8,6,2,5,4,8,3,7};
    int result = container_to_hold_max_water(nums);
    std::cout << result;
}