#pragma once
#include <vector>
#include "BinaryTree.hpp"

namespace LEETCODE_0515 {
     
    class Solution {
    public:
        std::vector<int> largestValues(TreeNode* root) {
            if (!root)
                return std::vector<int>();

            std::vector<TreeNode*> q;
            q.push_back(root);

            std::vector<int> result;
            while (!q.empty())
            {
                std::vector<TreeNode*> temp = q;
                q.clear();
                bool hasNode = false;
                int maxi = std::numeric_limits<int>::min();
                for (const TreeNode* node : temp)
                {
                    if (node)
                    {
                        maxi = std::max(maxi, node->val);
                        q.push_back(node->left);
                        q.push_back(node->right);
                        hasNode = true;
                    }
                }
                if (hasNode)
                    result.push_back(maxi);
            }
            return result;
        }
    };
}
