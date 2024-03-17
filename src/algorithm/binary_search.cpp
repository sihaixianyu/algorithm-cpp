#include <optional>
#include <vector>

#include <fmt/core.h>
#include <gtest/gtest.h>

namespace binary_search {
using std::nullopt;
using std::optional;
using std::vector;

optional<int> search(vector<int>& nums, int target) {
    auto left = 0;
    auto right = nums.size();

    while (left < right) {
        auto mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            right = mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        }
    }

    return std::nullopt;
}

optional<int> left_bound(vector<int>& nums, int target) {
    auto left = 0;
    auto right = nums.size();

    while (left < right) {
        auto mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (target < nums[mid]) {
            right = mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        }
    }

    if (nums[left] == target) {
        return left;
    }

    return nullopt;
}

optional<int> right_bound(vector<int>& nums, int target) {
    return nullopt;
}

namespace tests {
class BinarySearchTest : public testing::Test {};

TEST_F(BinarySearchTest, test_ok) {
    auto nums = vector<int>{1, 2, 3, 4, 5};
    auto loc = binary_search::search(nums, 4);
    ASSERT_EQ(loc, 3);
}

TEST_F(BinarySearchTest, test_ok_no_tgt_num) {
    auto nums = vector<int>{1, 2, 3, 4, 5};
    auto loc = binary_search::search(nums, 0);
    ASSERT_EQ(loc, nullopt);
}

class LeftBoundTest : public testing::Test {};

TEST_F(LeftBoundTest, test_ok) {
    auto nums = vector<int>{1, 3, 3, 3, 5};
    auto loc = binary_search::left_bound(nums, 3);
    ASSERT_EQ(loc, 1);
}

TEST_F(LeftBoundTest, test_ok_no_tgt_num) {
    auto nums = vector<int>{1, 2, 3, 4, 5};
    auto loc = binary_search::left_bound(nums, 0);
    ASSERT_EQ(loc, nullopt);
}
} // namespace tests

} // namespace binary_search
