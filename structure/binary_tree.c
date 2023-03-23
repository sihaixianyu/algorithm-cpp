#include <assert.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *make_tree_node(const int val) {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void test_make_tree_node() {
    TreeNode *node = make_tree_node(1);
    node->val = 1;

    assert(node->val == 1);
}

int main() { test_make_tree_node(); }