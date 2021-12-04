#pragma once
#include <vector>

namespace LEETCODE_0130 {
    class Solution {
    public:
        void solve(std::vector<std::vector<char>>& board) {
            const int lastColumn = board[0].size() - 1;
            for (int i = 0; i < board.size(); ++i)
            {
                if ('O' == board[i][0])
                    DFS(board, i, 0);
                if ('O' == board[i][lastColumn])
                    DFS(board, i, lastColumn);
            }

            const int lastRow = board.size() - 1;
            for (int i = 0; i < board[0].size(); ++i)
            {
                if ('O' == board[0][i])
                    DFS(board, 0, i);
                if ('O' == board[lastRow][i])
                    DFS(board, lastRow, i);
            }

            for (int i = 0; i < board.size(); ++i)
            {
                for (int j = 0; j < board[0].size(); ++j)
                {
                    if ('O' == board[i][j])
                        board[i][j] = 'X';
                    if ('#' == board[i][j])
                        board[i][j] = 'O';
                }
            }
        }
    private:
        void DFS(std::vector<std::vector<char>>& board, const int row, const int col) {
            const bool isValid = 0 <= row && row < board.size() && 0 <= col && col < board[0].size() && 'O' == board[row][col];
            if (!isValid)
                return;

            board[row][col] = '#';
            DFS(board, row + 1, col);
            DFS(board, row - 1, col);
            DFS(board, row, col + 1);
            DFS(board, row, col - 1);
        }
    };
}
