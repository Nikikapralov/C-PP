#pragma once
#include <vector>
#include <iterator>

int container_to_hold_max_water(std::vector<int>& height) {
    /*
    *   You are given an integer array height of length n.
    *   There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    *   Find two lines that together with the x-axis form a container, such that the container contains the most water.
    *   Return the maximum amount of water a container can store.
    *
    *   Solution:
    *   Area = a * b
    *   I set a pointer to the right and to the left of the array.
    *   I calculate the area between the 2 columns.
    *   I move the smaller pointer one position.
    *   I calculate the area again.
    *   Repeat until the biggest area is found.
    *
    *   This works because with this approach, we are limited by the height of the smallest wall. (Water overflow)
    *   and we subsequently squeeze the container tighter and tighter until we reach out of options.
    *   We can continue to move the smaller column since the length gets shorter every time and
    *   we take the risk of either moving to a bigger column that can compensate for that or to a column
    *   that can't.
    */

    int area{0};
    auto left_it = height.begin();
    auto right_it = height.end() - 1;


    while (left_it != right_it) {
        int distance = std::distance(left_it, right_it);
        int smaller;

        if (*left_it > *right_it) {
            smaller = *right_it;
            --right_it;
        }
        else {
            smaller = *left_it;
            ++left_it;
        }

        int current_area = distance * smaller;

        area = current_area > area ? current_area : area;

    }

    return area;
};