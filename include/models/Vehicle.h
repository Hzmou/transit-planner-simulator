
#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <memory>

namespace transit {

class Route; // fwd decl
class Stop;  // fwd decl

// Abstract base class for all vehicles.
class Vehicle {
public:
    using Id = std::uint32_t;

    virtual ~Vehicle() = default;

    Vehicle(Id id, std::string label, std::uint32_t capacity);

    Id id() const noexcept;
    const std::string& label() const noexcept;
    std::uint32_t capacity() const noexcept;

    // Current position in the assigned route (index into stops sequence)
    std::size_t route_index() const noexcept;

    // Assignment APIs
    void assign_route(const Route* route);
    const Route* route() const noexcept;

    // Simulation hooks (define behavior in concrete classes)
    virtual void tick(int minutes_elapsed) = 0;

protected:
    Id id_ {0};
    std::string label_;
    std::uint32_t capacity_ {0};
    const Route* route_ {nullptr};
    std::size_t route_index_ {0};
};

} // namespace transit
