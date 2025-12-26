
#pragma once
#include <cstdint>
#include <string>
#include <memory>

namespace transit {

// Base event type for the simulation.
class Event {
public:
    using Time = int; // minutes since simulation start

    explicit Event(Time scheduled_time, std::string type);
    virtual ~Event() = default;

    Time scheduled_time() const noexcept;
    const std::string& type() const noexcept;

    // Execute the event. Returns next event to schedule (optional).
    virtual std::shared_ptr<Event> execute() = 0;

private:
    Time scheduled_time_ {0};
    std::string type_;
};

// Comparator for priority queue (min by time)
struct EventEarlier {
    bool operator()(const std::shared_ptr<Event>& a, const std::shared_ptr<Event>& b) const;
};

} // namespace transit
