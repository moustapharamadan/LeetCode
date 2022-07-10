#pragma once

#include <vector>
#include <unordered_map>

namespace LEETCODE_0560 {
    class Solution {
    public:
        int subarraySum(std::vector<int>& nums, int k) {
            std::unordered_map<int, int> seen;
            int sum = 0, count = 0;
            seen[sum] = 1;
            for (size_t i = 0; i < nums.size(); ++i)
            {
                sum += nums[i];
                int find = sum - k;
                if (seen.count(find))
                {
                    count += seen[find];
                }
                
                ++seen[sum];
            }
            return count;
        }
    };
}