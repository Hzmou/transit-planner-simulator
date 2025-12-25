
# Transit Planner & Simulator (C++)

An intermediate–large C++ project that challenges you to design and build a **transit route planner** and **discrete‑event simulator**. You'll implement core **data structures** (graph, heap, union‑find, trie, LRU cache) and algorithms (Dijkstra), then wire them up into a realistic transit network with vehicles, stops, routes, passengers, and an event queue.

> You will implement all `.cpp` files. This repository provides organized `.h` files (interfaces, types, and documentation) to guide you.

---

## High‑Level Goals

1. **Model a transit network** with stops, routes, and vehicles.
2. **Implement data structures from scratch**:
   - `Graph` (adjacency list)
   - `MinHeap` (binary heap)
   - `DisjointSet` (union–find)
   - `Trie` (prefix search for stop names)
   - `LRUCache` (path cache)
3. **Pathfinding**: Use **Dijkstra** to compute shortest travel time paths.
4. **Simulation**: Build a **discrete‑event simulator** that moves vehicles, boards passengers, and tracks events over simulated time via an `EventQueue`.
5. **Testing & Extensibility**: Unit test modules; add features like real‑time delays, rerouting, and capacity constraints.

---

## Suggested Milestones

### Milestone 1 — Core Data Structures
- Implement `ds/MinHeap<T>` with customizable comparator.
- Implement `ds/DisjointSet<T>` (path compression + union by rank/size).
- Implement `ds/Trie` (insert, search, prefix suggestions).
- Implement `ds/LRUCache<Key, Value>` using a doubly linked list + hash map.

### Milestone 2 — Graph & Algorithms
- Implement `ds/Graph<NodeId, Weight>` (directed weighted graph):
  - `add_vertex`, `add_edge`, `remove_edge`, `neighbors`, etc.
- Implement `algo/Dijkstra` returning shortest path + distance.
- Integrate `DisjointSet` for quick connectivity checks.

### Milestone 3 — Domain Models & Network
- Implement `models/Stop`, `models/Route`, `models/Vehicle` (abstract), `models/Bus`, `models/Passenger`.
- Implement `TransitNetwork` to manage stops, routes, and backing graph.
- Implement `Trie` inside `TransitNetwork` for name autocomplete.

### Milestone 4 — Simulation Engine
- Implement `sim/Event` (base) and concrete event types (arrival, departure, boarding).
- Implement `sim/EventQueue` built on `MinHeap`.
- Implement `sim/Simulation` that processes events, advances time, updates vehicles.

### Milestone 5 — Path Cache & Rerouting
- Add `LRUCache` to memoize common source–target shortest paths.
- Support real‑time delays; trigger rerouting when routes are blocked.

---

## Input Data (You design)
You may load stops and routes from simple CSVs:
- `stops.csv`: `stop_id,name,lat,lon`
- `routes.csv`: `route_id,stop_id_sequence (semicolon‑separated),travel_time_minutes (semicolon‑separated)`

Alternatively, construct the network programmatically for testing.

---

## Build & Run

Use **CMake** (or a simple g++ command). Example (adjust paths):

```bash
g++ -std=c++20 -Iinclude \
    src/*.cpp src/models/*.cpp src/ds/*.cpp src/algo/*.cpp src/sim/*.cpp \
    -o transit_sim





# From the project root
mkdir -p build
cd build
cmake ..
cmake --build . --config Release

# Run
./bin/transit_sim
