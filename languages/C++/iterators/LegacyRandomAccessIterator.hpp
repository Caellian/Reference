#include <iterator>

class LegacyRandomAccessIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = int;
    using difference_type = int;
    using pointer = int *;
    using reference = int &; // Must be mutable or a const

private:
    // Private iterator data goes here.

public:
    LegacyRandomAccessIterator() = default;                              // Iterator is DefaultConstructible
    LegacyRandomAccessIterator(const LegacyRandomAccessIterator &other); // Iterator is CopyConstructible
    LegacyRandomAccessIterator(LegacyRandomAccessIterator &&other);      // Iterator is MoveConstructible
    ~LegacyRandomAccessIterator() noexcept;                              // Iterator is Destructible

    // Iterator is Swapable - https://en.cppreference.com/w/cpp/named_req/Swappable

    [[nodiscard]] value_type operator*() const; // Iterator is dereferenceable

    LegacyRandomAccessIterator &operator++();         // Pre-increment is defined (with multipass guarantee)
    LegacyRandomAccessIterator operator++(int) const; // Post-increment is defined (with multipass guarantee)
    LegacyRandomAccessIterator &operator--();         // Pre-decrement is defined (with multipass guarantee)
    LegacyRandomAccessIterator operator--(int) const; // Post-decrement is defined (with multipass guarantee)

    [[nodiscard]] LegacyRandomAccessIterator operator+(const difference_type &other) const; // difference_type can be subtracted from the iterator
    [[nodiscard]] LegacyRandomAccessIterator operator-(const difference_type &other) const; // difference_type can be subtracted from the iterator

    LegacyRandomAccessIterator &operator+=(const difference_type &other); // Iterator can be addition assigned
    LegacyRandomAccessIterator &operator-=(const difference_type &other); // Iterator can be subtraction assigned

    [[nodiscard]] difference_type operator-(const LegacyRandomAccessIterator &other) const; // difference_type can be acquired from two iterators

    [[nodiscard]] LegacyRandomAccessIterator &operator[](const difference_type &n) const; // Subscript is implemented

    [[nodiscard]] bool operator==(const LegacyRandomAccessIterator &other) const; // Iterator is EqualityComparable

    [[nodiscard]] bool operator<(const LegacyRandomAccessIterator &other) const; // Iterator is LessThanComparable (total ordering is defined)
    [[nodiscard]] bool operator>(const LegacyRandomAccessIterator &other) const; // Iterator is more than comparable (total ordering is defined)

    [[nodiscard]] bool operator<=(const LegacyRandomAccessIterator &other) const; // Iterator is LessThanComparable (total ordering is defined)
    [[nodiscard]] bool operator>=(const LegacyRandomAccessIterator &other) const; // Iterator is more than comparable (total ordering is defined)
};

[[nodiscard]] LegacyRandomAccessIterator operator+(const std::iterator_traits<LegacyRandomAccessIterator>::difference_type &a, const LegacyRandomAccessIterator &b) {
    return b + a;
}
