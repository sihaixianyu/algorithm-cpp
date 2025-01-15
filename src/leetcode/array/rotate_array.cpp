#include <utility>
#include <vector>

#include "gtest/gtest.h"

namespace leetcode {
namespace array {
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto n = nums.size();
        k = k % n;

        this->reverse(nums, 0, n - 1);
        this->reverse(nums, 0, k - 1);
        this->reverse(nums, k, n - 1);
    }

private:
    void reverse(vector<int>& nums, int lb, int rb) {
        auto lp = lb;
        auto rp = rb;
        while (lp < rp) {
            std::swap(nums[lp], nums[rp]);
            lp += 1;
            rp -= 1;
        }
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto nums = vector{1, 2, 3, 4, 5, 6, 7};
    auto k = 3;

    Solution().rotate(nums, k);
    auto exp = vector{5, 6, 7, 1, 2, 3, 4};

    ASSERT_EQ(nums, exp);
}

TEST(SolutionTest, test_case_1) {
    auto nums = vector{-1, -100, 3, 99};
    auto k = 2;

    Solution().rotate(nums, k);
    auto exp = vector{3, 99, -1, -100};

    ASSERT_EQ(nums, exp);
}
}  // namespace tests
}  // namespace array
}  // namespace leetcode
