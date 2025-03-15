#include <vector>

#include <fmt/base.h>
#include <gtest/gtest.h>

namespace leetcode {
namespace array {
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto m = matrix.size() - 1;
        auto n = matrix[0].size() - 1;

        auto i = 0;
        auto j = static_cast<int>(n);
        while (i <= m && j >= 0) {
            auto cur_num = matrix[i][j];
            if (target == cur_num) {
                return true;
            } else if (target > cur_num) {
                i += 1;
            } else if (target < cur_num) {
                j -= 1;
            }
        }

        return false;
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto mat = vector<vector<int>>{
        {1,  4,  7,  11, 15},
        {2,  5,  8,  12, 19},
        {3,  6,  9,  16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
    auto target = 5;

    auto res = Solution().searchMatrix(mat, target);
    auto ans = true;

    ASSERT_EQ(res, ans);
}

TEST(SolutionTest, test_case_1) {
    auto mat = vector<vector<int>>{{-5}};
    auto target = -10;

    auto res = Solution().searchMatrix(mat, target);
    auto ans = false;

    ASSERT_EQ(res, ans);
}
}  // namespace tests
}  // namespace array
}  // namespace leetcode
