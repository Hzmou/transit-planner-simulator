
#pragma once
#include <memory>
#include <vector>
#include "EventQueue.h"

namespace transit {

class TransitNetwork; // fwd decl
class Vehicle;        // fwd decl
class Passenger;      // fwd decl

// Discrete-event simulation engine.
class Simulation {
public:
    Simulation();

    void set_network(TransitNetwork* network);

    // Load vehicles and passengers to the simulation context.
    void add_vehicle(std::shared_ptr<Vehicle> vehicle);
    void add_passenger(std::shared_ptr<Passenger> passenger);

    // Run until the queue is empty or until max_minutes.
    void run(int max_minutes = 24 * 60);

    // Schedule an event at given time.
    void schedule(std::shared_ptr<Event> evt);

    int current_time() const noexcept;

private:
    TransitNetwork* network_ {nullptr};
    EventQueue queue_;
    std::vector<std::shared_ptr<Vehicle>> vehicles_;
    std::vector<std::shared_ptr<Passenger>> passengers_;
    int current_time_ {0};
};

} // namespace transit
