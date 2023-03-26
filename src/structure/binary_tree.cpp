#include <assert.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* new_tree_node(const int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void test_init_tree_node() {
    TreeNode* node = new_tree_node(1);
    node->val = 1;

    assert(node->val == 1);

    free(node);
}

int main() {
    test_init_tree_node();
}
