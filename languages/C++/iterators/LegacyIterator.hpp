#include <iterator>

class LegacyIterator
{
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = int;
    using difference_type = int;
    using pointer = int *;
    using reference = int &;

private:
    // Private iterator data goes here.

public:
    LegacyIterator(const LegacyIterator &other); // Iterator is CopyConstructible
    LegacyIterator(LegacyIterator &&other);      // Iterator is MoveConstructible
    ~LegacyIterator() noexcept;                  // Iterator is Destructible

    // Iterator is Swapable - https://en.cppreference.com/w/cpp/named_req/Swappable

    [[nodiscard]] value_type operator*() const; // Iterator is dereferenceable

    LegacyIterator &operator++(); // Pre-increment is defined
};
