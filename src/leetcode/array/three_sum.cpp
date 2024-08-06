#include <vector>

#include "gtest/gtest.h"

namespace three_sum {
using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto n = nums.size();
        auto res = vector<vector<int>>();

        std::sort(nums.begin(), nums.end());

        for (auto k = 0; k < n - 2; k++) {
            if (nums[k] > 0) {
                continue;
            }
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }

            auto i = k + 1;
            auto j = n - 1;

            while (i < j) {
                if (nums[k] + nums[i] + nums[j] < 0) {
                    i += 1;
                    continue;
                }
                if (nums[k] + nums[i] + nums[j] > 0) {
                    j -= 1;
                    continue;
                }

                res.push_back(vector<int> {nums[k], nums[i], nums[j]});

                while (i < j && nums[i + 1] == nums[i]) {
                    i += 1;
                }
                while (i < j && nums[j - 1] == nums[j]) {
                    j -= 1;
                }
                i += 1;
                j -= 1;
            }
        }

        return res;
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto nums = vector<int> {-1, 0, 1, 2, -1, -4};
    auto res = Solution().threeSum(nums);

    auto expected = vector<vector<int>> {{-1, -1, 2}, {-1, 0, 1}};
    ASSERT_EQ(res, expected);
}

TEST(SolutionTest, test_case_1) {
    auto nums = vector<int> {0, 1, 1};
    auto res = Solution().threeSum(nums);

    auto expected = vector<vector<int>> {};
    ASSERT_EQ(res, expected);
}

TEST(SolutionTest, test_case_2) {
    auto nums = vector<int> {0, 0, 0};
    auto res = Solution().threeSum(nums);

    auto expected = vector<vector<int>> {{0, 0, 0}};
    ASSERT_EQ(res, expected);
}

TEST(SolutionTest, test_case_3) {
    auto nums = vector<int> {-2, 0, 0, 2, 2};
    auto res = Solution().threeSum(nums);

    auto expected = vector<vector<int>> {{-2, 0, 2}};
    ASSERT_EQ(res, expected);
}
} // namespace tests
} // namespace three_sum
