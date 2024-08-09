#include <algorithm>
#include <optional>
#include <vector>

#include "gtest/gtest.h"

namespace trap {
using std::optional;
using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
        auto area = 0;
        const auto n = height.size();

        auto l_tops = vector<int>(n);
        auto r_tops = vector<int>(n);

        l_tops[0] = height[0];
        r_tops[n - 1] = height[n - 1];

        for (auto i = 1; i < n - 1; i++) {
            l_tops[i] = std::max(height[i], l_tops[i - 1]);
            r_tops[n - i - 1] = std::max(height[n - i - 1], r_tops[n - i]);
        }

        for (auto i = 1; i < n - 1; i++) {
            area += std::min(l_tops[i], r_tops[i]) - height[i];
        }

        return area;
    }
};

namespace tests {
class SolutionTest : public testing::Test {
public:
    optional<Solution> solution_ = std::nullopt;

protected:
    void SetUp() override {
        solution_ = Solution();
    }
};

TEST_F(SolutionTest, test_case_0) {
    auto height = vector {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    auto exp = 6;
    auto res = solution_.value().trap(height);
    ASSERT_EQ(res, exp);
}

TEST_F(SolutionTest, test_case_1) {
    auto height = vector {4, 2, 0, 3, 2, 5};
    auto exp = 9;
    auto res = solution_.value().trap(height);
    ASSERT_EQ(res, exp);
}
}  // namespace tests
}  // namespace trap
