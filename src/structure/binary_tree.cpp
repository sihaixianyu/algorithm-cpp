#include <cassert>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define null 1000000

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree(TreeNode* root) : root(root) {}
    BinaryTree(const vector<int>& nums);
    ~BinaryTree();

    vector<int> traverse_level() const;
    vector<int> traverse_preorder();
    vector<int> traverse_inorder();
    vector<int> traverse_postorder();

    static vector<int> level_traverse(const TreeNode* root);
    static void destroy(TreeNode* root);
};

BinaryTree::BinaryTree(const vector<int>& nums) {
    if (nums.empty()) return;

    auto nodes = vector<TreeNode*>();

    for (auto num : nums) {
        if (num == null) {
            nodes.push_back(nullptr);
        }

        auto node = new TreeNode(num);
        nodes.push_back(node);
    }

    for (auto i = 0; i < nodes.size() / 2; i++) {
        if (nodes[i] == nullptr) continue;

        nodes[i]->left = nodes[2 * i + 1];
        nodes[i]->right = nodes[2 * i + 2];
    }

    this->root = nodes[0];
}

BinaryTree::~BinaryTree() {
    cout << "destroy binary tree" << endl;

    BinaryTree::destroy(this->root);
}

void BinaryTree::destroy(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    BinaryTree::destroy(root->left);
    BinaryTree::destroy(root->right);
    delete root;
}

vector<int> BinaryTree::traverse_level() const {
    return BinaryTree::level_traverse(this->root);
}

vector<int> BinaryTree::level_traverse(const TreeNode* root) {
    if (root == nullptr) return vector<int>();

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

void test_new() {
    auto nums = vector{1, 2, 3, 4, 5};
    auto tree = new BinaryTree(nums);

    auto ans = tree->traverse_level();
    assert(ans == nums);

    delete tree;
}

int main() { test_new(); }
