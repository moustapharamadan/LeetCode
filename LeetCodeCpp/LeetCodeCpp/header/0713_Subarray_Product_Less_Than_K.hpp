#pragma once

#include <vector>
#include <unordered_map>

namespace LEETCODE_0713 {
    class Solution {
    public:
        int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
            if (k <= 1)
                return 0;

            int left = 0, count = 0;
            double product = 1;

            for (size_t right = 0; right < nums.size(); ++right)
            {
                product *= nums[right];
                while (product >= k)
                {
                    product /= nums[left++];
                }
                count += right - left + 1;
            }
            return count;
        }
    };
}