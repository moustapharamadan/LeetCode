#include "../pch.h"
#include "../header/0515_Find_Largest_Value_in_Each_Tree_Row.hpp"

class FindTheLargestValueInEachTreeRow : public ::testing::Test, public LEETCODE_0515::Solution {
};

TEST_F(FindTheLargestValueInEachTreeRow, test1)
{
	const std::vector<int>result = { 1,3,7 };
	std::unique_ptr<TreeNode> root(new TreeNode(1,
		new TreeNode(2, new TreeNode(4), new TreeNode(5)),
		new TreeNode(3, new TreeNode(6), new TreeNode(7))
	));
	EXPECT_EQ(largestValues(root.get()), result);
}
