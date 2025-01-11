#include <vector>

#include "gtest/gtest.h"

namespace leetcode {
namespace array {
namespace spiral_matrix {
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto n = static_cast<int>(nums.size());

        auto pre = vector<int>(n);
        std::fill(pre.begin(), pre.end(), 1);
        for (auto i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        auto suf = vector<int>(n);
        std::fill(suf.begin(), suf.end(), 1);
        for (auto i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] * nums[i + 1];
        }

        auto ans = vector<int>(n);
        std::fill(ans.begin(), ans.end(), 1);
        for (auto i = 0; i < n; i++) {
            ans[i] = pre[i] * suf[i];
        }

        return ans;
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto nums = vector{1, 2, 3, 4};
    auto ans = Solution().productExceptSelf(nums);
    auto exp = vector{24, 12, 8, 6};
    ASSERT_EQ(ans, exp);
}

TEST(SolutionTest, test_case_1) {
    auto nums = vector{-1, 1, 0, -3, 3};
    auto ans = Solution().productExceptSelf(nums);
    auto exp = vector{0, 0, 9, 0, 0};
    ASSERT_EQ(ans, exp);
}
}  // namespace tests
}  // namespace spiral_matrix
}  // namespace array
}  // namespace leetcode
