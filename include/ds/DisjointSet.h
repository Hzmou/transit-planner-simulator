
#pragma once
#include <unordered_map>

namespace transit {

// Union-Find (Disjoint Set) with path compression and union by rank.
template <typename T>
class DisjointSet {
public:
    void make_set(const T& x);
    T find(const T& x);
    void unite(const T& a, const T& b);

    bool same_set(const T& a, const T& b);

private:
    struct Node { T parent; int rank {0}; bool initialized {false}; };
    std::unordered_map<T, Node> nodes_;
};

} // namespace transit
