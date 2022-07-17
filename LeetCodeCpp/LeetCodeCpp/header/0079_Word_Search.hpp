#pragma once

#include <vector>
#include <string>

namespace LEETCODE_0079 {
    class Solution {
    public:
        bool exist(std::vector<std::vector<char>>&board, std::string word) {
            for (int i = 0; i < board.size(); ++i)
            {
                for (int j = 0; j < board[i].size(); ++j)
                {
                    if (dfs(board, word, i, j))
                        return true;
                }
            }
            return false;
        }
    private:
        bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int i , int j) {
            if (word.empty())
                return true;
            if (i < 0 || i == board.size() || j < 0 || j == board[i].size() || word[0] != board[i][j])
                return false;
            
            char c = board[i][j];
            board[i][j] = ' ';
            bool found = checkAllDirections(board, word.substr(1), i, j);
            board[i][j] = c;
            return found;
        }

        bool checkAllDirections(std::vector<std::vector<char>>& board, const std::string& word, int i, int j)
        {
            return dfs(board, word, i + 1, j)
                || dfs(board, word, i, j + 1)
                || dfs(board, word, i - 1, j)
                || dfs(board, word, i, j - 1);
        }
    };
}