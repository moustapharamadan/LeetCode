#include "../pch.h"
#include "../header/0310_Minimum_Height_Trees.hpp"

class MinimumHeightTrees : public ::testing::Test, public LEETCODE_0310::Solution {
};

TEST_F(MinimumHeightTrees, test1)
{
	std::vector<std::vector<int>> edges = { {1,0} ,{1,2},{1,3} };
	EXPECT_EQ(findMinHeightTrees(4, edges), std::vector<int>({ 1 }));
}

TEST_F(MinimumHeightTrees, test2)
{
	std::vector<std::vector<int>> edges = { {3,0} ,{3,1},{3,2},{3,4},{5,4} };
	EXPECT_EQ(findMinHeightTrees(6, edges), std::vector<int>({ 3,4 }));
}