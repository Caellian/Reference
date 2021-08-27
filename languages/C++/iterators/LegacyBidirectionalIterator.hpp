#include <iterator>

class LegacyBidirectionalIterator
{
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = int;
    using difference_type = int;
    using pointer = int *;
    using reference = int &; // Must be mutable or a const

private:
    // Private iterator data goes here.

public:
    LegacyBidirectionalIterator() = default;                               // Iterator is DefaultConstructible
    LegacyBidirectionalIterator(const LegacyBidirectionalIterator &other); // Iterator is CopyConstructible
    LegacyBidirectionalIterator(LegacyBidirectionalIterator &&other);      // Iterator is MoveConstructible
    ~LegacyBidirectionalIterator() noexcept;                               // Iterator is Destructible

    // Iterator is Swapable - https://en.cppreference.com/w/cpp/named_req/Swappable

    [[nodiscard]] value_type operator*() const; // Iterator is dereferenceable

    LegacyBidirectionalIterator &operator++();         // Pre-increment is defined (with multipass guarantee)
    LegacyBidirectionalIterator operator++(int) const; // Post-increment is defined (with multipass guarantee)
    LegacyBidirectionalIterator &operator--();         // Pre-decrement is defined (with multipass guarantee)
    LegacyBidirectionalIterator operator--(int) const; // Post-decrement is defined (with multipass guarantee)

    [[nodiscard]] bool operator==(const LegacyBidirectionalIterator &other) const; // Iterator is EqualityComparable
};
