#include "linked_list.h"

#include <vector>

#include <fmt/base.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

namespace structure {

using std::vector;

LinkedList::LinkedList(const vector<int>& nums) {
    if (nums.size() == 0) {
        return;
    }

    auto head = new ListNode(nums[0]);
    auto curr = head;

    for (int i = 1; i < nums.size(); i++) {
        auto node = new ListNode(nums[i]);
        curr->next = node;
        curr = curr->next;
    }

    this->head = head;
}

LinkedList::~LinkedList() noexcept {
    auto curr = this->head;

    while (curr != nullptr) {
        auto prev = curr;
        curr = curr->next;
        delete prev;
    }

    this->head = nullptr;
}

vector<int> traverse(ListNode* head) {
    auto nums = vector<int>();
    auto curr = head;

    while (curr != nullptr) {
        nums.push_back(curr->val);
        curr = curr->next;
    }

    return nums;
}

}  // namespace structure
