#include "../pch.h"
#include "../header/0652_Find_Duplicate_Subtrees.hpp"

class FindDuplicateSubtrees : public ::testing::Test, public LEETCODE_0652::Solution {
public:
    using TreeNode = LEETCODE_0652::TreeNode;
};


TEST_F(FindDuplicateSubtrees, hasDuplictes)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);

    std::vector<TreeNode*> result = findDuplicateSubtrees(root);
}