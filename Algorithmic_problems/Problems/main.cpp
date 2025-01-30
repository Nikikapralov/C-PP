#include <iostream>
#include <vector>
#include "01_Two_sum/two_sum.h"
#include "11_Container_to_hold_max_water/container_to_hold_max_water.h"
#include "15_three_sum/three_sum.h"


int main() {
    std::vector<int> nums{-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> result = three_sum(nums);
}