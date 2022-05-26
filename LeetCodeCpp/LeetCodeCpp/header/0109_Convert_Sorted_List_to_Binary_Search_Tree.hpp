#pragma once

#include <vector>

namespace LEETCODE_0109 {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
     
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
     
    class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head)
        {
            if (!head)
                return nullptr;

            return BFS(&head, nullptr);
        }

        TreeNode* sortedListToBST1(ListNode* head) 
        {
            if (!head)
                return nullptr;

            int size = 0;
            ListNode* runner = head;
            while (runner)
            {
                ++size;
                runner = runner->next;
            }

            return BFS1(&head, 0, size);
        }
    private:
        TreeNode* BFS(ListNode** start, ListNode** end)
        {
            if (!start || !*start)
                return nullptr;
            if (end && *start == *end)
                return  nullptr;

            ListNode* mid = *start;
            ListNode* runner = *start;
            while (runner && runner->next && (end ? (runner != *end && runner->next != *end) : true))
            {
                mid = mid->next;
                runner = runner->next->next;
            }

            TreeNode* node = new TreeNode(mid->val);

            TreeNode* left = BFS(start, &mid);
            node->left = left;

            TreeNode* right = BFS(&mid->next, end);
            node->right = right;

            return node;
        }

        TreeNode* BFS1(ListNode** head, const int start, const int end)
        {
            if (end <= start)
                return nullptr;

            const int mid = start + (end - start) / 2;
            TreeNode* left = BFS1(head, start, mid);
            TreeNode* node = new TreeNode((*head)->val);
            node->left = left;

            *head = (*head)->next;
           
            TreeNode* right = BFS1(head, mid + 1, end);
            node->right = right;
            return node;
        }
    };
}