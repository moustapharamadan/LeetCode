#pragma once
#include <vector>
#include <map>

namespace LEETCODE_0001 {
    class Solution {
    public:
        //std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        //    std::vector<int> temp;
        //    for (int i = 0; i < nums.size(); ++i)
        //    {
        //        auto it = std::find(temp.begin(), temp.end(), nums[i]);
        //        if (it == temp.end())
        //        {
        //            temp.push_back(target - nums[i]);
        //        }
        //        else {
        //            std::vector<int> result;
        //            result.push_back(i);
        //            result.push_back(it - temp.begin());
        //            return result;
        //        }
        //    }
        //    return std::vector<int>();
        //}
        std::vector<int> twoSum(const std::vector<int>& nums, int target) {
            std::map<int,int> remainingIndexMap;
            for (int i = 0; i < nums.size(); ++i)
            {
                auto it = remainingIndexMap.find(nums[i]);
                if (it == remainingIndexMap.end())
                {
                    remainingIndexMap[target - nums[i]] = i;
                }
                else {
                    std::vector<int> result;
                    result.push_back(i);
                    result.push_back(it->second);
                    return result;
                }
            }
            return std::vector<int>();
        }
    };
}
