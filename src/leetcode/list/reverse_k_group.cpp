#include <fmt/base.h>
#include <gtest/gtest.h>

#include <vector>

#include "linked_list.h"

namespace list {

using std::vector;
using structure::LinkedList;
using structure::ListNode;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto nextHead = head;
        
        for (auto i = 0; i < k; i++) {
            if (!nextHead) {
                return head;
            }
            nextHead = nextHead->next;
        }

        auto newHead = reverse_list(head, nextHead);
        head->next = reverseKGroup(nextHead, k);

        return newHead;
    }

    ListNode* reverse_list(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        auto curr = head;

        while (curr != tail) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};

namespace tests {

TEST(SolutionTest, test_case_0) {
    auto nums = vector<int>{1, 2, 3, 4, 5};
    auto list = LinkedList(nums);

    auto rev_list = Solution().reverseKGroup(list.head, 2);
    auto res = structure::traverse(rev_list);

    auto exp = vector<int>{2, 1, 4, 3, 5};
    EXPECT_EQ(res, exp);
}

TEST(SolutionTest, test_case_1) {
    auto nums = vector<int>{1, 2, 3, 4, 5};
    auto list = LinkedList(nums);

    auto rev_list = Solution().reverseKGroup(list.head, 3);
    auto res = structure::traverse(rev_list);

    auto exp = vector<int>{3, 2, 1, 4, 5};
    EXPECT_EQ(res, exp);
}

}  // namespace tests
}  // namespace list
