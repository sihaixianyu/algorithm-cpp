#include <any>
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

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
    auto ans = vector(nums);

    for (auto i = 0; i < nums.size() - 1; i++) {
        auto min_idx = i;
        for (auto j = i + 1; j < nums.size(); j++) {
            if (ans[j] < ans[min_idx]) {
                min_idx = j;
            }
        }
        swap(ans[i], ans[min_idx]);
    }

    return ans;
}

vector<int> insert_sort(const vector<int>& nums) {
    auto ans = vector<int>(nums);

    for (auto i = 1; i < ans.size(); i++) {
        auto ins_val = ans[i];
        auto j = i - 1;
        for (; j >= 0; j--) {
            if (ans[j] <= ins_val) {
                break;
            }
            ans[j + 1] = ans[j];
        }
        ans[j + 1] = ins_val;
        fmt::print("{}\n", ans);
    }

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

namespace tests {
class SortTest : public testing::Test {
protected:
    vector<int> input_1, input_2, input_3;
    vector<int> expected_1, expected_2, expected_3;

    SortTest() {
        cout << "[NOTE] invoking constructor" << endl;

        this->input_1 = vector{1, 2, 3, 4};
        this->expected_1 = vector{1, 2, 3, 4};

        this->input_2 = vector{5, 4, 3, 2, 1};
        this->expected_2 = vector{1, 2, 3, 4, 5};

        this->input_3 = vector{6, 2, 3, 1, 5, 4};
        this->expected_3 = vector{1, 2, 3, 4, 5, 6};
    }

    ~SortTest() {
        cout << "[NOTE] invoking destructor" << endl;
    }

    void SetUp() override {
        // cout << "[NOTE] invoke setup method" << endl;
    }

    void TearDown() override {
        // cout << "[NOTE] invoke teardown method" << endl;
    }
};

TEST_F(SortTest, BubbleSortTest) {
    vector<int> ans;

    ans = bubble_sort(this->input_1);
    ASSERT_EQ(ans, this->expected_1);

    ans = bubble_sort(this->input_2);
    ASSERT_EQ(ans, this->expected_2);

    ans = bubble_sort(this->input_3);
    ASSERT_EQ(ans, this->expected_3);

    this->expected_3.push_back(5);
}

TEST_F(SortTest, SelectSortTest) {
    vector<int> ans;

    ans = select_sort(this->input_1);
    EXPECT_EQ(ans, this->expected_1);

    ans = select_sort(this->input_2);
    ASSERT_EQ(ans, this->expected_2);

    ans = select_sort(this->input_3);
    ASSERT_EQ(ans, this->expected_3);
}

TEST_F(SortTest, InsertSortTest) {
    vector<int> ans;

    ans = insert_sort(this->input_1);
    EXPECT_EQ(ans, this->expected_1);

    ans = insert_sort(this->input_2);
    ASSERT_EQ(ans, this->expected_2);

    ans = insert_sort(this->input_3);
    ASSERT_EQ(ans, this->expected_3);
}
} // namespace tests
