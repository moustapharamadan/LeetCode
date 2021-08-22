#pragma once
#include <vector>

namespace LEETCODE_0011 {
    class Solution {
    public:
        int maxArea(const std::vector<int>& height) {
            int volume = 0;
            int leftIndex = 0, rightIndex = height.size() - 1;
            while (leftIndex < rightIndex)
            {
                if (height[leftIndex] < height[rightIndex])
                {
                    volume = std::max(volume, height[leftIndex] * (rightIndex - leftIndex));
                    ++leftIndex;
                }
                else {
                    volume = std::max(volume, height[rightIndex] * (rightIndex - leftIndex));
                    --rightIndex;
                }
            }
            return volume;
        }
    };
}
