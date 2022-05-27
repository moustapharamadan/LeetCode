#pragma once
#include <vector>

namespace LEETCODE_0102 {

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
        std::vector<std::vector<int>> levelOrderBFS(TreeNode* root) {
            if (!root)
                return std::vector<std::vector<int>>();

            std::vector<std::vector<int>> result;
            std::vector<TreeNode*> current;
            current.push_back(root);
            while (!current.empty())
            {
                result.push_back(std::vector<int>());
                std::vector<TreeNode*> parent = current;
                current.clear();
                for (TreeNode* node : parent)
                {
                    result.back().push_back(node->val);
                    if (TreeNode* left = node->left)
                    {
                        current.push_back(left);
                    }
                    if (TreeNode* right = node->right)
                    {
                        current.push_back(right);
                    }
                }
            }
            return result;
        }

        std::vector<std::vector<int>> levelOrder(TreeNode* root) {
            std::vector<std::vector<int>> result;
            levelOrderDFS(root, result, 0);
            return result;
        }

        void levelOrderDFS(TreeNode* root, std::vector<std::vector<int>>& result, int depth)
        {
            if (!root)
                return;

            if (result.size() == depth)
            {
                result.push_back(std::vector<int>());
            }
            result[depth].push_back(root->val);
            levelOrderDFS(root->left, result, depth + 1);
            levelOrderDFS(root->right, result, depth + 1);
        }
    };
}