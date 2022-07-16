#pragma once

#include <vector>
#include <deque>

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
            std::deque<std::pair<int, int>> incrStack;
            for (int i = 0; i < temperatures.size(); ++i)
            {
                auto it = incrStack.begin();
                while (!incrStack.empty() && it != incrStack.end())
                {
                    if (temperatures[it->first] >= temperatures[i])
                    {
                        it->second += 1;
                        ++it;
                    }
                    else
                    {
                        result[it->first] = it->second + 1;
                        incrStack.erase(it++);
                    }
                }

                incrStack.push_front(std::pair<int, int>({ i, 0 }));
            }
            return result;
        }
    };
}