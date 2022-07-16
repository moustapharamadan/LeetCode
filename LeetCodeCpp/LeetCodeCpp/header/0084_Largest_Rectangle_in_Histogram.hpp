#pragma once

#include <vector>
#include <stack>

namespace LEETCODE_0084 {
    class Solution {
    public:
        int largestRectangleArea(std::vector<int>& heights) {
            int maxArea = 0;
            std::stack<int> s;
            for (size_t i = 0; i <= heights.size(); ++i)
            {
                while (!s.empty() && (i == heights.size() || heights[i] < heights[s.top()]))
                {
                    int heightIndex = s.top();
                    s.pop();
                    int step = s.empty() ? -1 : s.top();
                    int area = heights[heightIndex] * (i - 1 - step);
                    maxArea = std::max(maxArea, area);
                }
                s.push(i);
            }
            return maxArea;
        }
    };
}