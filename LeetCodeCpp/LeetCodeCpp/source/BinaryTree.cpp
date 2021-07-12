#include "../pch.h"
#include "../header/BinaryTree.hpp"
#include <queue>

bool TreeNode::operator==(const TreeNode& root) const
{
    return isEqual(this, &root);
}

bool TreeNode::operator!=(const TreeNode& root) const
{
    return !(*this==root);
}

bool TreeNode::isEqual(const TreeNode* const root1, const TreeNode* const root2)
{
    if (nullptr == root1 && nullptr == root2) {
        return true;
    }

    if (root1 && root2)
    {
        if (root1->val != root2->val) {
            return false;
        }
        return isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
    }
    return false;
}

std::string TreeNode::treeNodeToString() const
{
    return treeNodeToString(this);
}

std::string TreeNode::treeNodeToString(const TreeNode* const root)
{
    std::ostringstream output;
    std::queue<const TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        if (nullptr == node) {
            output << "null, ";
            continue;
        }

        output << node->val << ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.str().substr(0, output.str().length() - 2) + "]";
}

TreeNode::~TreeNode()
{
	if (this->left)
		delete this->left;
	if (this->right)
		delete this->right;
}
