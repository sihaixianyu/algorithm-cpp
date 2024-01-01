#include <algorithm>
#include <functional>
#include <vector>

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

using namespace std;

namespace sort {
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
    }

    return ans;
}

vector<int> shell_sort(const vector<int>& nums) {
    auto ans = vector<int>(nums);

    function<void(int)> helper = [&](int gap) {
        for (auto i = gap; i < ans.size(); i += 1) {
            auto temp = ans[i];
            // fmt::print("ins: {}, before: {}\n", temp, ans);

            auto j = i;
            for (; j >= gap && ans[j - gap] > temp; j -= gap) {
                ans[j] = ans[j - gap];
            }
            ans[j] = temp;
            // fmt::print("ins: {}, after: {}\n", temp, ans);
        }
        // fmt::print("[GAP Used] gap: {}, ans: {}\n", gap, ans);
    };

    for (auto gap = ans.size() / 2; gap > 0; gap /= 2) {
        helper(gap);
    }

    return ans;
}

vector<int> quick_sort(const vector<int>& nums) {
    auto ans = vector<int>(nums);

    function<void(int, int)> helper = [&](int left, int right) {
        if (left >= right) {
            return;
        }

        auto lp = left;
        auto rp = right;

        while (lp < rp) {
            while (lp < rp && ans[lp] < ans[left]) {
                lp += 1;
            }
            while (lp < rp && ans[rp] > ans[left]) {
                rp -= 1;
            }
            swap(ans[lp], ans[rp]);
        }
        swap(ans[left], ans[lp]);

        helper(left, lp - 1);
        helper(lp + 1, right);
    };

    helper(0, ans.size() - 1);

    return ans;
}

vector<int> merge_sort(const vector<int>& nums) {
    auto ans = vector<int>(nums);

    auto merge = [&](int left, int mid, int right) {
        auto lp = left;
        auto rp = mid + 1;
        auto tmp = vector<int>();

        while (lp <= mid && rp <= right) {
            if (ans[lp] < ans[rp]) {
                tmp.push_back(ans[lp]);
                lp += 1;
            } else {
                tmp.push_back(ans[rp]);
                rp += 1;
            }
        }

        while (lp <= mid) {
            tmp.push_back(ans[lp]);
            lp += 1;
        }
        while (rp <= right) {
            tmp.push_back(ans[rp]);
            rp += 1;
        }
        // fmt::print("merge => {}-{}-{} tmp: {}, ans: {}\n", left, mid, right,
        // tmp, ans);

        for (auto i = left; i <= right; i++) {
            ans[i] = tmp[i - left];
        }
    };

    function<void(int, int)> helper = [&](int left, int right) {
        if (left >= right) {
            return;
        }

        auto mid = left + (right - left) / 2;
        // fmt::print("divide => (left, mid, right) = ({}, {}, {})\n", left,
        // mid, right);

        helper(left, mid);
        helper(mid + 1, right);
        merge(left, mid, right);
    };

    helper(0, ans.size() - 1);

    return ans;
}
} // namespace sort

namespace tests {
class SortTest : public testing::Test {
protected:
    vector<int> input1, input2, input3;
    vector<int> expected1, expected2, expected3;

    SortTest() {
        // cout << "[NOTE] invoking constructor" << endl;

        this->input1 = vector{1, 2, 3, 4};
        this->expected1 = vector{1, 2, 3, 4};

        this->input2 = vector{5, 4, 3, 2, 1};
        this->expected2 = vector{1, 2, 3, 4, 5};

        this->input3 = vector{6, 2, 3, 1, 5, 4};
        this->expected3 = vector{1, 2, 3, 4, 5, 6};
    }

    ~SortTest() {
        // cout << "[NOTE] invoking destructor" << endl;
    }

    void SetUp() override {
        // cout << "[NOTE] invoke setup method" << endl;
    }

    void TearDown() override {
        // cout << "[NOTE] invoke teardown method" << endl;
    }
};

TEST_F(SortTest, test_bubble_sort) {
    vector<int> real;

    real = sort::bubble_sort(this->input1);
    ASSERT_EQ(real, this->expected1);

    real = sort::bubble_sort(this->input2);
    ASSERT_EQ(real, this->expected2);

    real = sort::bubble_sort(this->input3);
    ASSERT_EQ(real, this->expected3);

    this->expected3.push_back(5);
}

TEST_F(SortTest, test_select_sort) {
    vector<int> real;

    real = sort::select_sort(this->input1);
    EXPECT_EQ(real, this->expected1);

    real = sort::select_sort(this->input2);
    ASSERT_EQ(real, this->expected2);

    real = sort::select_sort(this->input3);
    ASSERT_EQ(real, this->expected3);
}

TEST_F(SortTest, test_insert_sort) {
    vector<int> real;

    real = sort::insert_sort(this->input1);
    EXPECT_EQ(real, this->expected1);

    real = sort::insert_sort(this->input2);
    ASSERT_EQ(real, this->expected2);

    real = sort::insert_sort(this->input3);
    ASSERT_EQ(real, this->expected3);
}

TEST_F(SortTest, test_shell_sort) {
    vector<int> real;

    // real = shell_sort(this->input1);
    // EXPECT_EQ(real, this->expected1);

    real = sort::shell_sort(this->input2);
    ASSERT_EQ(real, this->expected2);

    real = sort::shell_sort(this->input3);
    ASSERT_EQ(real, this->expected3);
}

TEST_F(SortTest, test_quick_sort) {
    vector<int> real;

    real = sort::quick_sort(this->input1);
    EXPECT_EQ(real, this->expected1);

    real = sort::quick_sort(this->input2);
    ASSERT_EQ(real, this->expected2);

    real = sort::quick_sort(this->input3);
    ASSERT_EQ(real, this->expected3);
}

TEST_F(SortTest, test_merge_sort) {
    vector<int> real;

    real = sort::merge_sort(this->input1);
    EXPECT_EQ(real, this->expected1);

    real = sort::merge_sort(this->input2);
    ASSERT_EQ(real, this->expected2);

    real = sort::merge_sort(this->input3);
    ASSERT_EQ(real, this->expected3);
}
} // namespace tests
