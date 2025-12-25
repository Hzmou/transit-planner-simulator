
#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <optional>
#include "ds/Graph.h"
#include "ds/DisjointSet.h"
#include "ds/Trie.h"
#include "ds/LRUCache.h"

namespace transit {

class Stop;  // fwd decl
class Route; // fwd decl

// Central orchestrator for stops, routes, and connectivity.
class TransitNetwork {
public:
    using NodeId = std::uint32_t;
    using Weight = double; // minutes

    TransitNetwork();

    // Stop management
    bool add_stop(NodeId id, const std::string& name, double lat, double lon);
    bool remove_stop(NodeId id);
    const Stop* get_stop(NodeId id) const;

    // Route management
    bool add_route(std::uint32_t route_id, const std::string& name,
                   const std::vector<NodeId>& stops,
                   const std::vector<int>& travel_minutes,
                   bool circular = false);
    bool remove_route(std::uint32_t route_id);

    // Graph access
    const Graph<NodeId, Weight>& graph() const noexcept;
    Graph<NodeId, Weight>& graph() noexcept;

    // Connectivity
    bool connected(NodeId a, NodeId b);

    // Autocomplete
    std::vector<NodeId> autocomplete(const std::string& prefix, std::size_t max_results = 10) const;

    // Pathfinding (uses Dijkstra; consider caching)
    std::vector<NodeId> shortest_path(NodeId source, NodeId target);

private:
    std::unordered_map<NodeId, std::unique_ptr<Stop>> stops_;
    std::unordered_map<std::uint32_t, std::unique_ptr<Route>> routes_;

    Graph<NodeId, Weight> graph_;
    Trie name_trie_;

    // Cache paths: key is "source|target"
    LRUCache<std::string, std::vector<NodeId>> path_cache_ {100};

    // For quick connectivity queries
    DisjointSet<NodeId> dsu_;

    std::string cache_key(NodeId s, NodeId t) const;
};

} // namespace transit
