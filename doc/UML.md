```mermaid … ```


classDiagram
    %% Packages (grouping via namespaces)
    %% models
    class Stop {
        +Id: uint32_t
        -id_: Id
        -name_: string
        -lat_: double
        -lon_: double
        -zone_: optional<string>
        +Stop()
        +Stop(Id, string, double, double)
        +id() uint32_t
        +name() string
        +latitude() double
        +longitude() double
        +set_zone(optional<string>) void
        +zone() optional<string>
    }

    class Route {
        +Id: uint32_t
        -id_: Id
        -name_: string
        -stops_: vector<Stop::Id>
        -travel_minutes_: vector<int>
        -circular_: bool
        +Route()
        +Route(Id, string, vector<Stop::Id>, vector<int>)
        +id() uint32_t
        +name() string
        +stops() vector<Stop::Id>
        +travel_minutes() vector<int>
        +is_circular() bool
        +set_circular(bool) void
    }

    class Vehicle {
        <<abstract>>
        +Id: uint32_t
        -id_: Id
        -label_: string
        -capacity_: uint32_t
        -route_: Route*
        -route_index_: size_t
        +Vehicle(Id, string, uint32_t)
        +~Vehicle()
        +id() uint32_t
        +label() string
        +capacity() uint32_t
        +route_index() size_t
        +assign_route(const Route*) void
        +route() const Route*
        +tick(int) *pure*
    }

    class Bus {
        +~Bus()
        +tick(int) void
    }
    Vehicle <|-- Bus

    class Passenger {
        +Id: uint64_t
        -id_: Id
        -name_: string
        -origin_stop_: uint32_t
        -destination_stop_: uint32_t
        -arrival_time_minutes_: int
        -planned_path_: vector<uint32_t>
        +Passenger(Id, string, uint32_t, uint32_t, int)
        +id() uint64_t
        +name() string
        +origin_stop() uint32_t
        +destination_stop() uint32_t
        +arrival_time_minutes() int
        +set_planned_path(vector<uint32_t>) void
        +planned_path() vector<uint32_t>
    }

    %% ds
    class Graph~NodeId, Weight~ {
        +Edge: pair<NodeId, Weight>
        -adj_: unordered_map<NodeId, vector<Edge>>
        -edge_count_: size_t
        +Graph()
        +add_vertex(NodeId) bool
        +remove_vertex(NodeId) bool
        +add_edge(NodeId, NodeId, Weight) bool
        +remove_edge(NodeId, NodeId) bool
        +has_vertex(NodeId) const bool
        +has_edge(NodeId, NodeId) const bool
        +neighbors(NodeId) const vector<Edge>&
        +neighbors(NodeId) vector<Edge>&
        +vertex_count() size_t
        +edge_count() size_t
    }

    class MinHeap~T, Compare~ {
        -data_: vector<T>
        -comp_: Compare
        +MinHeap()
        +MinHeap(Compare)
        +empty() bool
        +size() size_t
        +top() const T&
        +push(const T&) void
        +push(T&&) void
        +pop() void
    }

    class DisjointSet~T~ {
        -nodes_: unordered_map<T, Node>
        +make_set(const T&) void
        +find(const T&) T
        +unite(const T&, const T&) void
        +same_set(const T&, const T&) bool
    }

    class Trie {
        -root_: unique_ptr<Node>
        +insert(string, uint32_t) void
        +contains(string) const bool
        +suggestions(string, size_t) const vector<uint32_t>
    }

    class LRUCache~Key, Value~ {
        -capacity_: size_t
        -list_: list<pair<Key, Value>>
        -map_: unordered_map<Key, list<pair<Key, Value>>::iterator>
        +LRUCache(size_t)
        +get(const Key&, Value&) bool
        +put(const Key&, const Value&) void
        +size() size_t
    }

    %% algo
    class Dijkstra~NodeId, Weight~ {
        <<utility>>
        +shortest_path(const Graph~NodeId,Weight~&, const NodeId&, const NodeId&) const Result
    }

    %% sim
    class Event {
        +Time: int
        -scheduled_time_: Time
        -type_: string
        +Event(Time, string)
        +~Event()
        +scheduled_time() Time
        +type() string
        +execute() shared_ptr<Event> *pure*
    }

    class EventEarlier {
        +operator()(shared_ptr<Event>, shared_ptr<Event>) const bool
    }

    class EventQueue {
        -heap_: MinHeap<shared_ptr<Event>, EventEarlier>
        +EventQueue()
        +empty() const bool
        +size() const size_t
        +push(shared_ptr<Event>) void
        +top() const shared_ptr<Event>
        +pop() void
    }

    class Simulation {
        -network_: TransitNetwork*
        -queue_: EventQueue
        -vehicles_: vector<shared_ptr<Vehicle>>
        -passengers_: vector<shared_ptr<Passenger>>
        -current_time_: int
        +Simulation()
        +set_network(TransitNetwork*) void
        +add_vehicle(shared_ptr<Vehicle>) void
        +add_passenger(shared_ptr<Passenger>) void
        +run(int) void
        +schedule(shared_ptr<Event>) void
        +current_time() const int
    }

    %% orchestration
    class TransitNetwork {
        +NodeId: uint32_t
        +Weight: double
        -stops_: unordered_map<NodeId, unique_ptr<Stop>>
        -routes_: unordered_map<uint32_t, unique_ptr<Route>>
        -graph_: Graph<NodeId, Weight>
        -name_trie_: Trie
        -path_cache_: LRUCache<string, vector<NodeId>>
        -dsu_: DisjointSet<NodeId>
        +TransitNetwork()
        +add_stop(NodeId, string, double, double) bool
        +remove_stop(NodeId) bool
        +get_stop(NodeId) const Stop*
        +add_route(uint32_t, string, vector<NodeId>, vector<int>, bool) bool
        +remove_route(uint32_t) bool
        +graph() Graph<NodeId, Weight>&
        +connected(NodeId, NodeId) bool
        +autocomplete(string, size_t) const vector<NodeId>
        +shortest_path(NodeId, NodeId) vector<NodeId>
    }

    %% Relationships
    TransitNetwork "1" o--> "many" Stop : owns
    TransitNetwork "1" o--> "many" Route : owns
    TransitNetwork "1" *--> Graph
    TransitNetwork "1" *--> Trie
    TransitNetwork "1" *--> LRUCache~string, vector<NodeId>~
    TransitNetwork "1" *--> DisjointSet~NodeId~
    Vehicle "1" --> "0..1" Route : assigned
    Simulation "1" --> "1" TransitNetwork : uses
    Simulation "1" *--> EventQueue
    Simulation "1" --> "many" Vehicle : manages
    Simulation "1" --> "many" Passenger : manages
    EventQueue "1" *--> MinHeap~shared_ptr<Event>, EventEarlier~
    Dijkstra --> Graph : reads
