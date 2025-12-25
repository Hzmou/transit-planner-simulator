
#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>

namespace transit {

// Trie for stop name autocomplete.
class Trie {
public:
    Trie() = default;

    void insert(const std::string& word, std::uint32_t stop_id);
    bool contains(const std::string& word) const;

    // Return up to max_results stop IDs with names starting with prefix.
    std::vector<std::uint32_t> suggestions(const std::string& prefix, std::size_t max_results = 10) const;

private:
    struct Node {
        bool terminal {false};
        std::vector<std::uint32_t> ids; // stop IDs that correspond to this exact word
        std::unordered_map<char, std::unique_ptr<Node>> next;
    };

    std::unique_ptr<Node> root_ = std::make_unique<Node>();
};

} // namespace transit
