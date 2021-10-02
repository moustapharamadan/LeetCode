#pragma once
#include <vector>

namespace LEETCODE_0053 {
    class Solution {
    public:
        int maxSubArray(const std::vector<int>& nums) {
            if (nums.empty())
                return 0;

            int maxSum = nums[0];
            int currentSum = maxSum;
            for (int i = 1; i < nums.size(); ++i) {

                currentSum = std::max(nums[i] + currentSum, nums[i]);
                maxSum = std::max(currentSum, maxSum);
            }
            return maxSum;
        }
    };
}
