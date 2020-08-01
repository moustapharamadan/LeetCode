#pragma once
#include <stack>

struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class ValidateBinarySearchTree {
public:
    bool isValidBST(TreeNode* root) 
    {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root, const long min, const long max)
    {
        if (nullptr == root) return true;
        if (!(min < root->val && root->val<max)) return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
public:
    bool isValidBST_inorder(TreeNode* root)
    {
        std::stack<TreeNode*> treeStack;
        long inorder = LONG_MIN;
        while (!treeStack.empty() || nullptr != root)
        {
            while (nullptr != root)
            {
                treeStack.push(root);
                root = root->left;
            }
            root = treeStack.top();
            treeStack.pop();
            if (root->val < inorder) return false;
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};
