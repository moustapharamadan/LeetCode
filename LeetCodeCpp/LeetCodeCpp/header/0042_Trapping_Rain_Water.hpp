#pragma once
#include <vector>

namespace LEETCODE_0042 {
    class Solution {
    public:
        int trap_brute_force(const std::vector<int>& height) {
            int result = 0;
            for (int i = 0 ; i < height.size(); ++i)
            {
                int leftMax= height[i],rightMax = height[i];
                for (int j = 0; j < i; ++j)
                {
                    leftMax = std::max(leftMax, height[j]);
                }
                for (int j = i+1; j < height.size(); ++j)
                {
                    rightMax = std::max(rightMax, height[j]);
                }
                result += std::min(leftMax, rightMax) - height[i];
            }
            return result;
        }

        int trap_brute_force_2(const std::vector<int>& height) {
            int result = 0;
            for (int i = 0 ; i < height.size(); ++i)
            {
                int leftMax = *std::max_element(height.begin(), height.begin() + i + 1);
                int rightMax= *std::max_element(height.begin() + i, height.end());
                result += std::min(leftMax, rightMax) - height[i];
            }
            return result;
        }

        int trap_dynamic_programming(const std::vector<int>& height) {
            int result = 0;
            const int size = height.size();
            std::vector<int> leftMax(size), rightMax(size);
            leftMax[0] = height[0];
            rightMax[size - 1] = height[size - 1];
            for (int i = 1; i < size; ++i)
            {
                leftMax[i] = std::max(leftMax[i - 1], height[i]);
            }
            for (int i = size - 2; i >= 0; --i)
            {
                rightMax[i] = std::max(rightMax[i + 1], height[i]);
            }

            for (int i = 0; i < size; ++i)
            {
                result += std::min(leftMax[i], rightMax[i]) - height[i];
            }
            return result;
        }

        int trap(const std::vector<int>& height) {
            int result = 0;
            int leftIndex = 0, rightIndex = height.size() - 1;
            int leftMax = 0, rightMax = 0;

            while (leftIndex < rightIndex)
            {
                if (height[leftIndex] < height[rightIndex])
                {
                    leftMax = std::max(leftMax, height[leftIndex]);
                    result += std::max(leftMax- height[leftIndex],0);
                    ++leftIndex;
                }
                else {
                    rightMax = std::max(rightMax, height[rightIndex]);
                    result += std::max(rightMax - height[rightIndex], 0);
                    --rightIndex;
                }
            }
            return result;
        }
    };
}