#include "../pch.h"
#include "../header/0236_Lowest_Common_Ancestor_of_a_Binary_Tree.hpp"

class LowestCommonAncestorofaBinaryTree : public ::testing::Test, public LEETCODE_0236::Solution {
public:
	typedef LEETCODE_0236::TreeNode TreeNode;
};

TEST_F(LowestCommonAncestorofaBinaryTree, test1)
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);

	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);

	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	TreeNode* result = lowestCommonAncestor(root, root->left, root->right);
	EXPECT_EQ(result, root);
}

TEST_F(LowestCommonAncestorofaBinaryTree, test2)
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);

	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);

	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	TreeNode* result = lowestCommonAncestor(root, root->left, root->left->right->right);
	EXPECT_EQ(result, root->left);
}
