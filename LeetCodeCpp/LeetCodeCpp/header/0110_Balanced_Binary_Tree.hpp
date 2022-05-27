#pragma once
#include <vector>

namespace LEETCODE_0110 {

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        bool isBalanced(TreeNode* root) 
        {
            bool result = true;
            DFS(root, result);

            return result;
        }

        int DFS(TreeNode* root, bool & result)
        {
            if (!root)
                return 0;

            int left = DFS(root->left, result);
            int right = DFS(root->right, result);
            
            if (std::abs(left - right) > 1)
            {
                result = false;
            }
            return std::max(left, right) + 1;
        }
    };
}