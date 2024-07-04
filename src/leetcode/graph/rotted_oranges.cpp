#include <algorithm>
#include <array>
#include <deque>
#include <tuple>
#include <vector>

#include <gtest/gtest.h>

namespace rotted_oranges {
using std::array;
using std::deque;
using std::tuple;
using std::vector;

class Solution {
private:
    static constexpr array<tuple<int, int>, 4> DIRECTIONS = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        auto num_rows = grid.size();
        auto num_cols = grid[0].size();
        auto locs = deque<tuple<int, int, int>>();

        for (auto r = 0; r < num_rows; r++) {
            for (auto c = 0; c < num_cols; c++) {
                if (grid[r][c] == 2) {
                    locs.push_back(tuple(r, c, 0));
                }
            }
        }

        auto elapsed_minutes = 0;
        while (!locs.empty()) {
            auto [r, c, d] = locs.front();
            locs.pop_front();
            elapsed_minutes = std::max(elapsed_minutes, d);
            for (auto [move_r, move_c] : Solution::DIRECTIONS) {
                auto next_r = r + move_r;
                auto next_c = c + move_c;
                if (next_r < 0 || next_c < 0 || next_r >= num_rows || next_c >= num_cols) {
                    continue;
                }
                if (grid[next_r][next_c] == 1) {
                    grid[next_r][next_c] = 2;
                    locs.push_back(tuple(next_r, next_c, d + 1));
                }
            }
        }

        for (auto row_status : grid) {
            for (auto status : row_status) {
                if (status == 1) {
                    return -1;
                }
            }
        }

        return elapsed_minutes;
    };
};

namespace tests {
class SolutionTest : public testing::Test {
protected:
    Solution solution;

    SolutionTest() {
        this->solution = Solution();
    }
};

TEST_F(SolutionTest, test_case_0) {
    auto grid = vector<vector<int>>{
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1},
    };
    auto ans = this->solution.orangesRotting(grid);
    ASSERT_EQ(ans, 4);
}

TEST_F(SolutionTest, test_case_1) {
    auto grid = vector<vector<int>>{
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1},
    };
    auto ans = this->solution.orangesRotting(grid);
    ASSERT_EQ(ans, -1);
}

TEST_F(SolutionTest, test_case_2) {
    auto grid = vector<vector<int>>{{0, 2}};
    auto ans = this->solution.orangesRotting(grid);
    ASSERT_EQ(ans, 0);
}

TEST_F(SolutionTest, test_case_3) {
    auto grid = vector<vector<int>>{
        {2, 1, 1},
        {1, 1, 1},
        {0, 1, 2},
    };
    auto ans = this->solution.orangesRotting(grid);
    ASSERT_EQ(ans, 2);
}
} // namespace tests
} // namespace rotted_oranges
