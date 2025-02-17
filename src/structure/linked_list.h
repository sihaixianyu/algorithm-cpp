#pragma once

#include <vector>

#include <fmt/base.h>

namespace linked_list {
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ~ListNode() noexcept {
        fmt::println("[ListNode] This node has been freed. ==> val={} <==", this->val);
    }
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
}  // namespace linked_list
