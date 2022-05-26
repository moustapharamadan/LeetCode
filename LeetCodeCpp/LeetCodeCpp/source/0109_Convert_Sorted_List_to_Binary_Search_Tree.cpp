#include "../pch.h"
#include "../header/0109_Convert_Sorted_List_to_Binary_Search_Tree.hpp"

class ConvertSortedListToBinaryTree : public ::testing::Test, public LEETCODE_0109::Solution {
public:
	typedef LEETCODE_0109::ListNode ListNode;
};

TEST_F(ConvertSortedListToBinaryTree, test1)
{
	ListNode* node = new ListNode(-10);
	node->next = new ListNode(-3);
	node->next->next = new ListNode(0);
	node->next->next->next = new ListNode(5);
	node->next->next->next->next = new ListNode(9);

	auto tree = sortedListToBST(node);
	EXPECT_EQ(tree->val, 0);
	EXPECT_EQ(tree->left->val, -3);
	EXPECT_EQ(tree->right->val, 9);
	EXPECT_EQ(tree->left->left->val, -10);
	EXPECT_EQ(tree->right->left->val, 5);
}
