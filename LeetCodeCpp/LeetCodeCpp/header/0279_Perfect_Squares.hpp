#pragma once
#include <vector>

namespace LEETCODE_0279 {
    class Solution {
    public:
        int numSquares(int n) {
            if (n <= 0)
                return 0;

            std::vector<int> perfectSquare(n + 1, std::numeric_limits<int>::max());
            perfectSquare[0] = 0;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j * j <= i; ++j)
                {
                    perfectSquare[i] = std::min(perfectSquare[i], perfectSquare[i - j * j] + 1);
                }
            }
            return perfectSquare[n];
        }
    };
}
