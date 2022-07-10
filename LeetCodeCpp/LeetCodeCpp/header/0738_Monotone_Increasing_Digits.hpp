#pragma once

#include <string>

namespace LEETCODE_0738 {
    class Solution {
    public:
        int monotoneIncreasingDigits(int n) {
            std::string number = std::to_string(n);

            int monotoneEnding = number.size();
            for (int i = number.size() - 1; i > 0; --i)
            {
                if (number[i] < number[i - 1])
                {
                    monotoneEnding = i;
                    --number[i - 1];
                }
            }

            for (int i = monotoneEnding; i < number.size(); ++i)
            {
                number[i] = '9';
            }
            return std::stoi(number);
        }
    };
}