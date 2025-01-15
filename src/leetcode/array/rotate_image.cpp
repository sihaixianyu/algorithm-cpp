#include <vector>

#include <gtest/gtest.h>

namespace leetcode {
namespace array {
using std::vector;

class Solution {
public:
    /// @Prob: Rotate Image
    /// @Link: https://leetcode.cn/problems/rotate-image/description/?envType=study-plan-v2&envId=top-100-liked
    /// @Tags: ["Array", "Math", "Matrix"]
    void rotate(vector<vector<int>>& matrix) {
        auto n = matrix.size();

        for (size_t i = 0; i < n / 2; i++) {
            for (size_t j = 0; j < (n + 1) / 2; j++) {
                auto temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto mat = vector<vector<int>>{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto exp = vector<vector<int>>{
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3},
    };

    Solution().rotate(mat);
    ASSERT_EQ(mat, exp);
}
TEST(SolutionTest, test_case_1) {
    auto mat = vector<vector<int>>{
        {5,  1,  9,  11},
        {2,  4,  8,  10},
        {13, 3,  6,  7 },
        {15, 14, 12, 16},
    };
    auto exp = vector<vector<int>>{
        {15, 13, 2,  5 },
        {14, 3,  4,  1 },
        {12, 6,  8,  9 },
        {16, 7,  10, 11},
    };

    Solution().rotate(mat);
    ASSERT_EQ(mat, exp);
}
}  // namespace tests
}  // namespace array
}  // namespace leetcode
