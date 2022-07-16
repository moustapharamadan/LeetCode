#pragma once

#include <vector>
#include <deque>

namespace LEETCODE_0739 {
    class Solution {
    public:
        std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) {

            k = nums1.size() + nums2.size() - k;
            int k1 = k;
            std::deque<int> s1 = removeValues(nums1, k1);
            std::deque<int> s2 = removeValues(nums2, k1);
            std::vector<int> r1 = max(s1, s2, k1);

            int k2 = k;
            s2 = removeValues(nums2, k2);
            s1 = removeValues(nums1, k2);
            std::vector<int> r2 = max(s1, s2, k2);

            return r1 > r2 ? r1 : r2;

        }
    private:
        std::deque<int> removeValues(const std::vector<int>& nums, int& k)
        {
            std::deque<int> s;
            for (size_t i = 0; i < nums.size(); ++i)
            {
                while (k > 0 && !s.empty() && s.back() < nums[i])
                {
                    s.pop_back();
                    --k;
                }
                s.push_back(nums[i]);
            }

            return s;
        }

        std::vector<int> max(std::deque<int> s1,std::deque<int> s2, int k)
        {
            std::vector<int> result;
            while (k != s1.size() + s2.size())
            {
                if (!s1.empty() && !s2.empty())
                {
                    if (s1 > s2)
                    {
                        result.push_back(s1.front());
                        s1.pop_front();
                    }
                    else
                    {
                        result.push_back(s2.front());
                        s2.pop_front();
                    }
                }
                else if (!s1.empty())
                {
                    result.push_back(s1.front());
                    s1.pop_front();
                }
                else if (!s2.empty())
                {
                    result.push_back(s2.front());
                    s2.pop_front();
                }
                else
                {
                    break;
                }
                k;
            }

            return result;
        }
    };
}