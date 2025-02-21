#include <fmt/base.h>

namespace binary_tree {
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
}  // namespace binary_tree
