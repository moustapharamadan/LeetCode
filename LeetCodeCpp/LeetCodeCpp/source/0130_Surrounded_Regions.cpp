#include "../pch.h"
#include "../header/0130_Surrounded_Regions.hpp"

class SurroundedRegions : public ::testing::Test, public LEETCODE_0130::Solution {
};

TEST_F(SurroundedRegions, Test1)
{
	std::vector<std::vector<char>> board = { 
		{'X','X','X','X'},
		{'X','O','O','X'},
		{'X','X','O','X'},
		{'X','O','X','X'} 
	};
	solve(board);

	const std::vector<std::vector<char>> expectedBoard = { 
		{'X','X','X','X'},
		{'X','X','X','X'},
		{'X','X','X','X'},
		{'X','O','X','X'} 
	};
	EXPECT_EQ(board, expectedBoard);
}


TEST_F(SurroundedRegions, Test2)
{
	std::vector<std::vector<char>> board = {
		{'O','O','O','O','X','X'},
		{'O','O','O','O','O','O'},
		{'O','X','O','X','O','O'},
		{'O','X','O','O','X','O'},
		{'O','X','O','X','O','O'},
		{'O','X','O','O','O','O'}
	};
	solve(board);

	const std::vector<std::vector<char>> expectedBoard = {
		{'O', 'O', 'O', 'O', 'X', 'X'},
		{'O', 'O', 'O', 'O', 'O', 'O'},
		{'O', 'X', 'O', 'X', 'O', 'O'},
		{'O', 'X', 'O', 'O', 'X', 'O'},
		{'O', 'X', 'O', 'X', 'O', 'O'},
		{'O', 'X', 'O', 'O', 'O', 'O'}
	};
	EXPECT_EQ(board, expectedBoard);
}

TEST_F(SurroundedRegions, Test3)
{
	std::vector<std::vector<char>> board = {
		{'X','O','O','X','X','X','O','X','O','O'},
		{'X','O','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','O','X','X','X','X','X'},
		{'X','O','X','X','X','O','X','X','X','O'},
		{'O','X','X','X','O','X','O','X','O','X'},
		{'X','X','O','X','X','O','O','X','X','X'},
		{'O','X','X','O','O','X','O','X','X','O'},
		{'O','X','X','X','X','X','O','X','X','X'},
		{'X','O','O','X','X','O','X','X','O','O'},
		{'X','X','X','O','O','X','O','X','X','O'}
	};
	solve(board);

	const std::vector<std::vector<char>> expectedBoard = {
		{'X','O','O','X','X','X','O','X','O','O'},
		{'X','O','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','O'},
		{'O','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','X','X'},
		{'O','X','X','X','X','X','X','X','X','O'},
		{'O','X','X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X','O','O'},
		{'X','X','X','O','O','X','O','X','X','O'}
	};
	EXPECT_EQ(board, expectedBoard);
}