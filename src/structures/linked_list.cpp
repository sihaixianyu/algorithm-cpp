#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int null = -1;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ~ListNode() {
        cout << "[DEL] ListNode { val: " << this->val << " }" << endl;
    }
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() : head(nullptr){};
    LinkedList(const vector<int>& nums);
    LinkedList(const LinkedList& other) noexcept;
    LinkedList& operator=(const LinkedList& other) noexcept;
    ~LinkedList() noexcept;
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

LinkedList::LinkedList(const LinkedList& other) noexcept {
    if (other.head == nullptr) {
        return;
    }

    this->head = new ListNode(other.head->val);

    auto curr1 = other.head;
    auto curr2 = this->head;

    while (curr1->next != nullptr) {
        curr2->next = new ListNode(curr1->next->val);

        curr1 = curr1->next;
        curr2 = curr2->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other) noexcept {
    // TODO
    return *this;
}

LinkedList::~LinkedList() noexcept {
    cout << "[DEL] LinkedList in addr: " << this << endl;

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

void test_new() {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto list = new LinkedList(nums);
    auto ans = traverse(list->head);
    assert(ans == nums);

    auto list_copy = new LinkedList(*list);
    ans = traverse(list->head);
    assert(ans == nums);

    delete list;
    delete list_copy;
}

void test_traverse() {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto list = new LinkedList(nums);

    auto ans = traverse(list->head);
    assert(ans == nums);

    delete list;
}

int main() {
    test_new();
    // test_traverse();
}
