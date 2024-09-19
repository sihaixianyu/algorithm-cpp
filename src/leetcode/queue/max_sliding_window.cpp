#include <cstddef>
#include <deque>
#include <vector>

#include "gtest/gtest.h"

namespace max_sliding_window {
using std::deque;
using std::vector;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto ans = vector<int>();
        auto que = deque<int>();
        auto n = nums.size();

        for (size_t i = 0; i < n; i++) {
            while (!que.empty() && nums[i] > nums[que.back()]) {
                que.pop_back();
            }
            que.push_back(i);

            while (i >= que.front() + k) {
                que.pop_front();
            }

            if (i >= k - 1) {
                ans.push_back(nums[que.front()]);
            }
        }

        return ans;
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto nums = vector<int> {1, 3, -1, -3, 5, 3, 6, 7};
    auto k = 3;
    auto res = Solution().maxSlidingWindow(nums, k);
    auto exp = vector<int> {3, 3, 5, 5, 6, 7};
    ASSERT_EQ(res, exp);
}
TEST(SolutionTest, test_case_1) {
    auto nums = vector<int> {1};
    auto k = 1;
    auto res = Solution().maxSlidingWindow(nums, k);
    auto exp = vector<int> {1};
    ASSERT_EQ(res, exp);
}
}  // namespace tests
}  // namespace max_sliding_window
