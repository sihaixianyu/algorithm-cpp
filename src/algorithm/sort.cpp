#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

vector<int> bubble_sort(vector<int>& nums) {
    auto ans = vector(nums);

    for (auto i = ans.size() - 1; i > 0; i--) {
        for (auto j = 0; j < i; j++) {
            if (ans[j] > ans[j + 1]) {
                swap(ans[j], ans[j + 1]);
            }
        }
    }

    return ans;
}

vector<int> select_sort(const vector<int>& nums) {
    auto ans = nums;

    return ans;
}

vector<int> insert_sort(const vector<int>& nums) {
    auto ans = vector<int>();

    return ans;
}

vector<int> hill_sort(const vector<int>& nums) {
    auto ans = vector<int>();

    return ans;
}

vector<int> quick_sort(const vector<int>& nums) {
    auto ans = vector<int>();

    return ans;
}

vector<int> merge_sort(const vector<int>& nums) {
    auto ans = vector<int>();

    return ans;
}

int main() {
    auto nums = vector{5, 4, 3, 2, 1};
    auto expected = vector{1, 2, 3, 4, 5};

    auto ans = bubble_sort(nums);
    fmt::print("[bubble_sort]: {}", ans);
    assert(ans == expected);
}
