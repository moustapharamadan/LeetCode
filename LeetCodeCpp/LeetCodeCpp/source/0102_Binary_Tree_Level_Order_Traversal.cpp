#include "../pch.h"
#include "../header/0102_Binary_Tree_Level_Order_Traversal.hpp"

class BinaryTreeLevelOrderTraversal : public ::testing::Test, public LEETCODE_0102::Solution {
public:
	typedef LEETCODE_0102::TreeNode TreeNode;
};

TEST_F(BinaryTreeLevelOrderTraversal, test1)
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	std::vector<std::vector<int>> result = levelOrder(root);
	std::vector<std::vector<int>> expected = { {3}, {9,20 }, {15,7} };
	EXPECT_EQ(result, expected);
}

TEST_F(BinaryTreeLevelOrderTraversal, test2)
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	std::vector<std::vector<int>> result = levelOrder(root);
	std::vector<std::vector<int>> expected = { {1}, {2,3 }, {4,5} };
	EXPECT_EQ(result, expected);
}

TEST_F(BinaryTreeLevelOrderTraversal, test3)
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(4);
	root->left->left->left->left = new TreeNode(5);

	std::vector<std::vector<int>> result = levelOrder(root);
	std::vector<std::vector<int>> expected = { {1}, {2} ,{3 }, { 4},{5 } };
	EXPECT_EQ(result, expected);
}
