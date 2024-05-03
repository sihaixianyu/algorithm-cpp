#include <vector>

#include <gtest/gtest.h>

namespace all_paths_source_target {
using std::vector;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        auto cur_path = vector<int>();
        auto all_paths = vector<vector<int>>();

        dfs(0, cur_path, all_paths, graph);

        return all_paths;
    }

private:
    void dfs(int cur_node, vector<int>& cur_path, vector<vector<int>>& all_paths, const vector<vector<int>>& graph) {
        if (cur_path.size() > graph.size()) {
            return;
        }
        cur_path.push_back(cur_node);

        if (cur_node == graph.size() - 1) {
            all_paths.push_back(vector(cur_path));
            return;
        }

        for (auto next_node : graph.at(cur_node)) {
            dfs(next_node, cur_path, all_paths, graph);
            cur_path.pop_back();
        }
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
    auto graph = vector<vector<int>>{
        {1, 2},
        {3},
        {3},
        {},
    };
    auto ans = Solution().allPathsSourceTarget(graph);
    auto expected_paths = vector<vector<int>>{{0, 1, 3}, {0, 2, 3}};
    ASSERT_EQ(ans, expected_paths);
}

TEST_F(SolutionTest, test_case_1) {
    auto graph = vector<vector<int>>{
        {4, 3, 1}, {3, 2, 4}, {3}, {4}, {},
    };
    auto ans = Solution().allPathsSourceTarget(graph);
    auto expected_paths = vector<vector<int>>{
        {0, 4}, {0, 3, 4}, {0, 1, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 4},
    };
    ASSERT_EQ(ans, expected_paths);
};
} // namespace tests
} // namespace all_paths_source_target
