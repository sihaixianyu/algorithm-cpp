#include <array>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"

namespace trie {
using std::array;
using std::make_shared;
using std::shared_ptr;
using std::string;

class TrieNode {
public:
    static constexpr auto CHARSET_SIZE = 26;

    bool get_is_end() const;
    void set_is_end(bool is_end);

    shared_ptr<TrieNode> get_child(char ch) const;
    void add_child(char ch);

private:
    bool is_end_ = false;
    array<shared_ptr<TrieNode>, CHARSET_SIZE> children_ = {};
};

bool TrieNode::get_is_end() const {
    return is_end_;
}

void TrieNode::set_is_end(bool is_end) {
    is_end_ = is_end;
}

void TrieNode::add_child(char ch) {
    ch = ch - 'a';
    if (children_.at(ch) == nullptr) {
        children_.at(ch) = make_shared<TrieNode>();
    }
}

shared_ptr<TrieNode> TrieNode::get_child(char ch) const {
    ch = ch - 'a';
    return children_.at(ch);
}

class Trie {
public:
    Trie() : root_(make_shared<TrieNode>()) {}

    void insert(string word) {
        if (std::size(word) == 0) {
            throw std::invalid_argument("arg `word` is invald.");
        }

        auto curr = root_;
        for (auto ch : word) {
            if (curr->get_child(ch) == nullptr) {
                curr->add_child(ch);
            }
            curr = curr->get_child(ch);
        }
        curr->set_is_end(true);
    }

    bool search(string word) {
        if (std::size(word) == 0) {
            throw std::invalid_argument("arg `word` is invald.");
        }

        auto curr = root_;
        for (auto ch : word) {
            if (curr->get_child(ch) == nullptr) {
                return false;
            }
            curr = curr->get_child(ch);
        }

        return curr->get_is_end();
    }

    bool startsWith(string prefix) {
        if (std::size(prefix) == 0) {
            throw std::invalid_argument("arg `prefix` is invald.");
        }

        auto curr = root_;
        for (auto ch : prefix) {
            auto child = curr->get_child(ch);
            if (child == nullptr) {
                return false;
            }
            curr = child;
        }

        return true;
    }

private:
    shared_ptr<TrieNode> root_ = nullptr;
};

namespace trie_tests {
TEST(TrieTest, test_case_0) {
    auto trie = Trie();
    trie.insert("apple");

    ASSERT_TRUE(trie.search("apple"));
    ASSERT_FALSE(trie.search("app"));

    ASSERT_TRUE(trie.startsWith("app"));

    trie.insert("app");
    ASSERT_TRUE(trie.search("app"));
}
} // namespace trie_tests
} // namespace trie
