#include <algorithm>
#include <deque>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

namespace leetcode {
namespace array {
using std::vector;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto que = std::deque<int>();
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (que.empty()) {
                que.push_back(i);
                continue;
            }

            if (nums[i] >= nums[que.back()]) {
                que.push_back(i);
                continue;
            }

            while (nums[que.front()] <= nums[i]) {
                que.pop_front();
            }

            std::swap(nums[i], nums[que.front()]);
            std::sort(nums.begin() + i + 1, nums.end());
            return;
        }
        std::reverse(nums.begin(), nums.end());
    }
};

namespace tests {
TEST(SolutionTest, test_case_1) {
    auto nums = vector<int>{1, 2, 3};
    auto exp = vector<int>{1, 3, 2};

    Solution().nextPermutation(nums);
    EXPECT_EQ(nums, exp);
}

TEST(SolutionTest, test_case_2) {
    auto nums = vector<int>{3, 2, 1};
    auto exp = vector<int>{1, 2, 3};

    Solution().nextPermutation(nums);
    EXPECT_EQ(nums, exp);
}

TEST(SolutionTest, test_case_3) {
    auto nums = vector<int>{1, 3, 2};
    auto exp = vector<int>{2, 1, 3};

    Solution().nextPermutation(nums);
    EXPECT_EQ(nums, exp);
}
}  // namespace tests
}  // namespace array
}  // namespace leetcode
