#pragma once

#include <vector>

namespace LEETCODE_0108 {

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
        TreeNode* sortedArrayToBST(std::vector<int>& nums) {
            if (nums.empty())
                return nullptr;
          
            return  BFS(nums, 0, nums.size());;
        }
    private:
        TreeNode* BFS(const std::vector<int>& nums, const int start, const int end)
        {
            if (end <= start)
                return nullptr;

            const int mid = start + (end - start) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = BFS(nums, start, mid);
            node->right = BFS(nums, mid + 1, end);

            return node;
        }
    };
}