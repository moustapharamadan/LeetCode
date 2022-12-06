#pragma once


namespace LEETCODE_0114 {    
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
        void flatten(TreeNode* root)
        {
            while (root)
            {
                if (TreeNode* curr = root->left)
                {
                    TreeNode* mostRight = getMostRight(curr);
                    mostRight->right = root->right;
                    root->right = root->left;
                    root->left = nullptr;
                }
                root = root->right;
            }
        }
    private:
        TreeNode* getMostRight(TreeNode* node)
        {
            while (node->right)
            {
                node = node->right;
            }
            return node;
        }
    };
}