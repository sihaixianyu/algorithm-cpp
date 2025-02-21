#include <vector>

#include <fmt/base.h>
#include <gtest/gtest.h>

#include "linked_list.h"

namespace leetcode {
namespace list {

using std::vector;
using structure::LinkedList;
using structure::ListNode;

class Solution {
public:
    /// @Prob: Rotate Image
    /// @Link: https://leetcode.cn/problems/reverse-linked-list/submissions/602388943/?envType=study-plan-v2&envId=top-100-liked
    /// @Tags: ["LinkedList", "Recursively"]
    ListNode* reverseList(ListNode* head) {
        reverseHelper(head);
        return tail;
    }

    ListNode* reverseListPro(ListNode* head) {
        auto prev = static_cast<ListNode*>(nullptr);
        auto curr = head;

        while (curr != nullptr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

private:
    ListNode* reverseHelper(ListNode* curr) {
        if (curr == nullptr || curr->next == nullptr) {
            tail = curr;
            return curr;
        }

        auto next = reverseHelper(curr->next);
        curr->next = nullptr;
        next->next = curr;

        return curr;
    }

    ListNode* tail;
};

namespace tests {

TEST(SolutionTest, test_case_0) {
    auto list = LinkedList({1, 2, 3, 4, 5});
    auto rev_head = Solution().reverseList(list.head);

    auto res = traverse(rev_head);
    auto exp = vector<int>{5, 4, 3, 2, 1};
    ASSERT_EQ(res, exp);
}

TEST(SolutionTest, test_case_1) {
    auto list = LinkedList({1, 2, 3, 4, 5});
    auto rev_head = Solution().reverseListPro(list.head);

    auto res = traverse(rev_head);
    auto exp = vector<int>{5, 4, 3, 2, 1};
    ASSERT_EQ(res, exp);
}

}  // namespace tests
}  // namespace list
}  // namespace leetcode
