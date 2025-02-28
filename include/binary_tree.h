#pragma once

#include <vector>

#include <fmt/base.h>

namespace structure {

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode& other) : val(other.val), left(other.left), right(other.right) {};
    ~TreeNode() {
        fmt::println("[TreeNode] This node has been freed. ==> val={} <==", this->val);
    }
};

class BinaryTree {
public:
    TreeNode* root;

    explicit BinaryTree(TreeNode* root) : root(nullptr) {};
    explicit BinaryTree(const std::vector<int>& nums);

    BinaryTree(const BinaryTree& other) = delete;
    BinaryTree& operator=(const BinaryTree& other) = delete;

    ~BinaryTree() noexcept;
};

}  // namespace structure
