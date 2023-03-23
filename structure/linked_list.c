#include <assert.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct TreeNode *next;
} ListNode;

ListNode *make_list_node(const int val) {
    ListNode *node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;

    return node;
}

void test_make_list_node() {
    ListNode *node = make_list_node(1);
    node->val = 1;

    assert(node->val == 1);
}

int main() { test_make_list_node(); }