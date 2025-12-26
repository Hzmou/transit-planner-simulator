
#pragma once
#include <vector>
#include <optional>
#include <limits>
#include "../ds/Graph.h"

namespace transit {

// Dijkstra shortest path on Graph<NodeId, Weight>.
template <typename NodeId = int, typename Weight = double>
class Dijkstra {
public:
    struct Result {
        Weight distance {std::numeric_limits<Weight>::infinity()};
        std::vector<NodeId> path; // inclusive: source ... target
        bool reachable {false};
    };

    Result shortest_path(const Graph<NodeId, Weight>& g, const NodeId& source, const NodeId& target) const;
};

} // namespace transit
