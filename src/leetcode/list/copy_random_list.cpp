#include <unordered_map>

#include "gtest/gtest.h"

namespace leetcode {
namespace list {

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }

        auto newHead = new Node(head->val);
        auto old2new = std::unordered_map<Node*, Node*>();
        old2new[head] = newHead;

        auto p1 = head, p2 = newHead;
        while (p1->next != nullptr) {
            p2->next = new Node(p1->next->val);
            old2new[p1->next] = p2->next;

            p1 = p1->next;
            p2 = p2->next;
        }

        p1 = head, p2 = newHead;
        while (p1 != nullptr) {
            auto newRandom = old2new[p1->random]; 
            p2->random = newRandom;

            p1 = p1->next;
            p2 = p2->next;
        }

        return newHead;
    }
};

namespace tests {

TEST(SolutionTest, test_case_0) {
    auto n0 = new Node(3);
    auto n1 = new Node(3);
    auto n2 = new Node(3);

    n0->next = n1;
    n1->next = n2;

    n0->random = nullptr;
    n1->random = n0;

    auto clone_head = Solution().copyRandomList(n0);

    EXPECT_EQ(clone_head->next->random, clone_head);
}

}  // namespace tests
}  // namespace list
}  // namespace leetcode
