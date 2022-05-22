#pragma once
#include <vector>

namespace LEETCODE_0086 {
     
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
     
    class Solution {
    public:
        ListNode* partition(ListNode* head, int x) 
        {
            std::vector<ListNode*> temp;
            ListNode* tempHead = head;

            ListNode* previousNode = nullptr;
            ListNode* currentNode = head;

            while (currentNode)
            {
                if (currentNode->val >= x)
                {
                    temp.push_back(currentNode);
                    if (previousNode)
                    {
                        previousNode->next = currentNode->next;
                    }
                    else
                    {
                        head = currentNode->next;
                    }
                }
                else
                {
                    previousNode = currentNode;
                }
                currentNode = currentNode->next;
            }

            if (previousNode)
            {
                for (ListNode* node : temp)
                {
                    previousNode->next = node;
                    previousNode = previousNode->next;
                }
                previousNode->next = nullptr;
            }

            return head ? head : tempHead;
        }
    };
}