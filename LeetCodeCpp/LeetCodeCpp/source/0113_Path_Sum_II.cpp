#include "../pch.h"
#include "../header/0113_Path_Sum_II.hpp"

class PathSumII : public ::testing::Test, public LEETCODE_0113::Solution {
public:
	typedef LEETCODE_0113::TreeNode TreeNode;
};

TEST_F(PathSumII, test1)
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);

	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);

	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	EXPECT_EQ(pathSum(root, 22), std::vector<std::vector<int>>({ {5,4,11,2},{5,8,4,5} }));
}