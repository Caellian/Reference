#include <algorithm>

template <class ForwardIt>
void insertion_sort(ForwardIt first, ForwardIt last) {
  for (auto it = first; it != last; ++it)
    std::rotate(std::upper_bound(first, it, *it), it, std::next(it));
}
