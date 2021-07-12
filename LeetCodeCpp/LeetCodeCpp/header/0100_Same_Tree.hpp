#ifndef LEETCODE_0100
#define LEETCODE_0100

#include "BinaryTree.hpp"

namespace LEETCODE_0100 {

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (nullptr == p && nullptr == q) {
            return true;
        }

        if (p && q)
        {
            if (p->val != q->val) {
                return false;
            }
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }
};

}

#endif // LEETCODE_0100


