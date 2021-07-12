#ifndef BINARYTREE
#define BINARYTREE

struct TreeNode {
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode() = default;
    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

    bool operator==(const TreeNode& root) const;
    bool operator!=(const TreeNode& root) const;
    static bool isEqual(const TreeNode* const root1, const TreeNode* const root2);

    std::string treeNodeToString()const;
    static std::string treeNodeToString(const TreeNode* const root);

    ~TreeNode();
};

#endif //BINARYTREE