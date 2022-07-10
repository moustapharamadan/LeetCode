#pragma once

#include <string>

namespace LEETCODE_0402 {
    class Solution {
    public:
        std::string removeKdigits(std::string num, int k) {
            std::string increasingStack;

            for (char c : num)
            {
                while (!increasingStack.empty() && k > 0 && increasingStack.back() > c)
                {
                    increasingStack.pop_back();
                    --k;
                }
                if(!increasingStack.empty() || '0' != c)
                    increasingStack.push_back(c);
            }

            while (k > 0 && !increasingStack.empty())
            {
                increasingStack.pop_back();
                --k;
            }
            return increasingStack.empty() ? "0" : increasingStack;
        }
    };
}