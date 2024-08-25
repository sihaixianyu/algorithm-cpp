#include <string>
#include <unordered_map>

#include "gtest/gtest.h"

namespace min_window {
using std::string;
using std::unordered_map;

class Solution {
public:
    string minWindow(string s, string t) {
        const auto n = s.length();
        auto ans = string("");
        auto req_cnt = 0u;
        auto req_chars = unordered_map<char, int>();

        for (auto c : t) {
            req_cnt += 1;
            if (req_chars.find(c) == req_chars.end()) {
                req_chars[c] = 0;
            }
            req_chars[c] += 1;
        }

        auto left = 0u;
        auto right = 0u;

        while (right < n) {
            const auto add_c = s[right];
            right += 1;

            if (auto it = req_chars.find(add_c); it != req_chars.end()) {
                it->second -= 1;
                if (it->second >= 0) {
                    req_cnt -= 1;
                }

                if (req_cnt != 0) {
                    continue;
                }

                while (req_cnt == 0) {
                    const auto del_char = s[left];
                    left += 1;

                    if (auto it = req_chars.find(del_char); it != req_chars.end()) {
                        if (it->second == 0) {
                            req_cnt += 1;
                        }
                        it->second += 1;
                    }
                }

                auto len = right - left + 1;
                if (ans == string("") || len < ans.length()) {
                    ans = s.substr(left - 1, len);
                }
            }
        }

        return ans;
    }
};

namespace tests {
TEST(SolutionTest, test_case_0) {
    auto s = string("ADOBECODEBANC");
    auto t = string("ABC");
    auto ans = Solution().minWindow(s, t);
    auto exp = string("BANC");
    ASSERT_EQ(ans, exp);
}

TEST(SolutionTest, test_case_1) {
    auto s = string("a");
    auto t = string("a");
    auto ans = Solution().minWindow(s, t);
    auto exp = string("a");
    ASSERT_EQ(ans, exp);
}

TEST(SolutionTest, test_case_2) {
    auto s = string("a");
    auto t = string("aa");
    auto ans = Solution().minWindow(s, t);
    auto exp = string("");
    ASSERT_EQ(ans, exp);
}
}  // namespace tests
}  // namespace min_window
