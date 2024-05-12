#include <deque>
#include <functional>
#include <tuple>
#include <unordered_set>
#include <vector>

#include <fmt/core.h>
#include <gtest/gtest.h>

namespace surrounded_regions {
using std::deque;
using std::function;
using std::tuple;
using std::unordered_set;
using std::vector;

struct loc_hasher {
    inline std::size_t operator()(const tuple<int, int>& t) const {
        auto [x, y] = t;
        return x ^ y;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        auto dircetions = vector{
            tuple{-1, 0},
            tuple{1, 0},
            tuple{0, -1},
            tuple{0, 1},
        };

        auto m = board.size();
        auto n = board[0].size();

        function<void(int, int)> bfs = [&](int x, int y) {
            auto level_locs = deque{tuple{x, y}};
            auto sinkable_locs = unordered_set<tuple<int, int>, loc_hasher>();
            sinkable_locs.insert(tuple{x, y});

            while (level_locs.size() > 0) {
                auto [cur_x, cur_y] = level_locs.front();
                level_locs.pop_front();
                for (auto [mov_x, mov_y] : dircetions) {
                    auto next_x = cur_x + mov_x;
                    auto next_y = cur_y + mov_y;
                    auto next_loc = tuple{next_x, next_y};
                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) {
                        return;
                    }
                    if (auto it = sinkable_locs.find(next_loc); it != sinkable_locs.end()) {
                        continue;
                    }
                    if (board[next_x][next_y] == 'X') {
                        continue;
                    }
                    level_locs.push_back(next_loc);
                    sinkable_locs.insert(next_loc);
                }
            }

            for (auto [x, y] : sinkable_locs) {
                board[x][y] = 'X';
            }
        };

        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    continue;
                }
                bfs(i, j);
            }
        }
    }
};

namespace tests {
class SolutionTest : public testing::Test {
protected:
    Solution solution_;

    SolutionTest() {
        solution_ = Solution();
    }
};

TEST_F(SolutionTest, test_case_0) {
    auto board = vector<vector<char>>{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    auto expected = vector<vector<char>>{
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
    };

    solution_.solve(board);
    ASSERT_EQ(board, expected);
}

TEST_F(SolutionTest, test_case_1) {
    auto board = vector<vector<char>>{{'X'}};
    auto expected = vector<vector<char>>{{'X'}};

    solution_.solve(board);
    ASSERT_EQ(board, expected);
}
} // namespace tests
} // namespace surrounded_regions
