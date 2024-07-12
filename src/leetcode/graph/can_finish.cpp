#include <functional>
#include <unordered_set>
#include <vector>

#include <fmt/core.h>
#include <gtest/gtest.h>

namespace can_finish {
using std::unordered_set;
using std::vector;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto has_cycle = false;
        auto graph = vector<vector<int>>(numCourses);
        auto path = unordered_set<int>();
        auto visited = unordered_set<int>();

        for (auto pair : prerequisites) {
            auto des = pair[0];
            auto src = pair[1];
            graph[src].push_back(des);
        }

        std::function<void(int)> dfs = [&](int src) {
            if (has_cycle) {
                return;
            }

            if (path.find(src) != path.end()) {
                has_cycle = true;
                return;
            }
            if (visited.find(src) != visited.end()) {
                return;
            }

            path.insert(src);
            visited.insert(src);

            for (auto des : graph[src]) {
                dfs(des);
            }

            path.erase(src);
        };

        for (auto i = 0; i < numCourses; i++) {
            dfs(i);
        }

        return !has_cycle;
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
    auto num_courses = 2;
    auto prerequisites = vector<vector<int>>{
        {1, 0},
    };

    auto res = this->solution.canFinish(num_courses, prerequisites);
    ASSERT_TRUE(res);
}

TEST_F(SolutionTest, test_case_1) {
    auto num_courses = 2;
    auto prerequisites = vector<vector<int>>{
        {1, 0},
        {0, 1},
    };

    auto res = this->solution.canFinish(num_courses, prerequisites);
    ASSERT_FALSE(res);
}
} // namespace tests
} // namespace can_finish
