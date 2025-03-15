#include <array>
#include <vector>

#include <gtest/gtest.h>

namespace num_enclaves {
using std::array;
using std::vector;

class Solution {
private:
    static constexpr array<array<int, 2>, 4> DIRECTIONS = {{
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    }};

    int count_ = 0;

    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        count_ += 1;
        for (const auto& d : DIRECTIONS) {
            auto next_x = x + d[0];
            auto next_y = y + d[1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
                continue;
            }
            if (grid[next_x][next_y] == 0) {
                continue;
            }
            dfs(grid, next_x, next_y);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();

        for (auto i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                this->dfs(grid, i, 0);
            }
            if (grid[i][n - 1] == 1) {
                this->dfs(grid, i, n - 1);
            }
        }
        for (auto j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                this->dfs(grid, 0, j);
            }
            if (grid[m - 1][j] == 1) {
                this->dfs(grid, m - 1, j);
            }
        }

        count_ = 0;
        for (auto i = 1; i < m; i++) {
            for (auto j = 1; j < n; j++) {
                if (grid[i][j] == 1) {
                    this->dfs(grid, i, j);
                }
            }
        }

        return count_;
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

TEST_F(SolutionTest, test_case_0) {
    auto grid = vector{
        vector{0, 0, 0, 0},
        vector{1, 0, 1, 0},
        vector{0, 1, 1, 0},
        vector{0, 0, 0, 0},
    };
    auto count = this->solution.numEnclaves(grid);
    ASSERT_EQ(count, 3);
}

TEST_F(SolutionTest, test_case_1) {
    auto grid = vector{
        vector{0, 1, 1, 0},
        vector{0, 0, 1, 0},
        vector{0, 0, 1, 0},
        vector{0, 0, 0, 0},
    };
    auto count = this->solution.numEnclaves(grid);
    ASSERT_EQ(count, 0);
}

TEST_F(SolutionTest, test_case_2) {
    auto grid = vector{
        vector{0}, vector{1}, vector{1}, vector{0}, vector{0},
    };
    auto count = this->solution.numEnclaves(grid);
    ASSERT_EQ(count, 0);
}
} // namespace tests
} // namespace num_enclaves
