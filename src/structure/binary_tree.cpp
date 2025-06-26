#include "binary_tree.h"

#include <deque>
#include <functional>
#include <stdexcept>
#include <vector>

#include <fmt/base.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

namespace structure {
using std::deque;
using std::function;
using std::invalid_argument;
using std::vector;

constexpr int null = -1;

BinaryTree::BinaryTree(const vector<int>& nums) {
    if (nums.empty())
        return;

    auto nodes = vector<TreeNode*>();

    for (auto i = 0; i < nums.size(); i++) {
        if (nums[i] == null) {
            if (2 * i + 1 < nums.size() && nums[2 * i + 1] != null) {
                throw invalid_argument(fmt::format("Invalid construct data: {}", nums));
            }
            if (2 * i + 2 < nums.size() && nums[2 * i + 2] != null) {
                throw invalid_argument(fmt::format("Invalid construct data: {}", nums));
            }

            nodes.push_back(nullptr);
            continue;
        }

        auto node = new TreeNode(nums[i]);
        nodes.push_back(node);
    }

    for (auto i = 0; i < nodes.size() / 2; i++) {
        if (nodes[i] == nullptr)
            continue;

        nodes[i]->left = nodes[2 * i + 1];
        nodes[i]->right = nodes[2 * i + 2];
    }

    this->root_ = nodes[0];
}

BinaryTree::~BinaryTree() noexcept {
    function<void(TreeNode*)> destroy = [&](TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        destroy(root->left);
        destroy(root->right);

        delete root;
    };

    destroy(this->root_);
    this->root_ = nullptr;
};

vector<int> BinaryTree::preorder_traverse(const TreeNode* root) {
    auto ans = vector<int>();

    function<void(const TreeNode*)> helper = [&](const TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        ans.push_back(root->val);
        helper(root->left);
        helper(root->right);
    };

    helper(root);

    return ans;
}

vector<int> BinaryTree::inorder_traverse(const TreeNode* root) {
    auto ans = vector<int>();

    function<void(const TreeNode*)> helper = [&](const TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    };

    helper(root);

    return ans;
}

vector<int> BinaryTree::postorder_traverse(const TreeNode* root) {
    auto ans = vector<int>();

    function<void(const TreeNode*)> helper = [&](const TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        helper(root->left);
        helper(root->right);
        ans.push_back(root->val);
    };

    helper(root);

    return ans;
}

vector<int> BinaryTree::level_traverse(const TreeNode* root) {
    if (root == nullptr)
        return vector<int>();

    auto ans = vector<int>();
    auto dq = deque{root};

    while (!dq.empty()) {
        auto curr = dq.front();
        dq.pop_front();
        ans.push_back(curr->val);

        if (curr->left != nullptr) {
            dq.push_back(curr->left);
        }
        if (curr->right != nullptr) {
            dq.push_back(curr->right);
        }
    }

    return ans;
}
}  // namespace structure
