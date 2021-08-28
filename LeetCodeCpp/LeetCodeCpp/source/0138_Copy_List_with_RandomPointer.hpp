#pragma once
#include <map>

namespace LEETCODE_0138 {
    // Definition for a Node.
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };
   
    class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (!head)
                return nullptr;

            std::map<int,Node*> cache;
            Node* result = new Node(head->val);
            Node* it = result;
            while (it)
            {
                if (Node* next = head->next)
                {
                    auto node = cache.find(next->val);
                    if (node == cache.end())
                    {
                        cache[next->val] = new Node(next->val);
                    }
                    it->next = cache[next->val];
                }
                if (Node* random = head->random)
                {
                    auto node = cache.find(random->val);
                    if (node == cache.end())
                    {
                        cache[random->val] = new Node(random->val);
                    }
                    it->random = cache[random->val];
                }
                it = it->next;
            }
            return result;
        }
    };

}

