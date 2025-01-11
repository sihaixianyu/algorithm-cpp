#include <utility>
#include <vector>

#include <gtest/gtest.h>

namespace leetcode {
namespace array {
namespace spiral_matrix {
using std::swap;
using std::vector;

class Solution {
public:
    /// @Prob: First Missing Positive
    /// @Link: https://leetcode.cn/problems/first-missing-positive/?envType=study-plan-v2&envId=top-100-liked
    /// @Tags: ["array", "sorting"]
    int firstMissingPositive(vector<int>& nums) {
        for (auto i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1]) {
                auto idx = nums[i];
                swap(nums[i], nums[idx - 1]);
            }
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto nums = vector{1, 2, 0};
    auto ans = 3;

    auto res = Solution().firstMissingPositive(nums);
    ASSERT_EQ(res, ans);
}

TEST(SolutionTest, test_case_1) {
    auto nums = vector{3, 4, -1, 1};
    auto ans = 2;

    auto res = Solution().firstMissingPositive(nums);
    ASSERT_EQ(res, ans);
}

TEST(SolutionTest, test_case_2) {
    auto nums = vector{7, 8, 9, 11, 12};
    auto ans = 1;

    auto res = Solution().firstMissingPositive(nums);
    ASSERT_EQ(res, ans);
}

TEST(SolutionTest, test_case_3) {
    auto nums = vector{2};
    auto ans = 1;

    auto res = Solution().firstMissingPositive(nums);
    ASSERT_EQ(res, ans);
}

TEST(SolutionTest, test_case_4) {
    auto nums = vector{1};
    auto ans = 2;

    auto res = Solution().firstMissingPositive(nums);
    ASSERT_EQ(res, ans);
}
}  // namespace tests
}  // namespace spiral_matrix
}  // namespace array
}  // namespace leetcode
