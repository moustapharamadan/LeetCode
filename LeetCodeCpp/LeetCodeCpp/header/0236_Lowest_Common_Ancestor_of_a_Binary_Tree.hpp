#pragma once
#include <vector>
#include <map>

namespace LEETCODE_0236 {

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

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            std::map< TreeNode*, TreeNode*> parents;
            BFS(root, p, q, false, false, parents);

            std::vector< TreeNode*> pPath;
            TreeNode* pParent = p;
            while (pParent)
            {
                pPath.push_back(pParent);
                pParent = parents[pParent];
            }
            
            std::vector< TreeNode*> qPath;
            TreeNode* qParent = q;
            while (qParent)
            {
                qPath.push_back(qParent);
                qParent = parents[qParent];
            }

            const int size = pPath.size() < qPath.size() ? pPath.size() : qPath.size();
            TreeNode* result = nullptr;
            for (size_t i = 1; i <= size; ++i)
            {
                if (pPath[pPath.size() - i] != qPath[qPath.size() - i])
                    return result;
                result = pPath[pPath.size() - i];
            }
            return result;
        }

        bool BFS(TreeNode* root, TreeNode* p, TreeNode* q, bool pFound, bool qFound, std::map< TreeNode*, TreeNode*>& parents)
        {
            if (!root)
                return false;
            
            if (root == p)
                pFound = true;
            if (root == q)
                qFound = true;

            if(pFound && qFound)
                return true;

            if (root->right)
            {
                parents[root->right] = root;
            }
            if (root->left)
            {
                parents[root->left] = root;
            }
            return BFS(root->left, p, q, pFound, qFound, parents) || BFS(root->right, p, q, pFound, qFound, parents);
        }
 
        // Recursive Approach using backtracking
        //TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
        //{
        //    TreeNode* node = nullptr;
        //    backtracking(root, p, q, &node);
        //    return node;
        //}

        //int backtracking(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** result)
        //{
        //    if (!root)
        //        return 0;

        //    const int left = backtracking(root->left, p, q, result);
        //    const int mid = root == p || root == q ? 1 : 0;
        //    const int right = backtracking(root->right, p, q, result);

        //    if (left + mid + right >= 2)
        //    {
        //        *result = root;
        //    }

        //    return left + mid + right > 0;
        //}

        // Memory Limit Exceeded
        //TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
        //{
        //    std::vector<TreeNode*> pNodePath;
        //    std::vector<TreeNode*> qNodePath;
        //    
        //    bool foundP = DFS(root, p, pNodePath);
        //    bool foundQ = DFS(root, q, qNodePath);

        //    TreeNode* result = nullptr;
        //    if (foundP && foundQ)
        //    {
        //        const int size = std::min(pNodePath.size(), qNodePath.size());
        //        for (size_t i =0; i< size; ++i)
        //        {
        //            if (pNodePath[i] != qNodePath[i])
        //                break;

        //            result = pNodePath[i];

        //        }
        //    }
        //    return result;
        //}

        //bool DFS(TreeNode* root, TreeNode* node, std::vector<TreeNode*>& pathResult, std::vector<TreeNode*> path = {})
        //{
        //    if (!root)
        //        return false;

        //    path.push_back(root);
        //    if (root == node)
        //    {
        //        pathResult = path;
        //        return true;
        //    }

        //    return DFS(root->left, node, pathResult, path) || DFS(root->right, node, pathResult, path);
        //}
    };
}