#include <iterator>

class LegacyForwardIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using difference_type = int;
    using pointer = int *;
    using reference = int &; // Must be mutable or a const

private:
    // Private iterator data goes here.

public:
    LegacyForwardIterator() = default;                         // Iterator is DefaultConstructible
    LegacyForwardIterator(const LegacyForwardIterator &other); // Iterator is CopyConstructible
    LegacyForwardIterator(LegacyForwardIterator &&other);      // Iterator is MoveConstructible
    ~LegacyForwardIterator() noexcept;                         // Iterator is Destructible

    // Iterator is Swapable - https://en.cppreference.com/w/cpp/named_req/Swappable

    [[nodiscard]] value_type operator*() const; // Iterator is dereferenceable

    LegacyForwardIterator &operator++();         // Pre-increment is defined (with multipass guarantee)
    LegacyForwardIterator operator++(int) const; // Post-increment is defined (with multipass guarantee)

    [[nodiscard]]  bool operator==(const LegacyForwardIterator &other) const; // Iterator is EqualityComparable
};
