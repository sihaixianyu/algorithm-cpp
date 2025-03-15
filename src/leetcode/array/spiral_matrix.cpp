#include <array>
#include <vector>

#include <gtest/gtest.h>

namespace leetcode {
namespace array {
using std::array;
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto btm = 0;
        auto top = static_cast<int>(matrix.size() - 1);
        auto left = 0;
        auto right = static_cast<int>(matrix[0].size() - 1);

        auto total_elems = (top + 1) * (right + 1);
        auto res = vector<int>(total_elems);

        auto i = 0;
        auto j = 0;
        auto cnt = 0;
        auto idx = 0;

        while (cnt < total_elems) {
            res[cnt] = matrix[i][j];
            cnt += 1;

            auto next_i = i + directions[idx][0];
            auto next_j = j + directions[idx][1];

            if (next_i < btm) {
                left += 1;
                idx = 0;
            } else if (next_i > top) {
                right -= 1;
                idx = 2;
            } else if (next_j < left) {
                top -= 1;
                idx = 3;
            } else if (next_j > right) {
                btm += 1;
                idx = 1;
            }

            i = i + directions[idx][0];
            j = j + directions[idx][1];
        }

        return res;
    }

private:
    static constexpr array<array<int, 2>, 4> directions{
        {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    };
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto mat = vector<vector<int>>{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto ans = vector<int>{1, 2, 3, 6, 9, 8, 7, 4, 5};

    auto res = Solution().spiralOrder(mat);
    ASSERT_EQ(res, ans);
}

TEST(SolutionTest, test_case_1) {
    auto mat = vector<vector<int>>{
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    auto ans = vector<int>{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

    auto res = Solution().spiralOrder(mat);
    ASSERT_EQ(res, ans);
}
}  // namespace tests
}  // namespace array
}  // namespace leetcode
