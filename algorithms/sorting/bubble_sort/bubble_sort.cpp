#include <utility>

template <class ForwardIt> void bubble_sort(ForwardIt first, ForwardIt last) {
  bool swapped = false;
  do {
    swapped = false;
    for (auto it = first; it < last; it++) {
      auto next = it;
      next++;
      if (next != last && *it > *next) {
        std::swap(*it, *next);
        swapped = true;
      }
    }
  } while (swapped);
}
