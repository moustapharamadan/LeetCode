#pragma once

#include<queue>

namespace LEETCODE_0572 {
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
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if (!root || !subRoot)
                return false;

            std::queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode* currentNode = q.front();
                if (currentNode->val == subRoot->val && BFS(currentNode, subRoot))
                {
                    return true;
                }
                q.pop();
                if (currentNode->left)
                    q.push(currentNode->left);
                if (currentNode->right)
                    q.push(currentNode->right);
            }

            return false;
        }

        bool BFS(TreeNode* root, TreeNode* subRoot)
        {
            if (!subRoot && !root)
                return true;

            if (!subRoot || !root)
                return false;

            if (root->val != subRoot->val)
                return false;

            return BFS(root->left, subRoot->left) && BFS(root->right, subRoot->right);
        }

    };
}