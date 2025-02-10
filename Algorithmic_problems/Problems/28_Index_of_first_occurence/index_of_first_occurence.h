#pragma once
#include <string>
#include <functional>
#include <iostream>

bool is_correct_substring(std::string_view needle, std::string_view potential_substring) {

    int needle_index{0};

    for (const auto& c : potential_substring) {
        if (c == needle[needle_index]) {
            ++needle_index;
        } else {
            return false;
        }
    }

    return true;
}


int index_of_first_occurence(std::string_view needle, std::string_view haystack) {
    /*
     * Given two strings needle and haystack,
     * return the index of the first occurrence
     * of needle in haystack, or -1 if needle
     * is not part of haystack.
     *
     * Rabin Carp rolling Hash function but its std::hash instead.
     * */

    int result{-1};
    if (needle.empty()) {
        return result;
    }

    if (haystack.empty()) {
        return result;
    }

    if (needle.size() > haystack.size()) {
        return result;
    }

    std::hash<std::string_view> string_hasher;
    int needle_hash = string_hasher(needle);

    for (int i{0}; i < haystack.size(); ++i) {
        if (i > haystack.size() - needle.size()) {
            return result;
        }
        std::string_view potential_substring = haystack.substr(i, needle.size());
        int substring_hash = string_hasher(potential_substring);

        if (needle_hash == substring_hash) {
            if (is_correct_substring(needle, potential_substring)) {
                result = i;
                return result;
            }
        }
    }

    return result;
}




