#pragma once

#include<string>

namespace LEETCODE_0449 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
 
    class Codec {
    public:

        // Encodes a tree to a single string.
        std::string serialize(TreeNode* root) {
            std::string order;
            serializeInorderDFS(root, order);
            return order;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(std::string data) {
            int pos = 0;
            return deserializeInorderDFS(data, pos, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        }

    private:
        void serializeInorderDFS(TreeNode* node, std::string& order)
        {
            if (!node)
                return;

            std::string value = std::to_string(node->val);
            value.resize(4);
            order+= value;
            serializeInorderDFS(node->left, order);
            serializeInorderDFS(node->right, order);
        }

        TreeNode* deserializeInorderDFS(const std::string& order, int& pos, int min, int max)
        {
            if (pos >= order.size())
                return nullptr;

            int value = stoi(order.substr(pos, 4));
            if (!(min < value && value < max))
                return nullptr;

            pos += 4;
            TreeNode* node = new TreeNode(value);
            node->left = deserializeInorderDFS(order, pos, min, value);
            node->right = deserializeInorderDFS(order, pos, value, max);
            
            return node;
        }
    };

    // Your Codec object will be instantiated and called as such:
    // Codec* ser = new Codec();
    // Codec* deser = new Codec();
    // string tree = ser->serialize(root);
    // TreeNode* ans = deser->deserialize(tree);
    // return ans;
}