#include "../pch.h"
#include "../header/0112_Path_Sum.hpp"

class PathSum : public ::testing::Test, public LEETCODE_0112::Solution {
public:
	typedef LEETCODE_0112::TreeNode TreeNode;
};

TEST_F(PathSum, test1)
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);

	root->right->right->right = new TreeNode(1);

	EXPECT_TRUE(hasPathSum(root, 22));
}