
#include <iostream>

// Headers (interfaces only; implementations will be in your .cpp files)
#include "TransitNetwork.h"
#include "models/Stop.h"
#include "models/Route.h"
#include "models/Vehicle.h"
#include "models/Bus.h"
#include "models/Passenger.h"
#include "ds/Graph.h"
#include "ds/MinHeap.h"
#include "ds/DisjointSet.h"
#include "ds/Trie.h"
#include "ds/LRUCache.h"
#include "algo/Dijkstra.h"
#include "sim/Event.h"
#include "sim/EventQueue.h"
#include "sim/Simulation.h"

int main() {
    std::cout << "Transit Planner & Simulator — bootstrap\n";

    // NOTE:
    // This scaffold avoids calling any methods that require .cpp implementations.
    // It’s safe to compile BEFORE you implement the classes.
    // Once you write your .cpp files, you can uncomment sections below to exercise functionality.

    // ------------------------------------------------------------
    // TODO #1: After implementing models/Stop.cpp, Route.cpp, TransitNetwork.cpp:
    // ------------------------------------------------------------
    // transit::TransitNetwork net;
    // net.add_stop(1, "Central Station", 43.661, -70.255);
    // net.add_stop(2, "Park Ave", 43.664, -70.260);
    // net.add_stop(3, "Harbor Point", 43.650, -70.240);
    //
    // net.add_route(100, "R1",
    //               std::vector<transit::TransitNetwork::NodeId>{1, 2, 3},
    //               std::vector<int>{5, 7}, /*circular=*/false);
    //
    // auto autocomp = net.autocomplete("Pa", 5);
    // std::cout << "Autocomplete results for 'Pa': " << autocomp.size() << " stops\n";
    //
    // auto path = net.shortest_path(1, 3);
    // std::cout << "Shortest path from 1 to 3 has " << path.size() << " stops\n";

    // ------------------------------------------------------------
    // TODO #2: After implementing sim/*.cpp (Event, EventQueue, Simulation) and models/Bus.cpp:
    // ------------------------------------------------------------
    // transit::Simulation sim;
    // sim.set_network(&net);
    //
    // auto bus = std::make_shared<transit::Bus>(1, "Bus-1", 40);
    // // bus->assign_route(net.get_route(100)); // if you provide get_route()
    // sim.add_vehicle(bus);
    //
    // // Schedule initial events (arrival/departure/boarding) once implemented
    // // sim.run(120);

    // ------------------------------------------------------------
    // TODO #3: Test your data structures (header-only vs non-header):
    // Be careful: Most of the DS headers declare methods but don’t define them yet.
    // If you want to test DS here, provide definitions in headers or implement .cpp and link.
    // ------------------------------------------------------------
    // Example (once methods are defined):
    // transit::Graph<int, double> g;
    // g.add_vertex(1);
    // g.add_vertex(2);
    // g.add_edge(1, 2, 3.5);

    std::cout << "Scaffold compiled successfully. Implement .cpp files to start using features.\n";
    return 0;
}

