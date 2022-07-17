#include "../pch.h"
#include "../header/0079_Word_Search.hpp"

class WordSearch : public ::testing::Test, public LEETCODE_0079::Solution {
};

TEST_F(WordSearch, test1)
{
	std::vector<std::vector<char>> board = { {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
	std::string word = "ABCCED";
	EXPECT_TRUE(exist(board, word));
}

TEST_F(WordSearch, test2)
{
	std::vector<std::vector<char>> board = { {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
	std::string word = "SEE";
	EXPECT_TRUE(exist(board, word));
}

TEST_F(WordSearch, test3)
{
	std::vector<std::vector<char>> board = { {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
	std::string word = "ABCB";
	EXPECT_FALSE(exist(board, word));
}
