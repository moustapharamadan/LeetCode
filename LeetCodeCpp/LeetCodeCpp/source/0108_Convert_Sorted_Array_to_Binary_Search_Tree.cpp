#include "../pch.h"
#include "../header/0108_Convert_Sorted_Array_to_Binary_Search_Tree.hpp"

class ConvertSortedArrayToBinaryTree : public ::testing::Test, public LEETCODE_0108::Solution {
};

TEST_F(ConvertSortedArrayToBinaryTree, test1)
{
	std::vector<int> nums{ -10,-3,0,5,9 };

	auto tree = sortedArrayToBST(nums);
	EXPECT_EQ(tree->val, 0);
	EXPECT_EQ(tree->left->val, -3);
	EXPECT_EQ(tree->right->val, 9);
	EXPECT_EQ(tree->left->left->val, -10);
	EXPECT_EQ(tree->right->left->val, 5);
}
