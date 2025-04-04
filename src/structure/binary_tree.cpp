#include "binary_tree.h"

#include <deque>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <vector>

#include <fmt/base.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

namespace structure {

using std::cout;
using std::deque;
using std::endl;
using std::function;
using std::invalid_argument;
using std::make_tuple;
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

    this->root = nodes[0];
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

    destroy(this->root);
    this->root = nullptr;
};

vector<int> level_traverse(const TreeNode* root) {
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

vector<int> preorder_traverse(const TreeNode* root) {
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

vector<int> preorder_loop(const TreeNode* root) {
    auto ans = vector<int>();
    auto stk = vector{make_tuple(root, 0)};

    while (!stk.empty()) {
        auto [node, tag] = stk.back();
        stk.pop_back();

        if (tag == 1) {
            ans.push_back(node->val);
            cout << fmt::format("Node {{ val: {} }}", node->val) << endl;
            continue;
        }

        if (node->right != nullptr) {
            stk.push_back(make_tuple(node->right, 0));
        }

        if (node->left != nullptr) {
            stk.push_back(make_tuple(node->left, 0));
        }

        stk.push_back(make_tuple(node, 1));
    }

    return ans;
}

vector<int> inorder_traverse(const TreeNode* root) {
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

vector<int> inorder_loop(const TreeNode* root) {
    auto ans = vector<int>();
    auto stk = vector{make_tuple(root, 0)};

    while (!stk.empty()) {
        auto [node, tag] = stk.back();
        stk.pop_back();

        if (tag == 1) {
            ans.push_back(node->val);
            cout << fmt::format("Node {{ val: {} }}", node->val) << endl;
            continue;
        }

        if (node->right != nullptr) {
            stk.push_back(make_tuple(node->right, 0));
        }

        stk.push_back(make_tuple(node, 1));

        if (node->left != nullptr) {
            stk.push_back(make_tuple(node->left, 0));
        }
    }

    return ans;
}

vector<int> postorder_traverse(const TreeNode* root) {
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

vector<int> postorder_loop(const TreeNode* root) {
    auto ans = vector<int>();
    auto stk = vector{make_tuple(root, 0)};

    while (!stk.empty()) {
        auto [node, tag] = stk.back();
        stk.pop_back();

        if (tag == 1) {
            ans.push_back(node->val);
            cout << fmt::format("Node {{ val: {} }}", node->val) << endl;
            continue;
        }

        stk.push_back(make_tuple(node, 1));

        if (node->right != nullptr) {
            stk.push_back(make_tuple(node->right, 0));
        }

        if (node->left != nullptr) {
            stk.push_back(make_tuple(node->left, 0));
        }
    }

    return ans;
}

}  // namespace structure
