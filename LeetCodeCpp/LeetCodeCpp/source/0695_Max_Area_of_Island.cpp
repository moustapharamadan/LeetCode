#include "../pch.h"
#include "../header/0695_Max_Area_of_Island.hpp"

class MaxAreaOfIsland : public ::testing::Test, public LEETCODE_0695::Solution {
};

TEST_F(MaxAreaOfIsland, Six)
{
	const std::vector<std::vector<int>>grid = { 
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}
	};
	EXPECT_EQ(maxAreaOfIsland(grid), 6);
}

TEST_F(MaxAreaOfIsland, Zero)
{
	const std::vector<std::vector<int>>grid = {
		{0,0,0,0,0,0,0,0}
	};
	EXPECT_EQ(maxAreaOfIsland(grid), 0);
}
