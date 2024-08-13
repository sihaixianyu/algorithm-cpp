#include <fmt/core.h>

#include <string>
#include <vector>

#include "gtest/gtest.h"

namespace find_anagrams {
using std::array;
using std::string;
using std::vector;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        auto res = vector<int>();
        auto s_cnt = array<int, 26>();
        auto p_cnt = array<int, 26>();

        auto chr_to_seq = [](char chr) -> int { return chr - 'a'; };

        for (auto c : p) {
            p_cnt[chr_to_seq(c)] += 1;
        }

        auto left = 0;
        auto right = 0;

        while (right < s.size()) {
            auto chr = s[right];
            right += 1;

            auto seq = chr_to_seq(chr);
            s_cnt[seq] += 1;

            while (s_cnt[seq] > p_cnt[seq]) {
                auto seq = chr_to_seq(s[left]);
                s_cnt[seq] -= 1;
                left += 1;
            }

            if (right - left == p.size()) {
                res.push_back(left);
            }
        }

        return res;
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto s = string("cbaebabacd");
    auto p = string("abc");
    auto res = Solution().findAnagrams(s, p);
    auto exp = vector {0, 6};
    ASSERT_EQ(res, exp);
}

TEST(SolutionTest, test_case_1) {
    auto s = string("abab");
    auto p = string("ab");
    auto res = Solution().findAnagrams(s, p);
    auto exp = vector {0, 1, 2};
    ASSERT_EQ(res, exp);
}
}  // namespace tests
}  // namespace find_anagrams
