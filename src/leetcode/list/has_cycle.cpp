#include <fmt/base.h>
#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

#include "linked_list.h"

namespace leetcode {
namespace list {

using std::unordered_set;
using std::vector;
using structure::LinkedList;
using structure::ListNode;

class Solution {
public:
    /// @Prob: Rotate Image
    /// @Link:
    /// https://leetcode.cn/problems/reverse-linked-list/submissions/602388943/?envType=study-plan-v2&envId=top-100-liked
    /// @Tags: ["LinkedList", "Recursively"]
    bool hasCycle(ListNode* head) {
        auto addrs = unordered_set<ListNode*>();

        auto curr = head;
        while (curr != nullptr) {
            if (addrs.contains(curr)) {
                return true;
            }
            addrs.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};

namespace tests {

TEST(SolutionTest, test_case_0) {
    auto nums = vector<int>{3, 2, 0, -4};
    auto list = LinkedList(nums);
    list.tail->next = list.head->next;
    EXPECT_TRUE(Solution().hasCycle(list.head));
}

TEST(SolutionTest, test_case_1) {
    auto nums = vector<int>{1, 2};
    auto list = LinkedList(nums);
    list.tail->next = list.head;
    EXPECT_TRUE(Solution().hasCycle(list.head));
}

}  // namespace tests
}  // namespace list
}  // namespace leetcode
