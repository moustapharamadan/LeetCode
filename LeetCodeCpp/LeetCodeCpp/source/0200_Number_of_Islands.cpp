#include "../pch.h"
#include "../header/0200_Number_of_Islands.hpp"

class NumberOfIslands : public ::testing::Test, public LEETCODE_0200::Solution {
};

TEST_F(NumberOfIslands, Nine)
{
	std::vector<std::vector<char>> grid = {
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1' }
	};
	EXPECT_EQ(numIslands(grid), 3);
}