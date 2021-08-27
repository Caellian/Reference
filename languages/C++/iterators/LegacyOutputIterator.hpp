#include <iterator>

class LegacyOutputIterator
{
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = void;
    using difference_type = void;
    using pointer = void;
    using reference = void;

private:
    // Private iterator data goes here.

public:
    LegacyOutputIterator(const LegacyOutputIterator &other); // Iterator is CopyConstructible
    LegacyOutputIterator(LegacyOutputIterator &&other);      // Iterator is MoveConstructible
    ~LegacyOutputIterator() noexcept;                        // Iterator is Destructible

    // Iterator is Swapable - https://en.cppreference.com/w/cpp/named_req/Swappable

    [[nodiscard]] value_type operator*() const; // Iterator is dereferenceable

    LegacyOutputIterator &operator++();         // Pre-increment is defined
    LegacyOutputIterator operator++(int) const; // Post-increment is defined
};
