#pragma once

#include <vector>

namespace LEETCODE_0054 {
    class Solution {
    public:
        std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
            const std::vector<std::vector<int>> directions = { {1,0}, {0,1 }, {-1,0}, {0,-1} };
            if (matrix.empty() || matrix[0].empty())
                return {};

            std::vector<size_t> dimensions = { matrix.size(), matrix[0].size() -1 };

            std::vector<int> result;
            int dir = 0, row = -1, col = 0;
            while (dimensions[dir % 2])
            {
                for (int i = 0; i < dimensions[dir % 2]; ++i)
                {
                    row += directions[dir][0]; 
                    col += directions[dir][1];
                    result.emplace_back(matrix[col][row]);
                }
                --dimensions[dir % 2];
                dir = (dir + 1) % 4;
            }

            return result;
        }
    };
}