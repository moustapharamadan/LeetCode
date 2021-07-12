#pragma once
#include <vector>
#include <stack>

//Pre-order (NLR)
//Access the data part of the current node.
//Traverse the left subtree by recursively calling the pre-order function.
//Traverse the right subtree by recursively calling the pre-order function.
//The pre-order traversal is a topologically sorted one, because a parent node is processed before any of its child nodes is done.

struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class PreoderTraversalGraph
{
public:
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::stack<TreeNode*> nodesStack;
        std::vector<int> result;

        while (!nodesStack.empty() || nullptr != root)
        {
            while (nullptr != root)
            {
                result.push_back(root->val);
                nodesStack.push(root);
                root = root->left;
            }
            root = nodesStack.top();
            nodesStack.pop();
            root = root->right;
        }
        return result;
    }
    std::vector<int> recursive(TreeNode* root)
    {
        std::vector<int> result;
        recursiveInternal(root, result);
        return result;
    }
private:
    void recursiveInternal(TreeNode* root, std::vector<int>& result)
    {
        if (nullptr != root)
        {
            result.push_back(root->val);
            recursiveInternal(root->left, result);
            recursiveInternal(root->right, result);
        }
    }
};
