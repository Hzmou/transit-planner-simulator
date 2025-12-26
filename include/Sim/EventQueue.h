
#pragma once
#include <memory>
#include "../ds/MinHeap.h"
#include "Event.h"

namespace transit {

// Wrapper around MinHeap for events.
class EventQueue {
public:
    EventQueue();

    bool empty() const noexcept;
    std::size_t size() const noexcept;

    void push(std::shared_ptr<Event> evt);
    std::shared_ptr<Event> top() const; // throws if empty
    void pop();

private:
    MinHeap<std::shared_ptr<Event>, EventEarlier> heap_;
};

} // namespace transit
