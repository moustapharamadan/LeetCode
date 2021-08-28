#pragma once
#include <vector>
#include <numeric>

namespace LEETCODE_0001 {
    class Solution {
    public:
        int missingNumber(const std::vector<int>& nums) {
            int sum = std::accumulate(nums.begin(), nums.end(), 0);
            int expectedSum = nums.size() * (1 + nums.size()) / 2.;
            return expectedSum - sum;
        }
    };
}
