#pragma once
#include <vector>
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

class PostorderTraversalGraph
{
public:
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        if (!root) return {};
        std::vector<int> result;
        std::stack<TreeNode*> nodesStack{ {root} };
        while (!nodesStack.empty()) {
            TreeNode* node = nodesStack.top();
            nodesStack.pop();
            result.insert(result.begin(), node->val);
            if (node->left) nodesStack.push(node->left);
            if (node->right) nodesStack.push(node->right);
        }
        return result;
    }
 }
