#pragma once
#include <vector>

namespace LEETCODE_0200 {
    class Solution {
    public:
        int numIslands(const std::vector<std::vector<char>>& grid) {

            std::vector<std::vector<bool>>visited(grid.size(), std::vector<bool>(grid[0].size(), false));
            int count = 0;

            for (int i = 0; i < grid.size(); ++i)
            {
                for (int j = 0; j < grid[0].size(); ++j)
                {
                    if (!visited[i][j] && '1' == grid[i][j])
                    {
                        DFS(visited, grid, i, j);
                        ++count;
                    }
                }
            }
            return count;
        }

    private:
        void DFS(std::vector<std::vector<bool>>& visited, const std::vector<std::vector<char>>& grid, const int row, const int col)
        {
            auto canVisit = [&](const int i, const int j) {
                return i < grid.size() && j < grid[0].size() && i >= 0 && j >= 0 && !visited[i][j] && '1' == grid[i][j];
            };

            if (!canVisit(row, col))
                return;

            visited[row][col] = true;
            DFS(visited, grid, row, col - 1);
            DFS(visited, grid, row, col + 1);
            DFS(visited, grid, row - 1, col);
            DFS(visited, grid, row + 1, col);
        }
    };
}
