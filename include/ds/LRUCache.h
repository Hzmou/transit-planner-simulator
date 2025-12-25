
#pragma once
#include <list>
#include <unordered_map>
#include <utility>
#include <cstddef>

namespace transit {

// LRU Cache implemented with a doubly linked list + hash map.
template <typename Key, typename Value>
class LRUCache {
public:
    explicit LRUCache(std::size_t capacity) : capacity_(capacity) {}

    bool get(const Key& key, Value& out_value);
    void put(const Key& key, const Value& value);
    std::size_t size() const noexcept { return map_.size(); }

private:
    std::size_t capacity_ {0};
    using Entry = std::pair<Key, Value>;
    std::list<Entry> list_; // front = most recent
    std::unordered_map<Key, typename std::list<Entry>::iterator> map_;

    void touch(typename std::list<Entry>::iterator it);
};

} // namespace transit.

