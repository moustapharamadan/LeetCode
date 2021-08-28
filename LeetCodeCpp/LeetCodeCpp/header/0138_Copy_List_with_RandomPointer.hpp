#pragma once
#include <unordered_map>

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

            std::unordered_map<Node*,Node*> cache;
            cache[head] = new Node(head->val);
            Node* result = cache[head];
            Node* it = result;
            Node* currentNode = head;
            while (currentNode)
            {
                if (Node* next = currentNode->next)
                {
                    auto node = cache.find(next);
                    if (node == cache.end())
                    {
                        cache[next] = new Node(next->val);
                    }
                    it->next = cache[next];
                }
                if (Node* random = currentNode->random)
                {
                    auto node = cache.find(random);
                    if (node == cache.end())
                    {
                        cache[random] = new Node(random->val);
                    }
                    it->random = cache[random];
                }
                it = it->next;
                currentNode = currentNode->next;
            }
            return result;
        }
    };

}

