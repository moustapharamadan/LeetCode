#include "../pch.h"
#include "../header/0100_Same_Tree.hpp"

class SameTreeTest : public ::testing::Test, public LEETCODE_0100::Solution {
public:
	std::unique_ptr<TreeNode> m_node1 = nullptr;
	std::unique_ptr<TreeNode> m_node2 = nullptr;
};

TEST_F(SameTreeTest, True)
{
	m_node1.reset(new TreeNode(1, new TreeNode(2), new TreeNode(3)));
	m_node2.reset(new TreeNode(1, new TreeNode(2), new TreeNode(3)));

	EXPECT_TRUE(isSameTree(m_node1.get(), m_node2.get()));
	EXPECT_TRUE(*m_node1 == *m_node2);
}

TEST_F(SameTreeTest, False)
{
	m_node1.reset(new TreeNode(1, new TreeNode(2), nullptr));
	m_node2.reset(new TreeNode(1, nullptr, new TreeNode(2)));

	EXPECT_FALSE(isSameTree(m_node1.get(), m_node2.get()));
}

