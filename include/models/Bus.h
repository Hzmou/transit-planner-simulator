
#pragma once
#include "Vehicle.h"

namespace transit {

// Concrete vehicle type: Bus.
class Bus : public Vehicle {
public:
    using Vehicle::Vehicle; // inherit constructors
    ~Bus() override = default;

    void tick(int minutes_elapsed) override; // advance along route, board passengers, etc.
};

} // namespace transit

