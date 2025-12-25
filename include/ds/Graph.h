
#pragma once
#include <unordered_map>
#include <vector>
#include <utility>
#include <optional>
#include <limits>

namespace transit {

// Directed weighted adjacency list graph.
template <typename NodeId = int, typename Weight = double>
class Graph {
public:
    using Edge = std::pair<NodeId, Weight>; // neighbor, weight

    Graph() = default;

    bool add_vertex(const NodeId& v);
    bool remove_vertex(const NodeId& v);

    bool add_edge(const NodeId& u, const NodeId& v, const Weight& w);
    bool remove_edge(const NodeId& u, const NodeId& v);

    bool has_vertex(const NodeId& v) const;
    bool has_edge(const NodeId& u, const NodeId& v) const;

    const std::vector<Edge>& neighbors(const NodeId& u) const;
    std::vector<Edge>& neighbors(const NodeId& u);

    std::size_t vertex_count() const noexcept;
    std::size_t edge_count() const noexcept;

private:
    std::unordered_map<NodeId, std::vector<Edge>> adj_;
    std::size_t edge_count_ {0};
};

} // namespace transit
