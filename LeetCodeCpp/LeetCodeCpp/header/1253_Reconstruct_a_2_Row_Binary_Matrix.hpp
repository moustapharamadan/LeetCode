#pragma once
#include <vector>

namespace LEETCODE_1253 {

class Solution {
public:
    std::vector<std::vector<int>> reconstructMatrix(int upper, int lower, const std::vector<int>& colsum) {
        std::vector<std::vector<int>> result(2, std::vector<int>(colsum.size(),0));
        for (int i = 0; i < colsum.size(); ++i)
        {
            if (2 != colsum[i])
                continue;

            if (!upper || !lower)
                return std::vector<std::vector<int>>();

            result[0][i] = 1;
            result[1][i] = 1;
            --upper;
            --lower;
        }

        for (int i = 0; i < colsum.size(); ++i)
        {
            if (1 != colsum[i])
                continue;

            if (upper)
            {
                result[0][i] = 1;
                --upper;
            }
            else if (lower)
            {
                result[1][i] = 1;
                --lower;
            }
            else {
                return std::vector<std::vector<int>>();
            }
        }

        return (!upper && !lower) ? result : std::vector<std::vector<int>>();
    }
};

}