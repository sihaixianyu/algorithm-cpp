#include <fmt/core.h>

#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define null (1 << 30) - 1

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode& other) : val(other.val), left(other.left), right(other.right){};
    TreeNode& operator=(const TreeNode& other) {
        this->val = other.val;
        this->left = other.left;
        this->right = other.right;

        return *this;
    };
    ~TreeNode() {
        fmt::print("TreeNode<{}> has been released\n", this->val);
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree(TreeNode* root) : root(nullptr){};
    BinaryTree(const vector<int>& nums);
    BinaryTree(const BinaryTree& other);
    BinaryTree& operator=(const BinaryTree& other);
    ~BinaryTree();
};

BinaryTree::BinaryTree(const vector<int>& nums) {
    if (nums.empty())
        return;

    auto nodes = vector<TreeNode*>();

    for (auto num : nums) {
        if (num == null) {
            nodes.push_back(nullptr);
            continue;
        }

        auto node = new TreeNode(num);
        nodes.push_back(node);
    }

    for (auto i = 0; i < nodes.size() / 2; i++) {
        if (nodes[i] == nullptr) {
            if (nodes[2 * i + 1] != nullptr) {
                cout << "[CONSTRUCTOR]" << endl;
                delete nodes[2 * i + 1];
            }

            if (nodes[2 * i + 2] != nullptr) {
                cout << "[CONSTRUCTOR]" << endl;
                delete nodes[2 * i + 2];
            }

            continue;
        }

        nodes[i]->left = nodes[2 * i + 1];
        nodes[i]->right = nodes[2 * i + 2];
    }

    this->root = nodes[0];
}

BinaryTree::BinaryTree(const BinaryTree& other) {
    // TODO
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
    // TODO
    return *this;
}

BinaryTree::~BinaryTree() {
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

void test_new() {
    auto nums = vector{1, 2, 3, null, null, null, null, 5};
    auto tree = new BinaryTree(nums);

    auto node1 = tree->root;
    auto node2 = tree->root->left;
    auto node3 = tree->root->right;

    assert(node1->val == 1);
    assert(node2->val == 2);
    assert(node3->val == 3);

    cout << "[DESTRUCTOR]" << endl;
    delete tree;
}

void test_level_traverse() {
    auto nums = vector{1, 2, 3, 4, 5};
    auto tree = new BinaryTree(nums);

    auto ans = level_traverse(tree->root);
    assert(ans == nums);

    delete tree;
}

void test_preorder_traverse() {
    auto nums = vector{1, 2, 3, 4, 5};
    auto tree = new BinaryTree(nums);

    auto ans = preorder_traverse(tree->root);
    auto expected = vector{1, 2, 4, 5, 3};

    assert(ans == expected);

    delete tree;
}

void test_inorder_traverse() {
    auto nums = vector{1, 2, 3, 4, 5};
    auto tree = new BinaryTree(nums);

    auto ans = inorder_traverse(tree->root);
    auto expected = vector{4, 2, 5, 1, 3};

    assert(ans == expected);

    delete tree;
}

void test_postorder_traverse() {
    auto nums = vector{1, 2, 3, 4, 5};
    auto tree = new BinaryTree(nums);

    auto ans = postorder_traverse(tree->root);
    auto expected = vector{4, 5, 2, 3, 1};

    assert(ans == expected);

    delete tree;
}

int main() {
    test_new();
    test_preorder_traverse();
    test_inorder_traverse();
    test_postorder_traverse();
}
