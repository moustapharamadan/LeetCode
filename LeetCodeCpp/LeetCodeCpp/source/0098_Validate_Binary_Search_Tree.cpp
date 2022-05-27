#include "../pch.h"
#include "../header/0098_Validate_Binary_Search_Tree.hpp"

class ValidateBinarySearchTree : public ::testing::Test, public LEETCODE_0098::Solution {
public:
	typedef LEETCODE_0098::TreeNode TreeNode;
};

TEST_F(ValidateBinarySearchTree, test1)
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);

	EXPECT_TRUE(isValidBST(root));
}

TEST_F(ValidateBinarySearchTree, test2)
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(6);

	EXPECT_FALSE(isValidBST(root));
}

TEST_F(ValidateBinarySearchTree, test3)
{
	TreeNode* root = new TreeNode(2147483647);

	EXPECT_TRUE(isValidBST(root));
}
