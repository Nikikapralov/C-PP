#pragma once

#ifndef TWO_SUM_H
#define TWO_SUM_H

#include <vector>
#include <unordered_map>
#include <utility>

inline std::pair<int, int> two_sum(const std::vector<int>& nums, int target) {
    /*Given an array of integers nums and an integer target,
    return indices of the two numbers such that they add up to target.

    My solution:
    For each number in numbers: O(N)
        Find 9 - number and save it in map with index. (O1)
        If number in map: (O1)
            return current_index and number_index. (O1)

    :param nums: The input array.
    :param target: The number to sum up to.
    :return: A list with the indexes of the two numbers that sum up to the target.*/

    std::unordered_map<int, int> map;
    std::pair<int, int> result;

    for (int i = 0; i < nums.size(); ++i) {
        const int num = nums[i];
        int number_to_find = target - num;

        if (map.contains(number_to_find)) {
            return std::pair<int, int>({ map.at(number_to_find), i });
        }

        map[num] = i;
    }

}



#endif //TWO_SUM_H
