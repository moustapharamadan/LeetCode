#pragma once
#include <bitset>
#include <algorithm>

namespace LEETCODE_0191 {
    class Solution {
    public:
        int hammingWeight(uint32_t n) {
            std::string stringBinary = std::bitset<32>(n).to_string();
            return std::count_if(stringBinary.begin(), stringBinary.end(), [](auto c) {return c == '1'; });
        }
    };
}