#include "../pch.h"
#include "../header/0110_Balanced_Binary_Tree.hpp"

class isBalancedBinaryTree : public ::testing::Test, public LEETCODE_0110::Solution {
public:
	typedef LEETCODE_0110::TreeNode TreeNode;
};

TEST_F(isBalancedBinaryTree, test1)
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	EXPECT_TRUE(isBalanced(root));
}

TEST_F(isBalancedBinaryTree, test2)
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(3);
	root->left->left->left = new TreeNode(4);
	root->left->left->right = new TreeNode(4);

	EXPECT_FALSE(isBalanced(root));
}

TEST_F(isBalancedBinaryTree, test3)
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->left->left->left = new TreeNode(8);

	EXPECT_TRUE(isBalanced(root));
}
