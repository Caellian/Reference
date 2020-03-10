// This implementation can work with bidirectional iterator but random access iterator is
// required for optimal performance.

template <class BidirectionalIt>
void shellsort(BidirectionalIt first, BidirectionalIt last) {
  for (size_t gap = std::distance(first, last) / 2; gap > 0; gap /= 2) {
    for (auto it = std::next(first, gap); it != last; it++) {
      typename std::iterator_traits<BidirectionalIt>::value_type tmp = *it;
      auto i = it;
      while (std::distance(first, i) >= gap && *std::prev(i, gap) > tmp) {
        *i = *std::prev(i, gap);
        i = std::prev(i, gap);
      }
      *i = tmp;
    }
  }
}
