#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    this->ans += 1;
                    sinkIslands(grid, i, j);
                }
            }
        }
        return this->ans;
    }

    void sinkIslands(vector<vector<char>> &grid, int x, int y) {
        if (x < 0 || x >= grid.size()) {
            return;
        }
        if (y < 0 || y >= grid[0].size()) {
            return;
        }
        if (grid[x][y] == '0') {
            return;
        }
        grid[x][y] = '0';
        this->sinkIslands(grid, x - 1, y);
        this->sinkIslands(grid, x + 1, y);
        this->sinkIslands(grid, x, y - 1);
        this->sinkIslands(grid, x, y + 1);
    }

  private:
    int ans;
};

namespace tests {
class SolutionTest : public testing::Test {
  protected:
    Solution solu;

    SolutionTest() { this->solu = Solution(); }
};

TEST_F(SolutionTest, test_case1) {
    auto grid = vector{
        vector{'1', '1', '1', '1', '0'},
        vector{'1', '1', '0', '1', '0'},
        vector{'1', '1', '0', '0', '0'},
        vector{'0', '0', '0', '0', '0'},
    };
    auto expected = 1;
    auto island_num = this->solu.numIslands(grid);
    ASSERT_EQ(island_num, expected);
}

TEST_F(SolutionTest, test_case2) {
    auto grid = vector{
        vector{'1', '1', '0', '0', '0'},
        vector{'1', '1', '0', '0', '0'},
        vector{'0', '0', '1', '0', '0'},
        vector{'0', '0', '0', '1', '1'},
    };
    auto expected = 3;
    auto island_num = this->solu.numIslands(grid);
    ASSERT_EQ(island_num, expected);
}
} // namespace tests
