#include <unordered_set>
#include <vector>

#include <fmt/core.h>
#include <gtest/gtest.h>

namespace find_kth_largest {
using std::unordered_set;
using std::vector;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        auto max_len = 0;

        const auto unique_nums = unordered_set<int>(nums.begin(), nums.end());
        for (const auto start : unique_nums) {
            if (unique_nums.count(start - 1) > 0) {
                continue;
            }
            auto end = start + 1;
            while (unique_nums.count(end) > 0) {
                end += 1;
            }

            max_len = std::max(max_len, end - start);
        }

        return max_len;
    }
};

namespace tests {
TEST(SolutionTest, test_case_1) {
    auto solution = Solution();
    auto nums = vector<int>{100, 4, 200, 1, 3, 2};

    auto ans = solution.longestConsecutive(nums);
    EXPECT_EQ(ans, 4);
}

TEST(SolutionTest, test_case_2) {
    auto solution = Solution();
    auto nums = vector<int>{1, 0, 1, 2};

    auto ans = solution.longestConsecutive(nums);
    EXPECT_EQ(ans, 3);
}
}  // namespace tests
}  // namespace find_kth_largest
