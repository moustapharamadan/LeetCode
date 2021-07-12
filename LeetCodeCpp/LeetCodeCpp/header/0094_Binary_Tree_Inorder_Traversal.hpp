#pragma once
#include <stack>
#include <vector>

//In-order (LNR)
//Traverse the left subtree by recursively calling the in-order function.
//Access the data part of the current node.
//Traverse the right subtree by recursively calling the in-order function.
//https://en.wikipedia.org/wiki/Tree_traversal#In-order_(LNR)

struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class TraversalGraph
{
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::stack<TreeNode*> nodesStack;
        std::vector<int> result;

        while (!nodesStack.empty() || nullptr != root)
        {
            while (nullptr != root)
            {
                nodesStack.push(root);
                root = root->left;
            }
            root = nodesStack.top();
            nodesStack.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
    std::vector<int> recursive(TreeNode* root)
    {
        std::vector<int> result;
        recursiveInternal(root,result);
        return result;
    }
private:
    void recursiveInternal(TreeNode* root, std::vector<int>& result)
    {
        if (nullptr != root)
        {
            recursiveInternal(root->left,result);
            result.push_back(root->val);
            recursiveInternal(root->right, result);
        }
    }
};
