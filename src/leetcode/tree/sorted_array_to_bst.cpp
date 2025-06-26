#include <vector>

#include "gtest/gtest.h"

#include "binary_tree.h"

namespace leetcode {
namespace tree {
using std::vector;
using structure::BinaryTree;
using structure::TreeNode;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return nullptr;
    }
};

namespace tests {

TEST(SolutionTest, test_case_1) {
    auto nums = vector{-10, -3, 0, 5, 9};
    auto exp = vector{0, -3, 9, -10, 5};

    auto root = Solution().sortedArrayToBST(nums);
    auto res = BinaryTree::level_traverse(root);
    EXPECT_EQ(res, exp);
}

TEST(SolutionTest, test_case_2) {
    auto nums = vector{1, 3};
    auto exp = vector{3, 1};

    auto root = Solution().sortedArrayToBST(nums);
    auto res = BinaryTree::level_traverse(root);
    EXPECT_EQ(res, exp);
}
}  // namespace tests
}  // namespace tree
}  // namespace leetcode
