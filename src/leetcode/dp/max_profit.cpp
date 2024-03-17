#include <gtest/gtest.h>
#include <vector>

namespace max_profit {
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return 0;
    }
};

namespace tests {
class SolutionTest : public testing::Test {
protected:
    Solution solution;

    SolutionTest() {
        this->solution = Solution();
    }
};

TEST_F(SolutionTest, test_case1) {
    auto prices = vector{7, 1, 5, 3, 6, 4};
    auto res = this->solution.maxProfit(prices);
    ASSERT_EQ(res, 5);
}

TEST_F(SolutionTest, test_case2) {
    auto prices = vector{7, 6, 4, 3, 1};
    auto res = this->solution.maxProfit(prices);
    ASSERT_EQ(res, 0);
}
} // namespace tests
} // namespace max_profit
