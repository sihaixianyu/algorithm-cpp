#include <algorithm>
#include <functional>
#include <vector>

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <gtest/gtest.h>

namespace sort {
using std::function;
using std::swap;
using std::vector;

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

vector<int> shell_sort(const vector<int>& nums) {
    auto ans = vector<int>(nums);

    function<void(int)> helper = [&](int gap) {
        for (auto i = gap; i < ans.size(); i += 1) {
            auto temp = ans[i];

            auto j = i;
            for (; j >= gap && ans[j - gap] > temp; j -= gap) {
                ans[j] = ans[j - gap];
            }
            ans[j] = temp;
        }
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

vector<int> heap_sort(const vector<int>& nums) {
    auto ans = vector<int>(nums);

    function<void(int, int)> heapify = [&](int idx, int len) {
        auto left = 2 * idx + 1;
        auto right = 2 * idx + 2;
        auto largest = idx;

        if (left < len && ans[left] > ans[largest]) {
            largest = left;
        }
        if (right < len && ans[right] > ans[largest]) {
            largest = right;
        }

        if (largest != idx) {
            swap(ans[idx], ans[largest]);
            heapify(largest, len);
        }
    };

    for (auto i = ans.size() / 2 - 1; i >= 0; i--) {
        heapify(i, ans.size());
    }

    for (auto i = ans.size() - 1; i > 0; i--) {
        swap(ans[0], ans[i]);
        heapify(0, i);
    }

    return ans;
}

namespace tests {
class SortTest : public testing::Test {
protected:
    vector<int> input1, input2, input3;
    vector<int> expected1, expected2, expected3;

    void SetUp() override {
        this->input1 = vector{1, 2, 3, 4};
        this->expected1 = vector{1, 2, 3, 4};

        this->input2 = vector{5, 4, 3, 2, 1};
        this->expected2 = vector{1, 2, 3, 4, 5};

        this->input3 = vector{6, 2, 3, 1, 5, 4};
        this->expected3 = vector{1, 2, 3, 4, 5, 6};
    }

    void TearDown() override {
    }
};

TEST_F(SortTest, test_select_sort) {
    vector<int> real;

    real = sort::select_sort(this->input1);
    EXPECT_EQ(real, this->expected1);

    real = sort::select_sort(this->input2);
    ASSERT_EQ(real, this->expected2);

    real = sort::select_sort(this->input3);
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

TEST_F(SortTest, test_heap_sort) {
    vector<int> real;

    real = sort::heap_sort(this->input1);
    EXPECT_EQ(real, this->expected1);

    real = sort::heap_sort(this->input2);
    ASSERT_EQ(real, this->expected2);

    real = sort::heap_sort(this->input3);
    ASSERT_EQ(real, this->expected3);
}
} // namespace tests
} // namespace sort
