#pragma once
#include <vector>


namespace LEETCODE_0695 {
    class Solution {
    public:
        int maxAreaOfIsland(const std::vector<std::vector<int>>& grid) {
            if (grid.empty())
                return 0;

            std::vector<std::vector<bool>> visisted(grid.size(), std::vector<bool>(grid[0].size(), false));
            int maxArea = 0;
            for (int i = 0; i < grid.size(); ++i)
            {
                for (int j = 0; j < grid[0].size(); ++j)
                {
                    if (grid[i][j] && !visisted[i][j])
                        maxArea = std::max(maxArea, DFS(visisted, grid, i, j));
                }
            }
            return maxArea;
        }
    private:
        int DFS(std::vector<std::vector<bool>>& visisted,
            const std::vector<std::vector<int>>& grid,
            const int row, 
            const int col)
        {
            auto canVisit = [&](const int i, const int j){
                return 0 <= i && i < grid.size() && 0 <= j && j < grid[0].size() && grid[i][j] && !visisted[i][j];
            };
            
            if (!canVisit(row, col))
                return 0;

            visisted[row][col] = true;
            return 1 + DFS(visisted, grid, row + 1, col) +
                DFS(visisted, grid, row - 1, col) +
                DFS(visisted, grid, row, col + 1) +
                DFS(visisted, grid, row, col - 1);
        }
    };
}