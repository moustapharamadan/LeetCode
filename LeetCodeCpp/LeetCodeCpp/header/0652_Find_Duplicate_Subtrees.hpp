#pragma once

#include <vector>
#include <unordered_map>

namespace LEETCODE_0652 {
    
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
        std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

            std::unordered_map<std::string, int> subTreeCount;
            std::vector<TreeNode*> result;
            
            inOrderDFS(root, subTreeCount, result);
            return result;
        }

    private:
        std::string inOrderDFS(TreeNode* node, std::unordered_map<std::string, int>& subTreeCount, std::vector<TreeNode*>& result)
        {
            if (!node)
                return "NULL";

            std::string serialization = std::to_string(node->val) + "," + inOrderDFS(node->left, subTreeCount, result) + "," + inOrderDFS(node->right, subTreeCount, result);
            if (1 == subTreeCount[serialization])
                result.push_back(node);

            ++subTreeCount[serialization];
            return serialization;
        }
    };
}