#pragma once

#include <vector>

namespace structure {

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ~ListNode() noexcept {};
};

class LinkedList {
public:
    ListNode* head;

    explicit LinkedList() : head(nullptr) {};
    explicit LinkedList(const std::vector<int>& nums);

    LinkedList(const LinkedList& other) = delete;
    LinkedList& operator=(const LinkedList& other) = delete;

    LinkedList(const LinkedList&& other) = delete;
    LinkedList& operator=(const LinkedList&& other) = delete;

    ~LinkedList() noexcept;
};

std::vector<int> traverse(ListNode* head);

}  // namespace structure
