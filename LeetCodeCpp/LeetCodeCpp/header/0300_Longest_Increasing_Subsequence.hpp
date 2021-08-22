#pragma once
#include <vector>

namespace LEETCODE_0300 {
    class Solution {
    public:
        int lengthOfLIS(const std::vector<int>& nums) {
            if (nums.empty())
                return 0;

            std::vector<int> dp;
            dp.push_back(1);
            for (int i = 1; i < nums.size(); ++i)
            {
                int sum = 0;
                for (int j = 0; j < i; ++j)
                {
                    if (nums[j] < nums[i])
                        sum= std::max(sum, dp[j]);
                }
                dp.push_back(sum+1);
            }
            return *std::max_element(dp.begin(), dp.end());
        }
    };
}
