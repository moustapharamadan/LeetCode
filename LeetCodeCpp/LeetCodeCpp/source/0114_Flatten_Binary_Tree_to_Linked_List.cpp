#include "../pch.h"
#include "../header/0114_Flatten_Binary_Tree_to_Linked_List.hpp"

class FlattenBT : public ::testing::Test, public LEETCODE_0114::Solution {
public:
	typedef LEETCODE_0114::TreeNode TreeNode;
};

TEST_F(FlattenBT, test1)
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);

	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);

	root->right->right = new TreeNode(6);

	flatten(root);
}