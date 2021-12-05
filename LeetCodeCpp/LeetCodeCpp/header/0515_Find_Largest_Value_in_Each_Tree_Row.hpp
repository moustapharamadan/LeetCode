#pragma once
#include <vector>
#include <queue>
#include "BinaryTree.hpp"

namespace LEETCODE_0515 {
     
    class Solution {
    public:
        std::vector<int> largestValues(TreeNode* root) {
            if (!root)
                return std::vector<int>();

            std::queue<TreeNode*> q;
            q.push(root);

            std::vector<int> result;
            while (!q.empty())
            {
                const int size = q.size();
                bool hasNode = false;
                int maxi = std::numeric_limits<int>::min();
                for (int i=0;i<size;++i)
                {
                    if (TreeNode* node=q.front())
                    {
                        maxi = std::max(maxi, node->val);
                        q.push(node->left);
                        q.push(node->right);
                        hasNode = true;
                    }
                    q.pop();
                }
                if (hasNode)
                    result.push_back(maxi);
            }
            return result;
        }
    };
}
