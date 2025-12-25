
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "Stop.h"

namespace transit {

// A route is an ordered sequence of stops with travel times between them.
class Route {
public:
    using Id = std::uint32_t;

    Route() = default;
    Route(Id id, std::string name, std::vector<Stop::Id> stops, std::vector<int> travel_minutes);

    Id id() const noexcept;
    const std::string& name() const noexcept;

    const std::vector<Stop::Id>& stops() const noexcept;
    const std::vector<int>& travel_minutes() const noexcept; // minutes between consecutive stops

    bool is_circular() const noexcept; // optional flag if last connects to first
    void set_circular(bool value) noexcept;

private:
    Id id_ {0};
    std::string name_;
    std::vector<Stop::Id> stops_;
    std::vector<int> travel_minutes_;
    bool circular_ {false};
};

} // namespace transit
