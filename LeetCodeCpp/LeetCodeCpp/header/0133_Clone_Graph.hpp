#pragma once
#include <vector>
#include <map>

namespace LEETCODE_0133 {
    class Node {
    public:
        int val;
        std::vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = std::vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = std::vector<Node*>();
        }
        Node(int _val, std::vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };


    class Solution {
    public:
        Node* cloneGraph(Node* node) {
            if (!node)
                return nullptr;
            std::map<Node*,Node*>cache;
            return cloneGraphInternal(node, cache);
        }
    private:
        Node* cloneGraphInternal(Node* node, std::map<Node*,Node*>& cache)
        {
            if (cache.end() != cache.find(node))
                return cache[node];

            cache[node] = new Node(node->val);
            Node* result = cache[node];
            for (Node* n : node->neighbors) {
                result->neighbors.push_back(cloneGraphInternal(n, cache));
            }
            return result;
        }
    };
}