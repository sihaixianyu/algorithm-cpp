#pragma once

#include <list>
#include <unordered_map>
#include <utility>

namespace structure {

class LRUCache {
public:
    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);

private:
    int cap_;
    std::list<std::pair<int, int>> nodes_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> key_to_node_;
};

}  // namespace structure
