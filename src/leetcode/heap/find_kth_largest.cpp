#include <fmt/core.h>
#include <functional>
#include <gtest/gtest.h>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto pq = priority_queue<int, vector<int>, greater<int>>();
        for (auto elem : nums) {
            pq.push(elem);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

namespace tests {
class SolutionTest : public testing::Test {
protected:
    Solution solu;

    SolutionTest() { this->solu = Solution(); }

    void SetUp() override { testing::internal::CaptureStdout(); }

    void TearDown() override {
        this->stdout = testing::internal::GetCapturedStdout();
        fmt::println("[STDOUT]");
        fmt::println("{}", this->stdout);
        fmt::println("[STDOUT]");
    }

    std::string stdout;
};

TEST_F(SolutionTest, test_case_1) {
    auto nums = vector{3, 2, 1, 5, 6, 4};
    auto k = 2;
    auto res = this->solu.findKthLargest(nums, k);
    ASSERT_EQ(res, 5);
}

TEST_F(SolutionTest, test_case_2) {
    auto nums = vector{3, 2, 3, 1, 2, 4, 5, 5, 6};
    auto k = 4;
    auto res = this->solu.findKthLargest(nums, k);
    ASSERT_EQ(res, 4);
}
} // namespace tests
