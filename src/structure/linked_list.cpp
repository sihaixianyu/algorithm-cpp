#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ~ListNode() {}
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() { head = nullptr; }
    LinkedList(const vector<int>& nums);
    ~LinkedList();

    vector<int> traverse() { return LinkedList::traverse(this->head); }

    static vector<int> traverse(ListNode* head);
};

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

LinkedList::~LinkedList() {
    cout << "destroy linked list" << endl;

    auto curr = this->head;

    while (curr != nullptr) {
        auto prev = curr;
        curr = curr->next;
        // Release the space of node.
        delete prev;
    }

    this->head = nullptr;
}

vector<int> LinkedList::traverse(ListNode* head) {
    auto nums = vector<int>();
    auto curr = head;

    while (curr != nullptr) {
        nums.push_back(curr->val);
        curr = curr->next;
    }

    return nums;
}

void test_new() {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto list = new LinkedList(nums);

    auto ans = list->traverse();
    assert(ans == nums);

    delete list;
}

void test_traverse() {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto list = new LinkedList(nums);

    auto ans = list->traverse();
    assert(ans == nums);
    fmt::print("{}\n", ans);

    delete list;
}

int main() {
    test_new();
    test_traverse();
}
