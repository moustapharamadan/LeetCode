#include "../pch.h"
#include "../header/0572_Subtree_of_Another_Tree.hpp"

class SubtreeOfAnotherTree : public ::testing::Test, public LEETCODE_0572::Solution {
public:
	typedef LEETCODE_0572::TreeNode TreeNode;
};

TEST_F(SubtreeOfAnotherTree, test1)
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(2);

	EXPECT_TRUE(isSubtree(root, root->left));
}

TEST_F(SubtreeOfAnotherTree, test2)
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(2);
	root->left->left->left = new TreeNode(0);

	TreeNode* sub = new TreeNode(4);
	sub->left = new TreeNode(1);
	sub->right = new TreeNode(2);

	EXPECT_FALSE(isSubtree(root, sub));
}