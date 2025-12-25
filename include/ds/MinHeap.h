
#pragma once
#include <vector>
#include <functional>
#include <stdexcept>

namespace transit {

// Binary min-heap with customizable comparator.
template <typename T, typename Compare = std::less<T>>
class MinHeap {
public:
    MinHeap() = default;
    explicit MinHeap(Compare comp) : comp_(comp) {}

    bool empty() const noexcept { return data_.empty(); }
    std::size_t size() const noexcept { return data_.size(); }

    const T& top() const { if (data_.empty()) throw std::out_of_range("heap empty"); return data_.front(); }

    void push(const T& value);
    void push(T&& value);
    void pop();

private:
    std::vector<T> data_;
    Compare comp_ {};

    void sift_up(std::size_t idx);
    void sift_down(std::size_t idx);
};

} // namespace transit
