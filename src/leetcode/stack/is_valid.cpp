#include "gtest/gtest.h"
#include <fmt/core.h>
#include <gtest/gtest.h>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        auto stk = std::stack<char>();
        for (auto chr : s) {
            // fmt::println("{}", chr);
            if (!stk.empty() && this->match(stk.top(), chr)) {
                stk.pop();
                continue;
            }
            stk.push(chr);
        }
        return stk.size() == 0;
    }

    bool match(char c1, char c2) {
        if (c1 == '(') {
            return c2 == ')';
        }
        if (c1 == '[') {
            return c2 == ']';
        }
        if (c1 == '{') {
            return c2 == '}';
        }

        return false;
    }
};

namespace tests {
class SolutionTest : public testing::Test {
protected:
    Solution solu;

    SolutionTest() { this->solu = Solution(); }

    void SetUp() override {
        testing::internal::CaptureStdout();
    }

    void TearDown() override {
        this->stdout = testing::internal::GetCapturedStdout();
        fmt::println("[STDOUT]");
        fmt::println("{}", this->stdout);
        fmt::println("[STDOUT]");
    }

    std::string stdout;
};

TEST_F(SolutionTest, test_case_1) {
    auto s = "()";
    auto res = this->solu.isValid(s);
    ASSERT_TRUE(res);
}

TEST_F(SolutionTest, test_case_2) {
    auto s = "()[]{}";
    auto res = this->solu.isValid(s);
    ASSERT_TRUE(res);
}

TEST_F(SolutionTest, test_case_3) {
    auto s = "(]";
    auto res = this->solu.isValid(s);
    ASSERT_FALSE(res);
}
} // namespace tests
