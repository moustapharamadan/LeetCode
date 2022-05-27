#pragma once

#include<vector>

namespace LEETCODE_0098 {
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
        bool isValidBST(TreeNode* root) {
            //constexpr long long left = std::numeric_limits<long long>::min();
            //constexpr long long right = std::numeric_limits<long long>::max();
            //return DFS(root, left, right);

            //TreeNode* node = nullptr;
            //return inorderTraversal(root, &node);

            std::vector<int> values;
            inorderTraversalWithSpaceComplexity(root, values);
            for (size_t i = 1; i < values.size(); ++i)
            {
                if (values[i] <= values[i - 1])
                    return false;
            }
            return true;
        }

        bool DFS(TreeNode* root, long long left, long long right)
        {
            if (!root)
            {
                return true;
            }

            if (!(left < root->val && root->val < right))
            {
                return false;
            }

            return DFS(root->left, left, root->val) && DFS(root->right, root->val, right);
        }

        bool inorderTraversal(TreeNode* root, TreeNode** lastNode)
        {
            if (!root)
                return true;

            bool result = inorderTraversal(root->left, lastNode);
            if(!result)
                return false;

            if (*lastNode && root->val <= (*lastNode)->val)
                return false;

            *lastNode = root;
            return inorderTraversal(root->right, lastNode);
        }

        void inorderTraversalWithSpaceComplexity(TreeNode* root, std::vector<int> & values)
        {
            if (!root)
                return;

            inorderTraversalWithSpaceComplexity(root->left, values);
            values.push_back(root->val);
            inorderTraversalWithSpaceComplexity(root->right, values);
        }
    };

    //class ValidateBinarySearchTree {
    //public:
    //    bool isValidBST(TreeNode* root)
    //    {
    //        return isValidBST(root, LONG_MIN, LONG_MAX);
    //    }
    //private:
    //    bool isValidBST(TreeNode* root, const long min, const long max)
    //    {
    //        if (nullptr == root) return true;
    //        if (!(min < root->val && root->val < max)) return false;
    //        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    //    }
    //public:
    //    bool isValidBST_inorder(TreeNode* root)
    //    {
    //        std::stack<TreeNode*> treeStack;
    //        long inorder = LONG_MIN;
    //        while (!treeStack.empty() || nullptr != root)
    //        {
    //            while (nullptr != root)
    //            {
    //                treeStack.push(root);
    //                root = root->left;
    //            }
    //            root = treeStack.top();
    //            treeStack.pop();
    //            if (root->val < inorder) return false;
    //            inorder = root->val;
    //            root = root->right;
    //        }
    //        return true;
    //    }
    //};
}