#pragma once

#include<string>

namespace LEETCODE_0297 {

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
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
            return deserializeInorderDFS(data, pos);
        }

    private:
        void serializeInorderDFS(TreeNode* node, std::string& order)
        {
            if (!node)
            {
                order += "NULL ";
                return;
            }
            std::string value = std::to_string(node->val);
            value.resize(5);
            order += value;
            serializeInorderDFS(node->left, order);
            serializeInorderDFS(node->right, order);
        }

        TreeNode* deserializeInorderDFS(const std::string& order, int& pos)
        {
            if (pos >= order.size())
                return nullptr;

            std::string nodeValue = order.substr(pos, 5);
            pos += 5;
            if ("NULL " == nodeValue)
                return nullptr;

            int value = stoi(nodeValue);
            TreeNode* node = new TreeNode(value);
            node->left = deserializeInorderDFS(order, pos);
            node->right = deserializeInorderDFS(order, pos);

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