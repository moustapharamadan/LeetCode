#pragma once

#include <vector>

namespace LEETCODE_0113 {
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
        std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) 
        {
            std::vector<int> path;
            std::vector<std::vector<int>> result;
            DFS(root, targetSum, 0, path, result);
            return result;
        }
    private:
        void DFS(TreeNode* root, const int targetSum, int sum, std::vector<int>& path, std::vector<std::vector<int>>& result)
        {
            if (!root)
                return;

            sum += root->val;
            path.push_back(root->val);
            if (sum == targetSum && isLeaf(root))
            {
                result.push_back(path);
                return;
            }

            DFS(root->left, targetSum, sum, path, result);
            if (root->left)
            {
                path.pop_back();
            }

            DFS(root->right, targetSum, sum, path, result);
            if (root->right)
            {
                path.pop_back();
            }

        }

        bool isLeaf(TreeNode* node)
        {
            return !node->left && !node->right;
        }
    };
}