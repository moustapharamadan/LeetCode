#pragma once

#include <vector>
#include <stack>

namespace LEETCODE_0739 {
    class Solution {
    public:
        std::vector<int> dailyTemperatures(std::vector<int>& temperatures) 
        {
            std::vector<int> result(temperatures.size());
            for (int i = 0; i < temperatures.size() -1; ++i)
            {
                int count = 0;
                int j = i + 1;
                while (j < temperatures.size() && temperatures[i] >= temperatures[j])
                {
                    ++j;
                }
                result[i] = j == temperatures.size() ? 0 : j - i;
            }
            return result;
        }

        std::vector<int> dailyTemperatures2(std::vector<int>& temperatures)
        {
            std::vector<int> result(temperatures.size(), 0);            
            std::stack<int> s;
            for (int i = 0; i < temperatures.size(); ++i)
            {
                while (!s.empty() && temperatures[s.top()] < temperatures[i])
                {
                    int index = s.top();
                    s.pop();
                    result[index] = i - index;
                }

                s.push(i);
            }
            return result;
        }
    };
}