#include "../pch.h"
#include "../header/0237_Delete_Node_in_a_Linked_List.hpp"

TEST(DeleteNode, Test1)
{
    using namespace LEETCODE_0237;
    Solution s;
    auto listNode = std::make_unique<ListNode>(5);
    listNode->next = new ListNode(6);
    listNode->next->next = new ListNode(7);

    s.deleteNode(listNode->next);
    EXPECT_EQ(5, listNode->val);
    EXPECT_EQ(7, listNode->next->val);
    EXPECT_EQ(nullptr, listNode->next->next);
}