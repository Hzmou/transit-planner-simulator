
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <optional>

namespace transit {

class Passenger {
public:
    using Id = std::uint64_t;

    Passenger(Id id, std::string name, std::uint32_t origin_stop, std::uint32_t destination_stop, int arrival_time_minutes);

    Id id() const noexcept;
    const std::string& name() const noexcept;

    std::uint32_t origin_stop() const noexcept;
    std::uint32_t destination_stop() const noexcept;

    int arrival_time_minutes() const noexcept;

    // Planned path as stop IDs (populate via planner)
    void set_planned_path(std::vector<std::uint32_t> path);
    const std::vector<std::uint32_t>& planned_path() const noexcept;

private:
    Id id_ {0};
    std::string name_;
    std::uint32_t origin_stop_ {0};
    std::uint32_t destination_stop_ {0};
    int arrival_time_minutes_ {0};
    std::vector<std::uint32_t> planned_path_;
};

} // namespace transit
