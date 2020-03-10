#include <utility>
#include <iterator>

template <class RandomAccessIt>
void heapify(RandomAccessIt first, RandomAccessIt last, RandomAccessIt from) {
  auto largest = from;

  if (2 * std::distance(first, from) + 1 < std::distance(first, last)) {
    auto l = first + (2 * std::distance(first, from) + 1);

    if (*l > *largest) {
      largest = l;
    }
  }

  if (2 * std::distance(first, from) + 2 < last - first) {
    auto r = first + (2 * std::distance(first, from) + 2);

    if (*r > *largest) {
      largest = r;
    }
  }

  if (largest != from) {
    std::swap(*from, *largest);
    heapify(first, last, largest);
  }
}

template <class RandomAccessIt>
void heapsort(RandomAccessIt first, RandomAccessIt last) {
  for (auto it = first + (std::distance(first, last) / 2 - 1); it >= first; it--) {
    heapify(first, last, it);
  }

  for (auto it = last - 1; it >= first; it--) {
    std::swap(*first, *it);
    heapify(first, it, first);
  }
}
