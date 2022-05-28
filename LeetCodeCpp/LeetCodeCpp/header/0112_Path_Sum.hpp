#pragma once

#include<queue>

namespace LEETCODE_0112 {
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
        bool hasPathSum(TreeNode* root, int targetSum) 
        {
            return DFS(root, 0, targetSum);
        }

    private:
        bool DFS(TreeNode* root, int currentSum, const int targetSum)
        {
            if (!root)
                return false;

            currentSum += root->val;
            if (currentSum == targetSum && isLeaf(root))
                return true;

            return DFS(root->left, currentSum, targetSum) || DFS(root->right, currentSum, targetSum);
        }
        bool isLeaf(TreeNode* node)
        {
            return !node->left && !node->right;
        }
    };
}