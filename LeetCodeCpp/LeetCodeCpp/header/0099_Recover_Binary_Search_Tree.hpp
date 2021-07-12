#ifndef LEETCODE_0099
#define LEETCODE_0099

#include <algorithm>
#include "BinaryTree.hpp"

namespace LEETCODE_0099 {

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (nullptr == root)
            return;
        TreeNode* firstNode = nullptr, * middleNode = nullptr, * lastNode = nullptr;
        recoverTree(root, nullptr, &firstNode, &middleNode, &lastNode);
        if (firstNode && lastNode)
            std::swap(firstNode->val, lastNode->val);
        if (firstNode && middleNode)
            std::swap(firstNode->val, middleNode->val);
    }

private:
    void recoverTree(TreeNode* currentNode, TreeNode* previousNode, TreeNode** firstNode, TreeNode** middleNode, TreeNode** lastNode)
    {
        if (nullptr == currentNode)
            return;
        recoverTree(currentNode->left, currentNode, firstNode, middleNode, lastNode);
        if (previousNode && currentNode->val < previousNode->val)
        {
            if (nullptr == *firstNode)
            {
                *firstNode = currentNode;
                *middleNode = previousNode;
            }
            else {
                *lastNode = currentNode;
            }
        }
        recoverTree(currentNode->right, currentNode, firstNode, middleNode, lastNode);
    }
};

}

#endif // LEETCODE_0099
