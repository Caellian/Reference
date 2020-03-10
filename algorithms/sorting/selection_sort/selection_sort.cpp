#include <algorithm>

template <class ForwardIt>
void selection_sort(ForwardIt first, ForwardIt last) {
  for (auto it = first; it != last; it++) {
    auto min = std::min_element(it, last);
    std::swap(*min, *it);
  }
}
