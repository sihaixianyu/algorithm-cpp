#pragma once

#include <vector>

#include "fmt/base.h"

namespace structure {
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    explicit TreeNode(const TreeNode& other) : val(other.val), left(other.left), right(other.right) {};
};

class BinaryTree {
public:
    explicit BinaryTree(TreeNode* root) : root_(root) {};
    explicit BinaryTree(const std::vector<int>& nums);

    ~BinaryTree() noexcept;

    BinaryTree(const BinaryTree& other) = delete;
    BinaryTree& operator=(const BinaryTree& other) = delete;

public:
    static std::vector<int> preorder_traverse(const TreeNode* root);
    static std::vector<int> inorder_traverse(const TreeNode* root);
    static std::vector<int> postorder_traverse(const TreeNode* root);
    static std::vector<int> level_traverse(const TreeNode* root);

private:
    TreeNode* root_;
};

}  // namespace structure
