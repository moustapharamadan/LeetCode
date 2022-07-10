#pragma once

#include <vector>
#include <unordered_map>

namespace LEETCODE_0523 {
    class Solution {
    public:
        bool checkSubarraySum(std::vector<int>& nums, int k) {
            std::unordered_map<int, int> remainderSum = { { 0,-1 } };
            int runningSum = 0;

            for (size_t i = 0; i < nums.size(); ++i)
            {
                runningSum += nums[i];
                runningSum = k ? runningSum % k : runningSum;
                if (remainderSum.count(runningSum))
                {
                    if(i - remainderSum[runningSum] > 1)
                        return true;
                }
                else
                {
                    remainderSum[runningSum] = i;
                }
            }

            return false;
        }
    };
}