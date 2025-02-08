#pragma once

#include <vector>
#include <algorithm>
#include <iostream>


int remove_element(std::vector<int>&& nums, int val) {
    /*
    * Given an integer array nums and an integer val,
    * remove all occurrences of val in nums in-place.
    * The order of the elements may be changed. Then
    * return the number of elements in nums which are
    * not equal to val.

    Consider the number of elements in nums which are not equal
    to val be k, to get accepted, you need to do the following things:

    Change the array nums such that the first k elements of
    nums contain the elements which are not equal to val. The
    remaining elements of nums are not important as well as
    the size of nums.
    Return k.
     */
    int result = nums.size();
    if (not result) {
        return 0;
    }

    auto left_iterator = nums.begin();
    auto right_iterator = --nums.end();

    while (left_iterator <= right_iterator) {
        if (*left_iterator == val) {
            --result;
            std::swap(*left_iterator, *right_iterator);
            --right_iterator;
        } else {
            ++left_iterator;
        }
    }

    // for (const auto& i : nums) {
    //     std::cout << i << std::endl;
    // }

    return result;
}