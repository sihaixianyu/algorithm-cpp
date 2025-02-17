#include "linked_list.h"

#include <vector>

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

namespace linked_list {
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

namespace tests {
class LinkedListTest : public testing::Test {
protected:
    vector<int> input_1;
    vector<int> expected_1;

    LinkedListTest() {
        this->input_1 = vector{1, 2, 3, 4};
        this->expected_1 = vector{1, 2, 3, 4};
    }

    ~LinkedListTest() {}
};

TEST_F(LinkedListTest, ConstructorTest) {
    vector<int> ans;

    auto list = new LinkedList(this->input_1);
    ans = traverse(list->head);
    ASSERT_EQ(ans, this->expected_1);

    delete list;
}
} // namespace tests
} // namespace linked_list
