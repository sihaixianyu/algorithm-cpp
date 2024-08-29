#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

namespace merge_intervals {
using std::vector;

/// @Prob: Merge Intervals
/// @Link: https://leetcode.cn/problems/merge-intervals/?envType=study-plan-v2&envId=top-100-liked
/// @Tags: ["array", "sorting"]
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto ans = vector<vector<int>>();

        auto cmp = [](const vector<int>& v1, const vector<int>& v2) -> bool { return v1.front() < v2.front(); };
        std::sort(intervals.begin(), intervals.end(), cmp);

        for (auto interval : intervals) {
            if (!ans.empty() && interval[0] <= ans.back()[1]) {
                ans.back()[1] = std::max(ans.back()[1], interval[1]);
                continue;
            }
            ans.push_back(interval);
        }

        return ans;
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto intervals = vector<vector<int>> {
        {1,  3 },
        {2,  6 },
        {8,  10},
        {15, 18}
    };
    auto ans = Solution().merge(intervals);
    auto exp = vector<vector<int>> {
        {1,  6 },
        {8,  10},
        {15, 18},
    };
    ASSERT_EQ(ans, exp);
}
TEST(SolutionTest, test_case_1) {
    auto intervals = vector<vector<int>> {
        {1, 4},
        {4, 5},
    };
    auto ans = Solution().merge(intervals);
    auto exp = vector<vector<int>> {
        {1, 5},
    };
    ASSERT_EQ(ans, exp);
}
}  // namespace tests
}  // namespace merge_intervals
