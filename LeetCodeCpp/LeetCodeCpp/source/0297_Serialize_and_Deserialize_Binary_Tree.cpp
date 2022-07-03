#include "../pch.h"
#include "../header/0297_Serialize_and_Deserialize_Binary_Tree.hpp"

class SerializeDeserializeBT : public ::testing::Test, public LEETCODE_0297::Codec {
public:
    typedef LEETCODE_0297::TreeNode TreeNode;
};

TEST_F(SerializeDeserializeBT, test1)
{
    Codec ser;
    Codec deser;

    TreeNode* root = new TreeNode(9);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(11);
    root->right->left->left = new TreeNode(10);
    root->right->left->right = new TreeNode(12);

    TreeNode* result = deser.deserialize(ser.serialize(root));

    EXPECT_EQ(root->val, result->val);
    EXPECT_EQ(root->left->val, result->left->val);
    EXPECT_EQ(root->right->val, result->right->val);
    EXPECT_EQ(root->left->left->val, result->left->left->val);
    EXPECT_EQ(root->right->left->val, result->right->left->val);
    EXPECT_EQ(root->right->left->left->val, result->right->left->left->val);
    EXPECT_EQ(root->right->left->right->val, result->right->left->right->val);
}