#include "lru_cache.h"

#include <utility>

#include "gtest/gtest.h"

namespace structure {

LRUCache::LRUCache(int capacity) {
    cap_ = capacity;
}

int LRUCache::get(int key) {
    if (key_to_node_.find(key) == key_to_node_.end()) {
        return -1;
    }

    const auto it = key_to_node_.find(key)->second;
    const auto value = it->second;

    nodes_.erase(it);
    nodes_.emplace_front(key, value);

    key_to_node_[key] = nodes_.begin();

    return value;
}

void LRUCache::put(int key, int value) {
    if (key_to_node_.find(key) != key_to_node_.end()) {
        nodes_.erase(key_to_node_.find(key)->second);
    }

    if (nodes_.size() >= cap_) {
        auto [del_key, _] = nodes_.back();
        nodes_.pop_back();
        key_to_node_.erase(del_key);
    }

    nodes_.emplace_front(key, value);

    key_to_node_[key] = nodes_.begin();
}

namespace tests {

TEST(LRUCacheTest, test_case_0) {
    auto cache = LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

}  // namespace tests
}  // namespace structure
