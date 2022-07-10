#pragma once

#include <vector>
#include <stack>

namespace LEETCODE_0907 {
    class Solution {
    public:
        int sumSubarrayMins(std::vector<int>& arr)
        {
            const std::vector<int> leftDistance = distanceToPreviousLessElement(arr);
            const std::vector<int> rightDistance = distanceToNextLessElement(arr);

            int sum = 0;
            const int mod = 1e9 + 7;
            for (int i = 0; i < arr.size(); ++i)
            {
                long prod = (leftDistance[i] * rightDistance[i]) % mod;
                prod = (prod * arr[i]) % mod;
                sum = (sum + prod) % mod;
            }

            return sum;

        }

    private:
        using IndexValue = std::pair<int, int>;
        std::vector<int> distanceToPreviousLessElement(const std::vector<int>& arr)
        {
            std::vector<int> result(arr.size());
            std::stack <IndexValue> increasingStack;
            for (int i = 0; i < arr.size(); ++i)
            {
                while (!increasingStack.empty() && increasingStack.top().second >= arr[i])
                    increasingStack.pop();

                result[i] = increasingStack.empty() ? i + 1 : i - increasingStack.top().first;
                increasingStack.push({ i, arr[i] });
            }

            return result;
        }

        std::vector<int> distanceToNextLessElement(const std::vector<int>& arr)
        {
            std::vector<int> result(arr.size());
            std::stack <IndexValue> increasingStack;
            for (int i = arr.size() - 1; i >= 0; --i)
            {
                while (!increasingStack.empty() && increasingStack.top().second > arr[i])
                    increasingStack.pop();

                result[i] = increasingStack.empty() ? arr.size() - i : increasingStack.top().first - i;
                increasingStack.push({ i, arr[i] });
            }

            return result;
        }
    };
}