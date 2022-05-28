#pragma once

namespace LEETCODE_0437 {
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

        int pathSum(TreeNode* root, int targetSum)
        {
            if (!root)
                return 0;

            std::map<int, int> countMap;
            return pathSum(root, targetSum, 0, countMap);
        }

        int pathSum(TreeNode* root, const int& targetSum, long long currentSum, std::map<int, int>& countMap)
        {
            if (!root)
                return 0;

            currentSum += root->val;
            int remainingSum = currentSum - targetSum;
            int totalPath = countMap[remainingSum];
            if (currentSum == targetSum)
                ++totalPath;

            ++countMap[currentSum];
            totalPath += pathSum(root->left, targetSum, currentSum, countMap);
            totalPath += pathSum(root->right, targetSum, currentSum, countMap);
            --countMap[currentSum];
            return totalPath;
        }

        //int pathSum(TreeNode* root, int targetSum) 
        //{
        //    if (!root)
        //        return 0;

        //    int count = countSum(root, targetSum, 0);
        //    int leftCount = pathSum(root->left, targetSum);
        //    int rightCount = pathSum(root->right, targetSum);

        //    return count + leftCount + rightCount;
        //}

        //int countSum(TreeNode* root, const int targetSum, long long sum)
        //{
        //    if (!root)
        //        return 0;

        //    sum += root->val;
        //    int count = 0;
        //    if (sum == targetSum)
        //        count = 1;

        //    return count + countSum(root->left, targetSum, sum) + countSum(root->right, targetSum, sum);
        //}
    };
}