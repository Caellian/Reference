#include <iterator>

class LegacyInputIterator
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
    LegacyInputIterator(const LegacyInputIterator &other); // Iterator is CopyConstructible
    LegacyInputIterator(LegacyInputIterator &&other);      // Iterator is MoveConstructible
    ~LegacyInputIterator() noexcept;                       // Iterator is Destructible

    // Iterator is Swapable - https://en.cppreference.com/w/cpp/named_req/Swappable

    [[nodiscard]] value_type operator*() const; // Iterator is dereferenceable

    LegacyInputIterator &operator++(); // Pre-increment is defined

    [[nodiscard]] bool operator==(const LegacyInputIterator &other) const; // Iterator is EqualityComparable
};
