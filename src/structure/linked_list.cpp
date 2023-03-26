#include <assert.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

typedef struct LinkedList {
    ListNode* head;
} LinkedList;

ListNode* new_list_node(const int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;

    return node;
}

LinkedList init_linked_list(const int* arr, const int len) {
    LinkedList list;

    if (len == 0) {
        return list;
    }

    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = arr[0];

    ListNode* curr = head;
    for (int i = 1; i < len; i++) {
        curr->next = (ListNode*)malloc(sizeof(ListNode));
        curr = curr->next;
    }

    list.head = head;

    return list;
}

void test_init_binary_tree() {
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    LinkedList list = init_linked_list(arr, sizeof(arr) / sizeof(arr[0]));
}
