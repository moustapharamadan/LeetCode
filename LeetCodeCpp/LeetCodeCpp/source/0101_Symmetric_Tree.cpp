#include "../pch.h"
#include "../header/0101_Symmetric_Tree.hpp"

class SymmetricTree : public ::testing::Test, public LEETCODE_0101::Solution {
};

TEST_F(SymmetricTree, Test) {
	using namespace LEETCODE_0101;
	TreeNode* node = new TreeNode(1);
	node->left = new TreeNode(2);
	node->right = new TreeNode(2);
	node->left->left = new TreeNode(3);
	node->left->right = new TreeNode(4);
	node->right->left = new TreeNode(4);
	node->right->right = new TreeNode(3);
	EXPECT_TRUE(isSymmetric(node));
}

TEST_F(SymmetricTree, Test2) {
	using namespace LEETCODE_0101;
	TreeNode* node = new TreeNode(1);
	node->left = nullptr;
	node->right = new TreeNode(2);
	EXPECT_FALSE(isSymmetric(node));
}

TEST_F(SymmetricTree, Test3) {
	using namespace LEETCODE_0101;
	TreeNode* node = new TreeNode(1);
	node->left = new TreeNode(2);
	node->right = new TreeNode(3);
	EXPECT_FALSE(isSymmetric(node));
}
