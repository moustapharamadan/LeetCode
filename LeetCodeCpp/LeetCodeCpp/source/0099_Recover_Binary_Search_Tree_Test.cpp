#include "../pch.h"
#include "../header/0099_Recover_Binary_Search_Tree.hpp"


class RecoverBinarySearchTreeTest : public ::testing::Test, public LEETCODE_0099::Solution {
public:
	std::unique_ptr<TreeNode> m_tree = nullptr;
	std::unique_ptr<TreeNode> m_expectedTree = nullptr;
};

TEST_F(RecoverBinarySearchTreeTest, True)
{
	m_tree.reset(new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)), nullptr));
	//m_expectedTree = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), nullptr);
	std::cout<< m_tree->treeNodeToString();
}

