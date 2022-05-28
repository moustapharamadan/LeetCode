#include "../pch.h"
#include "../header/0437_Path_Sum_III.hpp"

class PathSumIII : public ::testing::Test, public LEETCODE_0437::Solution {
public:
	typedef LEETCODE_0437::TreeNode TreeNode;
};

TEST_F(PathSumIII, test1)
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(-3);

	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(2);
	root->right->right = new TreeNode(11);

	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right->right = new TreeNode(1);

	EXPECT_EQ(pathSum(root, 8), 3);
}

TEST_F(PathSumIII, test2)
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(-2);
	root->right = new TreeNode(-3);

	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(-2);

	root->left->left->left = new TreeNode(-1);

	EXPECT_EQ(pathSum(root, -1), 4);
}