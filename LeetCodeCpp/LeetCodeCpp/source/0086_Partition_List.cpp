#include "../pch.h"
#include "../header/0086_Partition_List.hpp"

class PartionList : public ::testing::Test, public LEETCODE_0086::Solution {
public:
	using ListNode = LEETCODE_0086::ListNode;
};

TEST_F(PartionList, test1)
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);

	head = partition(head, 3);

	EXPECT_EQ(head->val, 1);
	EXPECT_EQ(head->next->val, 2);
	EXPECT_EQ(head->next->next->val, 2);
	EXPECT_EQ(head->next->next->next->val, 4);
	EXPECT_EQ(head->next->next->next->next->val, 3);
	EXPECT_EQ(head->next->next->next->next->next->val, 5);
}

TEST_F(PartionList, test2)
{
	ListNode* head = new ListNode(1);

	head = partition(head, 0);

	EXPECT_EQ(head->val, 1);
}

