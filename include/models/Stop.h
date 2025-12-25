
#pragma once
#include <string>
#include <cstdint>
#include <vector>
#include <optional>

namespace transit {

// Represents a physical stop/station in the network.
class Stop {
public:
    using Id = std::uint32_t;

    Stop() = default;
    Stop(Id id, std::string name, double lat, double lon);

    Id id() const noexcept;
    const std::string& name() const noexcept;
    double latitude() const noexcept;
    double longitude() const noexcept;

    // Optional metadata hooks.
    void set_zone(std::optional<std::string> zone);
    const std::optional<std::string>& zone() const noexcept;

private:
    Id id_ {0};
    std::string name_;
    double lat_ {0.0};
    double lon_ {0.0};
    std::optional<std::string> zone_ {};
};

} // namespace transit
